//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// void* operator new(std::size_t, std::align_val_t, std::nothrow_t const&);

// UNSUPPORTED: c++03, c++11, c++14

// We get availability markup errors when aligned allocation is missing
// XFAIL: availability-aligned_allocation-missing

// https://reviews.llvm.org/D129198 is not in AppleClang 14
// XFAIL: stdlib=apple-libc++ && target={{.+}}-apple-macosx10.13{{(.0)?}} && apple-clang-14

// asan and msan will not call the new handler.
// UNSUPPORTED: sanitizer-new-delete

// Libc++ when built for z/OS doesn't contain the aligned allocation functions,
// nor does the dynamic library shipped with z/OS.
// UNSUPPORTED: target={{.+}}-zos{{.*}}

#include <new>
#include <cstddef>
#include <cstdint>
#include <cassert>
#include <limits>

#include "test_macros.h"
#include "../types.h"

static int new_handler_called = 0;

static void my_new_handler() {
    ++new_handler_called;
    std::set_new_handler(nullptr);
}

extern "C" int main(int, char**) {
    // Test that we can call the function directly
    {
        void* x = operator new(10, static_cast<std::align_val_t>(64), std::nothrow);
        assert(x != nullptr);
        assert(reinterpret_cast<std::uintptr_t>(x) % 64 == 0);
        operator delete(x, static_cast<std::align_val_t>(64), std::nothrow);
    }

    // Test that the new handler is called and we return nullptr if allocation fails
    {
        std::set_new_handler(my_new_handler);
        void* x = operator new(std::numeric_limits<std::size_t>::max(),
                               static_cast<std::align_val_t>(32), std::nothrow);
        assert(new_handler_called == 1);
        assert(x == nullptr);
    }

    // Test that a new expression constructs the right object
    // and a delete expression deletes it
    {
        LifetimeInformation info;
        TrackLifetimeOverAligned* x = new (std::nothrow) TrackLifetimeOverAligned(info);
        assert(x != nullptr);
        assert(reinterpret_cast<std::uintptr_t>(x) % alignof(TrackLifetimeOverAligned) == 0);
        assert(info.address_constructed == x);

        delete x;
        assert(info.address_destroyed == x);
    }

    return 0;
}
