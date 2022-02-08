//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// WARNING: This test was generated by generate_feature_test_macro_components.py
// and should not be edited manually.
//
// clang-format off

// <string>

// Test the feature test macros defined by <string>

/*  Constant                                      Value
    __cpp_lib_allocator_traits_is_always_equal    201411L [C++17]
    __cpp_lib_char8_t                             201811L [C++20]
    __cpp_lib_constexpr_string                    201811L [C++20]
    __cpp_lib_erase_if                            202002L [C++20]
    __cpp_lib_nonmember_container_access          201411L [C++17]
    __cpp_lib_ranges_to_container                 202202L [C++2b]
    __cpp_lib_starts_ends_with                    201711L [C++20]
    __cpp_lib_string_contains                     202011L [C++2b]
    __cpp_lib_string_resize_and_overwrite         202110L [C++2b]
    __cpp_lib_string_udls                         201304L [C++14]
    __cpp_lib_string_view                         201606L [C++17]
                                                  201803L [C++20]
*/

#include <string>
#include "test_macros.h"

#if TEST_STD_VER < 14

# ifdef __cpp_lib_allocator_traits_is_always_equal
#   error "__cpp_lib_allocator_traits_is_always_equal should not be defined before c++17"
# endif

# ifdef __cpp_lib_char8_t
#   error "__cpp_lib_char8_t should not be defined before c++20"
# endif

# ifdef __cpp_lib_constexpr_string
#   error "__cpp_lib_constexpr_string should not be defined before c++20"
# endif

# ifdef __cpp_lib_erase_if
#   error "__cpp_lib_erase_if should not be defined before c++20"
# endif

# ifdef __cpp_lib_nonmember_container_access
#   error "__cpp_lib_nonmember_container_access should not be defined before c++17"
# endif

# ifdef __cpp_lib_ranges_to_container
#   error "__cpp_lib_ranges_to_container should not be defined before c++2b"
# endif

# ifdef __cpp_lib_starts_ends_with
#   error "__cpp_lib_starts_ends_with should not be defined before c++20"
# endif

# ifdef __cpp_lib_string_contains
#   error "__cpp_lib_string_contains should not be defined before c++2b"
# endif

# ifdef __cpp_lib_string_resize_and_overwrite
#   error "__cpp_lib_string_resize_and_overwrite should not be defined before c++2b"
# endif

# ifdef __cpp_lib_string_udls
#   error "__cpp_lib_string_udls should not be defined before c++14"
# endif

# ifdef __cpp_lib_string_view
#   error "__cpp_lib_string_view should not be defined before c++17"
# endif

#elif TEST_STD_VER == 14

# ifdef __cpp_lib_allocator_traits_is_always_equal
#   error "__cpp_lib_allocator_traits_is_always_equal should not be defined before c++17"
# endif

# ifdef __cpp_lib_char8_t
#   error "__cpp_lib_char8_t should not be defined before c++20"
# endif

# ifdef __cpp_lib_constexpr_string
#   error "__cpp_lib_constexpr_string should not be defined before c++20"
# endif

# ifdef __cpp_lib_erase_if
#   error "__cpp_lib_erase_if should not be defined before c++20"
# endif

# ifdef __cpp_lib_nonmember_container_access
#   error "__cpp_lib_nonmember_container_access should not be defined before c++17"
# endif

# ifdef __cpp_lib_ranges_to_container
#   error "__cpp_lib_ranges_to_container should not be defined before c++2b"
# endif

# ifdef __cpp_lib_starts_ends_with
#   error "__cpp_lib_starts_ends_with should not be defined before c++20"
# endif

# ifdef __cpp_lib_string_contains
#   error "__cpp_lib_string_contains should not be defined before c++2b"
# endif

# ifdef __cpp_lib_string_resize_and_overwrite
#   error "__cpp_lib_string_resize_and_overwrite should not be defined before c++2b"
# endif

# ifndef __cpp_lib_string_udls
#   error "__cpp_lib_string_udls should be defined in c++14"
# endif
# if __cpp_lib_string_udls != 201304L
#   error "__cpp_lib_string_udls should have the value 201304L in c++14"
# endif

# ifdef __cpp_lib_string_view
#   error "__cpp_lib_string_view should not be defined before c++17"
# endif

#elif TEST_STD_VER == 17

