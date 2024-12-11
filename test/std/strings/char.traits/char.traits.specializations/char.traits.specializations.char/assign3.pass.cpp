//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <string>

// template<> struct char_traits<char>

// static char_type* assign(char_type* s, size_t n, char_type a);

#include <string>
#include <cassert>

#include "test_macros.h"

TEST_CONSTEXPR_CXX20 bool test()
{
    char s2[3] = {0};
    assert(std::char_traits<char>::assign(s2, 3, char(5)) == s2);
    assert(s2[0] == char(5));
    assert(s2[1] == char(5));
    assert(s2[2] == char(5));
    assert(std::char_traits<char>::assign(NULL, 0, char(5)) == NULL);

  return true;
}

extern "C" int main(int, char**)
{
    test();

#if TEST_STD_VER > 17
    static_assert(test());
#endif

  return 0;
}
