//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <string>

// basic_string<charT,traits,Allocator>& operator=(basic_string_view<charT, traits> sv); // constexpr since C++20

#include <string>
#include <cassert>

#include "test_macros.h"
#include "min_allocator.h"

template <class S, class SV>
TEST_CONSTEXPR_CXX20 void
test(S s1, SV sv)
{
    typedef typename S::traits_type T;
    s1 = sv;
    LIBCPP_ASSERT(s1.__invariants());
    assert(s1.size() == sv.size());
    assert(T::compare(s1.data(), sv.data(), s1.size()) == 0);
    assert(s1.capacity() >= s1.size());
}

template <class S>
TEST_CONSTEXPR_CXX20 void test_string() {
  typedef std::string_view SV;
  test(S(), SV(""));
  test(S("1"), SV(""));
  test(S(), SV("1"));
  test(S("1"), SV("2"));
  test(S("1"), SV("2"));

  test(S(),
        SV("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"));
  test(S("123456789"),
        SV("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"));
  test(S("1234567890123456789012345678901234567890123456789012345678901234567890"),
        SV("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"));
  test(S("1234567890123456789012345678901234567890123456789012345678901234567890"
          "1234567890123456789012345678901234567890123456789012345678901234567890"),
        SV("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"));
}

TEST_CONSTEXPR_CXX20 bool test() {
  test_string<std::string>();
#if TEST_STD_VER >= 11
  test_string<std::basic_string<char, std::char_traits<char>, min_allocator<char>>>();
#endif

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
