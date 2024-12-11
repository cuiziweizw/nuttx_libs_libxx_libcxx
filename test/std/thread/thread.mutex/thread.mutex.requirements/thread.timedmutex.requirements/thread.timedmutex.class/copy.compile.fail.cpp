//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <mutex>

// class timed_mutex;

// timed_mutex(const timed_mutex&) = delete;

#include <mutex>

extern "C" int main(int, char**)
{
    std::timed_mutex m0;
    std::timed_mutex m1(m0);

  return 0;
}
