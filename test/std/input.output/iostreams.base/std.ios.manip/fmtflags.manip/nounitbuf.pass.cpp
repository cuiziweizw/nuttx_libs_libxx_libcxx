//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <ios>

// class ios_base

// ios_base& nounitbuf(ios_base& str);

#include <ios>
#include <streambuf>
#include <cassert>

#include "test_macros.h"

struct testbuf : public std::streambuf {};

extern "C" int main(int, char**)
{
    testbuf sb;
    std::ios ios(&sb);
    std::unitbuf(ios);
    std::ios_base& r = std::nounitbuf(ios);
    assert(&r == &ios);
    assert(!(ios.flags() & std::ios::unitbuf));

  return 0;
}
