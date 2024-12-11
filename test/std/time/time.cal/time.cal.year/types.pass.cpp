//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
// UNSUPPORTED: c++03, c++11, c++14, c++17

// <chrono>
// class year;

#include <chrono>
#include <type_traits>
#include <cassert>

#include "test_macros.h"

extern "C" int main(int, char**)
{
    using year = std::chrono::year;

    static_assert(std::is_trivially_copyable_v<year>, "");
    static_assert(std::is_standard_layout_v<year>, "");

  return 0;
}
