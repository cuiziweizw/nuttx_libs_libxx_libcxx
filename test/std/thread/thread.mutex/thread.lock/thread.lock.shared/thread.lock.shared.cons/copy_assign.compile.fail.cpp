//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03, c++11
// <shared_mutex>

// template <class Mutex> class shared_lock;

// shared_lock& operator=(shared_lock const&) = delete;

#include <shared_mutex>

static std::shared_timed_mutex m0;
static std::shared_timed_mutex m1;

extern "C" int main(int, char**)
{
    std::shared_lock<std::shared_timed_mutex> lk0(m0);
    std::shared_lock<std::shared_timed_mutex> lk1(m1);
    lk1 = lk0;

  return 0;
}
