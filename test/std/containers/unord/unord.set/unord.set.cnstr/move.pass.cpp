//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03

// <unordered_set>

// template <class Value, class Hash = hash<Value>, class Pred = equal_to<Value>,
//           class Alloc = allocator<Value>>
// class unordered_set

// unordered_set(unordered_set&& u);

#include <unordered_set>
#include <cassert>
#include <cfloat>
#include <cmath>
#include <cstddef>

#include "test_macros.h"
#include "../../../test_compare.h"
#include "../../../test_hash.h"
#include "test_allocator.h"
#include "min_allocator.h"

extern "C" int main(int, char**)
{
    {
        typedef std::unordered_set<int,
                                   test_hash<int>,
                                   test_equal_to<int>,
                                   test_allocator<int>
                                   > C;
        C c0(7,
            test_hash<int>(8),
            test_equal_to<int>(9),
            test_allocator<int>(10)
           );
        C c = std::move(c0);
        LIBCPP_ASSERT(c.bucket_count() == 7);
        assert(c.size() == 0);
        assert(c.hash_function() == test_hash<int>(8));
        assert(c.key_eq() == test_equal_to<int>(9));
        assert(c.get_allocator() == test_allocator<int>(10));
        assert(c.empty());
        assert(static_cast<std::size_t>(std::distance(c.begin(), c.end())) == c.size());
        assert(static_cast<std::size_t>(std::distance(c.cbegin(), c.cend())) == c.size());
        assert(c.load_factor() == 0);
        assert(c.max_load_factor() == 1);

        assert(c0.empty());
    }
    {
        typedef std::unordered_set<int,
                                   test_hash<int>,
                                   test_equal_to<int>,
                                   test_allocator<int>
                                   > C;
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
        C c0(a, a + sizeof(a)/sizeof(a[0]),
            7,
            test_hash<int>(8),
            test_equal_to<int>(9),
            test_allocator<int>(10)
           );
        C::iterator it0 = c0.begin();
        C c = std::move(c0);
        assert(it0 == c.begin()); // Iterators remain valid
        LIBCPP_ASSERT(c.bucket_count() == 7);
        assert(c.size() == 4);
        assert(c.count(1) == 1);
        assert(c.count(2) == 1);
        assert(c.count(3) == 1);
        assert(c.count(4) == 1);
        assert(c.hash_function() == test_hash<int>(8));
        assert(c.key_eq() == test_equal_to<int>(9));
        assert(c.get_allocator() == test_allocator<int>(10));
        assert(!c.empty());
        assert(static_cast<std::size_t>(std::distance(c.begin(), c.end())) == c.size());
        assert(static_cast<std::size_t>(std::distance(c.cbegin(), c.cend())) == c.size());
        assert(std::fabs(c.load_factor() - (float)c.size()/c.bucket_count()) < FLT_EPSILON);
        assert(c.max_load_factor() == 1);

        assert(c0.empty());
    }
    {
        typedef std::unordered_set<int,
                                   test_hash<int>,
                                   test_equal_to<int>,
                                   min_allocator<int>
                                   > C;
        C c0(7,
            test_hash<int>(8),
            test_equal_to<int>(9),
            min_allocator<int>()
           );
        C c = std::move(c0);
        LIBCPP_ASSERT(c.bucket_count() == 7);
        assert(c.size() == 0);
        assert(c.hash_function() == test_hash<int>(8));
        assert(c.key_eq() == test_equal_to<int>(9));
        assert(c.get_allocator() == min_allocator<int>());
        assert(c.empty());
        assert(static_cast<std::size_t>(std::distance(c.begin(), c.end())) == c.size());
        assert(static_cast<std::size_t>(std::distance(c.cbegin(), c.cend())) == c.size());
        assert(c.load_factor() == 0);
        assert(c.max_load_factor() == 1);

        assert(c0.empty());
    }
    {
        typedef std::unordered_set<int,
                                   test_hash<int>,
                                   test_equal_to<int>,
                                   min_allocator<int>
                                   > C;
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
        C c0(a, a + sizeof(a)/sizeof(a[0]),
            7,
            test_hash<int>(8),
            test_equal_to<int>(9),
            min_allocator<int>()
           );
        C::iterator it0 = c0.begin();
        C c = std::move(c0);
        assert(it0 == c.begin()); // Iterators remain valid
        LIBCPP_ASSERT(c.bucket_count() == 7);
        assert(c.size() == 4);
        assert(c.count(1) == 1);
        assert(c.count(2) == 1);
        assert(c.count(3) == 1);
        assert(c.count(4) == 1);
        assert(c.hash_function() == test_hash<int>(8));
        assert(c.key_eq() == test_equal_to<int>(9));
        assert(c.get_allocator() == min_allocator<int>());
        assert(!c.empty());
        assert(static_cast<std::size_t>(std::distance(c.begin(), c.end())) == c.size());
        assert(static_cast<std::size_t>(std::distance(c.cbegin(), c.cend())) == c.size());
        assert(std::fabs(c.load_factor() - (float)c.size()/c.bucket_count()) < FLT_EPSILON);
        assert(c.max_load_factor() == 1);

        assert(c0.empty());
    }

    return 0;
}