# ifndef __cpp_lib_allocator_traits_is_always_equal
#   error "__cpp_lib_allocator_traits_is_always_equal should be defined in c++17"
# endif
# if __cpp_lib_allocator_traits_is_always_equal != 201411L
#   error "__cpp_lib_allocator_traits_is_always_equal should have the value 201411L in c++17"
# endif

# ifdef __cpp_lib_char8_t
#   error "__cpp_lib_char8_t should not be defined before c++20"
# endif

# ifdef __cpp_lib_constexpr_string
#   error "__cpp_lib_constexpr_string should not be defined before c++20"
# endif

# ifdef __cpp_lib_erase_if
#   error "__cpp_lib_erase_if should not be defined before c++20"
# endif

# ifndef __cpp_lib_nonmember_container_access
#   error "__cpp_lib_nonmember_container_access should be defined in c++17"
# endif
# if __cpp_lib_nonmember_container_access != 201411L
#   error "__cpp_lib_nonmember_container_access should have the value 201411L in c++17"
# endif

# ifdef __cpp_lib_ranges_to_container
#   error "__cpp_lib_ranges_to_container should not be defined before c++2b"
# endif

# ifdef __cpp_lib_starts_ends_with
#   error "__cpp_lib_starts_ends_with should not be defined before c++20"
# endif

# ifdef __cpp_lib_string_contains
#   error "__cpp_lib_string_contains should not be defined before c++2b"
# endif

# ifdef __cpp_lib_string_resize_and_overwrite
#   error "__cpp_lib_string_resize_and_overwrite should not be defined before c++2b"
# endif

# ifndef __cpp_lib_string_udls
#   error "__cpp_lib_string_udls should be defined in c++17"
# endif
# if __cpp_lib_string_udls != 201304L
#   error "__cpp_lib_string_udls should have the value 201304L in c++17"
# endif

# ifndef __cpp_lib_string_view
#   error "__cpp_lib_string_view should be defined in c++17"
# endif
# if __cpp_lib_string_view != 201606L
#   error "__cpp_lib_string_view should have the value 201606L in c++17"
# endif

#elif TEST_STD_VER == 20

# ifndef __cpp_lib_allocator_traits_is_always_equal
#   error "__cpp_lib_allocator_traits_is_always_equal should be defined in c++20"
# endif
# if __cpp_lib_allocator_traits_is_always_equal != 201411L
#   error "__cpp_lib_allocator_traits_is_always_equal should have the value 201411L in c++20"
# endif

# if defined(__cpp_char8_t)
#   ifndef __cpp_lib_char8_t
#     error "__cpp_lib_char8_t should be defined in c++20"
#   endif
#   if __cpp_lib_char8_t != 201811L
#     error "__cpp_lib_char8_t should have the value 201811L in c++20"
#   endif
# else
#   ifdef __cpp_lib_char8_t
#     error "__cpp_lib_char8_t should not be defined when defined(__cpp_char8_t) is not defined!"
#   endif
# endif

# ifndef __cpp_lib_constexpr_string
#   error "__cpp_lib_constexpr_string should be defined in c++20"
# endif
# if __cpp_lib_constexpr_string != 201811L
#   error "__cpp_lib_constexpr_string should have the value 201811L in c++20"
# endif

# ifndef __cpp_lib_erase_if
#   error "__cpp_lib_erase_if should be defined in c++20"
# endif
# if __cpp_lib_erase_if != 202002L
#   error "__cpp_lib_erase_if should have the value 202002L in c++20"
# endif

# ifndef __cpp_lib_nonmember_container_access
#   error "__cpp_lib_nonmember_container_access should be defined in c++20"
# endif
# if __cpp_lib_nonmember_container_access != 201411L
#   error "__cpp_lib_nonmember_container_access should have the value 201411L in c++20"
# endif

# ifdef __cpp_lib_ranges_to_container
#   error "__cpp_lib_ranges_to_container should not be defined before c++2b"
# endif

# ifndef __cpp_lib_starts_ends_with
#   error "__cpp_lib_starts_ends_with should be defined in c++20"
# endif
# if __cpp_lib_starts_ends_with != 201711L
#   error "__cpp_lib_starts_ends_with should have the value 201711L in c++20"
# endif

