//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <chrono>

// typedef duration<signed integral type of at least 35 bits > seconds;

#include <chrono>
#include <limits>
#include <ratio>
#include <type_traits>

#include "test_macros.h"

extern "C" int main(int, char**)
{
    typedef std::chrono::seconds D;
    typedef D::rep Rep;
    typedef D::period Period;
    static_assert(std::is_signed<Rep>::value, "");
    static_assert(std::is_integral<Rep>::value, "");
    static_assert(std::numeric_limits<Rep>::digits >= 34, "");
    static_assert((std::is_same<Period, std::ratio<1> >::value), "");

  return 0;
}
