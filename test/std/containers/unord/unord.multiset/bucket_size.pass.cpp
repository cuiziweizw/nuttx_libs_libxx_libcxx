//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <unordered_set>

// template <class Value, class Hash = hash<Value>, class Pred = equal_to<Value>,
//           class Alloc = allocator<Value>>
// class unordered_multiset

// size_type bucket_size(size_type n) const

#include <unordered_set>
#include <cassert>

#include "test_macros.h"
#include "min_allocator.h"

extern "C" int main(int, char**)
{
    {
        typedef std::unordered_multiset<int> C;
        typedef int P;
        P a[] =
        {
            P(1),
            P(2),
            P(3),
            P(4),
            P(1),
            P(2)
        };
        const C c(std::begin(a), std::end(a));
        assert(c.bucket_count() >= 7);
        LIBCPP_ASSERT(c.bucket_size(0) == 0);
        LIBCPP_ASSERT(c.bucket_size(1) == 2);
        LIBCPP_ASSERT(c.bucket_size(2) == 2);
        LIBCPP_ASSERT(c.bucket_size(3) == 1);
        LIBCPP_ASSERT(c.bucket_size(4) == 1);
        LIBCPP_ASSERT(c.bucket_size(5) == 0);
        LIBCPP_ASSERT(c.bucket_size(6) == 0);
    }
#if TEST_STD_VER >= 11
    {
        typedef std::unordered_multiset<int, std::hash<int>,
                                      std::equal_to<int>, min_allocator<int>> C;
        typedef int P;
        P a[] =
        {
            P(1),
            P(2),
            P(3),
            P(4),
            P(1),
            P(2)
        };
        const C c(std::begin(a), std::end(a));
        assert(c.bucket_count() >= 7);
        LIBCPP_ASSERT(c.bucket_size(0) == 0);
        LIBCPP_ASSERT(c.bucket_size(1) == 2);
        LIBCPP_ASSERT(c.bucket_size(2) == 2);
        LIBCPP_ASSERT(c.bucket_size(3) == 1);
        LIBCPP_ASSERT(c.bucket_size(4) == 1);
        LIBCPP_ASSERT(c.bucket_size(5) == 0);
        LIBCPP_ASSERT(c.bucket_size(6) == 0);
    }
#endif
    return 0;
}