# ifdef __cpp_lib_string_contains
#   error "__cpp_lib_string_contains should not be defined before c++2b"
# endif

# ifdef __cpp_lib_string_resize_and_overwrite
#   error "__cpp_lib_string_resize_and_overwrite should not be defined before c++2b"
# endif

# ifndef __cpp_lib_string_udls
#   error "__cpp_lib_string_udls should be defined in c++20"
# endif
# if __cpp_lib_string_udls != 201304L
#   error "__cpp_lib_string_udls should have the value 201304L in c++20"
# endif

# ifndef __cpp_lib_string_view
#   error "__cpp_lib_string_view should be defined in c++20"
# endif
# if __cpp_lib_string_view != 201803L
#   error "__cpp_lib_string_view should have the value 201803L in c++20"
# endif

#elif TEST_STD_VER > 20

# ifndef __cpp_lib_allocator_traits_is_always_equal
#   error "__cpp_lib_allocator_traits_is_always_equal should be defined in c++2b"
# endif
# if __cpp_lib_allocator_traits_is_always_equal != 201411L
#   error "__cpp_lib_allocator_traits_is_always_equal should have the value 201411L in c++2b"
# endif

# if defined(__cpp_char8_t)
#   ifndef __cpp_lib_char8_t
#     error "__cpp_lib_char8_t should be defined in c++2b"
#   endif
#   if __cpp_lib_char8_t != 201811L
#     error "__cpp_lib_char8_t should have the value 201811L in c++2b"
#   endif
# else
#   ifdef __cpp_lib_char8_t
#     error "__cpp_lib_char8_t should not be defined when defined(__cpp_char8_t) is not defined!"
#   endif
# endif

# ifndef __cpp_lib_constexpr_string
#   error "__cpp_lib_constexpr_string should be defined in c++2b"
# endif
# if __cpp_lib_constexpr_string != 201811L
#   error "__cpp_lib_constexpr_string should have the value 201811L in c++2b"
# endif

# ifndef __cpp_lib_erase_if
#   error "__cpp_lib_erase_if should be defined in c++2b"
# endif
# if __cpp_lib_erase_if != 202002L
#   error "__cpp_lib_erase_if should have the value 202002L in c++2b"
# endif

# ifndef __cpp_lib_nonmember_container_access
#   error "__cpp_lib_nonmember_container_access should be defined in c++2b"
# endif
# if __cpp_lib_nonmember_container_access != 201411L
#   error "__cpp_lib_nonmember_container_access should have the value 201411L in c++2b"
# endif

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_ranges_to_container
#     error "__cpp_lib_ranges_to_container should be defined in c++2b"
#   endif
#   if __cpp_lib_ranges_to_container != 202202L
#     error "__cpp_lib_ranges_to_container should have the value 202202L in c++2b"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_ranges_to_container
#     error "__cpp_lib_ranges_to_container should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# ifndef __cpp_lib_starts_ends_with
#   error "__cpp_lib_starts_ends_with should be defined in c++2b"
# endif
# if __cpp_lib_starts_ends_with != 201711L
#   error "__cpp_lib_starts_ends_with should have the value 201711L in c++2b"
# endif

# ifndef __cpp_lib_string_contains
#   error "__cpp_lib_string_contains should be defined in c++2b"
# endif
# if __cpp_lib_string_contains != 202011L
#   error "__cpp_lib_string_contains should have the value 202011L in c++2b"
# endif

# ifndef __cpp_lib_string_resize_and_overwrite
#   error "__cpp_lib_string_resize_and_overwrite should be defined in c++2b"
# endif
# if __cpp_lib_string_resize_and_overwrite != 202110L
#   error "__cpp_lib_string_resize_and_overwrite should have the value 202110L in c++2b"
# endif

# ifndef __cpp_lib_string_udls
#   error "__cpp_lib_string_udls should be defined in c++2b"
# endif
# if __cpp_lib_string_udls != 201304L
#   error "__cpp_lib_string_udls should have the value 201304L in c++2b"
# endif

# ifndef __cpp_lib_string_view
#   error "__cpp_lib_string_view should be defined in c++2b"
# endif
# if __cpp_lib_string_view != 201803L
#   error "__cpp_lib_string_view should have the value 201803L in c++2b"
# endif

#endif // TEST_STD_VER > 20

int main(int, char**) { return 0; }
