//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// REQUIRES: c++03 || c++11 || c++14

// ADDITIONAL_COMPILE_FLAGS: -D_LIBCPP_DISABLE_DEPRECATION_WARNINGS

// <ios>
//
// class ios_base
// {
// public:
//     typedef T1 io_state;
// };

//  These members were removed for C++17

#include "test_macros.h"
#include <strstream>
#include <cassert>

extern "C" int main(int, char**)
{
    std::strstream::io_state b = std::strstream::eofbit;
    assert(b == std::ios::eofbit);

  return 0;
}
