//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<ForwardIterator Iter, class T, CopyConstructible Compare>
//   constexpr pair<Iter, Iter>   // constexpr after c++17
//   equal_range(Iter first, Iter last, const T& value, Compare comp);

#include <algorithm>
#include <functional>
#include <vector>
#include <cassert>
#include <cstddef>

#include "test_macros.h"
#include "test_iterators.h"

#if TEST_STD_VER > 17
TEST_CONSTEXPR bool lt(int a, int b) { return a < b; }

TEST_CONSTEXPR bool test_constexpr() {
    int ia[] = {1, 3, 3, 6, 7};

    return (std::equal_range(std::begin(ia), std::end(ia), 1, lt) == std::pair<int *, int *>(ia+0, ia+1))
        && (std::equal_range(std::begin(ia), std::end(ia), 3, lt) == std::pair<int *, int *>(ia+1, ia+3))
        && (std::equal_range(std::begin(ia), std::end(ia), 9, lt) == std::pair<int *, int *>(std::end(ia), std::end(ia)))
        ;
    }
#endif

template <class Iter, class T>
void
test(Iter first, Iter last, const T& value)
{
    std::pair<Iter, Iter> i = std::equal_range(first, last, value, std::greater<int>());
    for (Iter j = first; j != i.first; ++j)
        assert(std::greater<int>()(*j, value));
    for (Iter j = i.first; j != last; ++j)
        assert(!std::greater<int>()(*j, value));
    for (Iter j = first; j != i.second; ++j)
        assert(!std::greater<int>()(value, *j));
    for (Iter j = i.second; j != last; ++j)
        assert(std::greater<int>()(value, *j));
}

template <class Iter>
void
test()
{
    const unsigned N = 1000;
    const int M = 10;
    std::vector<int> v(N);
    int x = 0;
    for (std::size_t i = 0; i < v.size(); ++i)
    {
        v[i] = x;
        if (++x == M)
            x = 0;
    }
    std::sort(v.begin(), v.end(), std::greater<int>());
    for (x = 0; x <= M; ++x)
        test(Iter(v.data()), Iter(v.data()+v.size()), x);
}

extern "C" int main(int, char**)
{
    int d[] = {3, 2, 1, 0};
    for (int* e = d; e <= d+4; ++e)
        for (int x = -1; x <= 4; ++x)
            test(d, e, x);

    test<forward_iterator<const int*> >();
    test<bidirectional_iterator<const int*> >();
    test<random_access_iterator<const int*> >();
    test<const int*>();

#if TEST_STD_VER > 17
    static_assert(test_constexpr());
#endif

  return 0;
}
