//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <iterator>

// __unconstrained_reverse_iterator

// reference operator*() const; // constexpr in C++17

// Be sure to respect LWG 198:
//    http://www.open-std.org/jtc1/sc22/wg21/docs/lwg-defects.html#198
// LWG 198 was superseded by LWG 2360
//    http://www.open-std.org/jtc1/sc22/wg21/docs/lwg-defects.html#2360

#include <iterator>
#include <cassert>

#include "test_macros.h"

class A
{
    int data_;
public:
    A() : data_(1) {}
    ~A() {data_ = -1;}

    friend bool operator==(const A& x, const A& y)
        {return x.data_ == y.data_;}
};

template <class It>
void
test(It i, typename std::iterator_traits<It>::value_type x)
{
    std::__unconstrained_reverse_iterator<It> r(i);
    assert(*r == x);
}

extern "C" int main(int, char**)
{
    A a;
    test(&a+1, A());

#if TEST_STD_VER > 14
    {
        constexpr const char *p = "123456789";
        typedef std::__unconstrained_reverse_iterator<const char *> RI;
        constexpr RI it1 = RI(p+1);
        constexpr RI it2 = RI(p+2);
        static_assert(*it1 == p[0], "");
        static_assert(*it2 == p[1], "");
    }
#endif

  return 0;
}
