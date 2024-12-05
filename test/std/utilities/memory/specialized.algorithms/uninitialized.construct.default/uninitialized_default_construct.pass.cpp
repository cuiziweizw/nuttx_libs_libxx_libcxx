//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03, c++11, c++14

// <memory>

// template <class ForwardIt>
// void uninitialized_default_construct(ForwardIt, ForwardIt);

#include <memory>
#include <cstdlib>
#include <cassert>

#include "test_macros.h"
#include "test_iterators.h"

struct Counted {
  static int count;
  static int constructed;
  explicit Counted() { ++count; ++constructed; }
  Counted(Counted const&) { assert(false); }
  ~Counted() { --count; }
  friend void operator&(Counted) = delete;
};


struct ThrowsCounted {
  static int count;
  static int constructed;
  static int throw_after;
  explicit ThrowsCounted() {
      ++constructed;
      if (throw_after > 0 && --throw_after == 0) {
          TEST_THROW(1);
      }
      ++count;
  }
  ThrowsCounted(ThrowsCounted const&) { assert(false); }
  ~ThrowsCounted() { assert(count > 0); --count; }
  friend void operator&(ThrowsCounted) = delete;
};

static void test_ctor_throws()
{
#ifndef TEST_HAS_NO_EXCEPTIONS
    using It = forward_iterator<ThrowsCounted*>;
    const int N = 5;
    alignas(ThrowsCounted) char pool[sizeof(ThrowsCounted)*N] = {};
    ThrowsCounted* p = (ThrowsCounted*)pool;
    try {
        ThrowsCounted::throw_after = 4;
        std::uninitialized_default_construct(It(p), It(p+N));
        assert(false);
    } catch (...) {}
    assert(ThrowsCounted::count == 0);
    assert(ThrowsCounted::constructed == 4); // Fourth construction throws
#endif
}

static void test_counted()
{
    using It = forward_iterator<Counted*>;
    const int N = 5;
    alignas(Counted) char pool[sizeof(Counted)*N] = {};
    Counted* p = (Counted*)pool;
    std::uninitialized_default_construct(It(p), It(p+1));
    assert(Counted::count == 1);
    assert(Counted::constructed == 1);
    std::uninitialized_default_construct(It(p+1), It(p+N));
    assert(Counted::count == 5);
    assert(Counted::constructed == 5);
    std::destroy(p, p+N);
    assert(Counted::count == 0);
}

extern "C" int main(int, char**)
{
    test_counted();
    test_ctor_throws();

  return 0;
}
