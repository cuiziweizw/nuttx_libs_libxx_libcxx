//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03

// <stack>

// template <class Alloc>
//   stack(stack&& q, const Alloc& a);

#include <stack>
#include <cassert>

#include "test_macros.h"
#include "test_allocator.h"
#include "MoveOnly.h"


template <class C>
C
make(int n)
{
    C c;
    for (int i = 0; i < n; ++i)
        c.push_back(MoveOnly(i));
    return c;
}

typedef std::deque<MoveOnly, test_allocator<MoveOnly> > C;

template <class T>
struct test
    : public std::stack<T, C>
{
    typedef std::stack<T, C> base;
    typedef test_allocator<MoveOnly>      allocator_type;
    typedef typename base::container_type container_type;

    explicit test(const allocator_type& a) : base(a) {}
    test(const container_type& cont, const allocator_type& a) : base(cont, a) {}
    test(container_type&& cont, const allocator_type& a) : base(std::move(cont), a) {}
    test(test&& q, const allocator_type& a) : base(std::move(q), a) {}
    allocator_type get_allocator() {return this->c.get_allocator();}
};


extern "C" int main(int, char**)
{
    test<MoveOnly> q(make<C>(5), test_allocator<MoveOnly>(4));
    test<MoveOnly> q2(std::move(q), test_allocator<MoveOnly>(5));
    assert(q2.get_allocator() == test_allocator<MoveOnly>(5));
    assert(q2.size() == 5);

  return 0;
}
