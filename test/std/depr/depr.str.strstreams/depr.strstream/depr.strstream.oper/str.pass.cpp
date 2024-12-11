//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// ADDITIONAL_COMPILE_FLAGS: -D_LIBCPP_DISABLE_DEPRECATION_WARNINGS

// <strstream>

// class strstream

// char* str();

#include <strstream>
#include <cassert>

#include "test_macros.h"

extern "C" int main(int, char**)
{
    {
        std::strstream out;
        out << 123 << ' ' << 4.5 << ' ' << "dog" << std::ends;
        assert(out.str() == std::string("123 4.5 dog"));
        out.freeze(false);
    }

  return 0;
}
