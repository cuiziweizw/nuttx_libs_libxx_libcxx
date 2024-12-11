//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03

// <list>

// template <class... Args> reference emplace_front(Args&&... args);
// return type is 'reference' in C++17; 'void' before

#include <list>
#include <cassert>

#include "test_macros.h"
#include "min_allocator.h"

class A
{
    int i_;
    double d_;

    A(const A&);
    A& operator=(const A&);
public:
    A(int i, double d)
        : i_(i), d_(d) {}

    int geti() const {return i_;}
    double getd() const {return d_;}
};

extern "C" int main(int, char**)
{
    {
    std::list<A> c;
#if TEST_STD_VER > 14
    A& r1 = c.emplace_front(2, 3.5);
    assert(c.size() == 1);
    assert(&r1 == &c.front());
    assert(c.front().geti() == 2);
    assert(c.front().getd() == 3.5);
    A& r2 = c.emplace_front(3, 4.5);
    assert(c.size() == 2);
    assert(&r2 == &c.front());
#else
    c.emplace_front(2, 3.5);
    assert(c.size() == 1);
    assert(c.front().geti() == 2);
    assert(c.front().getd() == 3.5);
    c.emplace_front(3, 4.5);
    assert(c.size() == 2);
#endif
    assert(c.front().geti() == 3);
    assert(c.front().getd() == 4.5);
    assert(c.back().geti() == 2);
    assert(c.back().getd() == 3.5);
    }

    {
    std::list<A, min_allocator<A>> c;
#if TEST_STD_VER > 14
    A& r1 = c.emplace_front(2, 3.5);
    assert(c.size() == 1);
    assert(&r1 == &c.front());
    assert(c.front().geti() == 2);
    assert(c.front().getd() == 3.5);
    A& r2 = c.emplace_front(3, 4.5);
    assert(c.size() == 2);
    assert(&r2 == &c.front());
#else
    c.emplace_front(2, 3.5);
    assert(c.size() == 1);
    assert(c.front().geti() == 2);
    assert(c.front().getd() == 3.5);
    c.emplace_front(3, 4.5);
    assert(c.size() == 2);
#endif
    assert(c.front().geti() == 3);
    assert(c.front().getd() == 4.5);
    assert(c.back().geti() == 2);
    assert(c.back().getd() == 3.5);
    }

  return 0;
}
