//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <streambuf>

// template <class charT, class traits = char_traits<charT> >
// class basic_streambuf;

// int pubsync();

#include <streambuf>
#include <cassert>

#include "test_macros.h"

template <class CharT>
struct test
    : public std::basic_streambuf<CharT>
{
    test() {}
};

extern "C" int main(int, char**)
{
    {
        test<char> t;
        assert(t.pubsync() == 0);
    }

  return 0;
}
