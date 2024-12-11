//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03, c++11, c++14, c++17

// constexpr counted_iterator& operator-=(iter_difference_t<I> n)
//   requires random_access_iterator<I>;

#include <iterator>

#include "test_macros.h"
#include "test_iterators.h"

template<class Iter>
concept MinusEqEnabled = requires(Iter& iter) {
  iter -= 1;
};

constexpr bool test() {
  int buffer[8] = {1, 2, 3, 4, 5, 6, 7, 8};

  {
    using Counted = std::counted_iterator<random_access_iterator<int*>>;
    Counted iter(random_access_iterator<int*>{buffer + 2}, 6);
    assert((iter -= 2) == Counted(random_access_iterator<int*>{buffer}, 8));
    assert((iter -= 0) == Counted(random_access_iterator<int*>{buffer}, 8));
    assert(iter.count() == 8);

    ASSERT_SAME_TYPE(decltype(iter -= 2), Counted&);
  }
  {
    using Counted = std::counted_iterator<contiguous_iterator<int*>>;
    Counted iter(contiguous_iterator<int*>{buffer + 2}, 6);
    assert((iter -= 2) == Counted(contiguous_iterator<int*>{buffer}, 8));
    assert((iter -= 0) == Counted(contiguous_iterator<int*>{buffer}, 8));
    assert(iter.count() == 8);

    ASSERT_SAME_TYPE(decltype(iter -= 2), Counted&);
  }
  {
    static_assert( MinusEqEnabled<      std::counted_iterator<random_access_iterator<int*>>>);
    static_assert(!MinusEqEnabled<const std::counted_iterator<random_access_iterator<int*>>>);
  }


  return true;
}

extern "C" int main(int, char**) {
  test();
  static_assert(test());

  return 0;
}
