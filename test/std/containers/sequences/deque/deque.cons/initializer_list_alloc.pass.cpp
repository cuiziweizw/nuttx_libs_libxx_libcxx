//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03

// <deque>

// deque(initializer_list<value_type> il, const Allocator& a = allocator_type());

#include "asan_testing.h"
#include <deque>
#include <cassert>

#include "test_macros.h"
#include "test_allocator.h"
#include "min_allocator.h"

extern "C" int main(int, char**)
{
    {
    std::deque<int, test_allocator<int>> d({3, 4, 5, 6}, test_allocator<int>(3));
    assert(d.get_allocator() == test_allocator<int>(3));
    assert(d.size() == 4);
    assert(d[0] == 3);
    assert(d[1] == 4);
    assert(d[2] == 5);
    assert(d[3] == 6);
    LIBCPP_ASSERT(is_double_ended_contiguous_container_asan_correct(d));
    }
    {
    std::deque<int, min_allocator<int>> d({3, 4, 5, 6}, min_allocator<int>());
    assert(d.get_allocator() == min_allocator<int>());
    assert(d.size() == 4);
    assert(d[0] == 3);
    assert(d[1] == 4);
    assert(d[2] == 5);
    assert(d[3] == 6);
    LIBCPP_ASSERT(is_double_ended_contiguous_container_asan_correct(d));
    }

  return 0;
}
