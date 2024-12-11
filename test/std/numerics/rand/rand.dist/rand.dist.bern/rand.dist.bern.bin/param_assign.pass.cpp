//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <random>

// template<class IntType = int>
// class binomial_distribution
// {
//     class param_type;

#include <random>
#include <limits>
#include <cassert>

#include "test_macros.h"

extern "C" int main(int, char**)
{
    {
        typedef std::binomial_distribution<> D;
        typedef D::param_type param_type;
        param_type p0(6, .7);
        param_type p;
        p = p0;
        assert(p.t() == 6);
        assert(p.p() == .7);
    }

  return 0;
}
