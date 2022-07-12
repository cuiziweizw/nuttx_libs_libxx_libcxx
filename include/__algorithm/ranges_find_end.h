//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP___ALGORITHM_RANGES_FIND_END_H
#define _LIBCPP___ALGORITHM_RANGES_FIND_END_H

#include <__algorithm/find_end.h>
#include <__algorithm/iterator_operations.h>
#include <__config>
#include <__functional/identity.h>
#include <__functional/ranges_operations.h>
#include <__iterator/concepts.h>
#include <__iterator/indirectly_comparable.h>
#include <__iterator/iterator_traits.h>
#include <__ranges/access.h>
#include <__ranges/concepts.h>
#include <__ranges/subrange.h>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#  pragma GCC system_header
#endif

#if _LIBCPP_STD_VER > 17 && !defined(_LIBCPP_HAS_NO_INCOMPLETE_RANGES)

_LIBCPP_BEGIN_NAMESPACE_STD

template <class _Iter>
consteval auto __get_iterator_concept() {
  if constexpr (contiguous_iterator<_Iter>)
    return contiguous_iterator_tag();
  else if constexpr (random_access_iterator<_Iter>)
    return random_access_iterator_tag();
  else if constexpr (bidirectional_iterator<_Iter>)
    return bidirectional_iterator_tag();
  else if constexpr (forward_iterator<_Iter>)
    return forward_iterator_tag();
  else if constexpr (input_iterator<_Iter>)
    return input_iterator_tag();
}

template <class _Iter>
using __iterator_concept = decltype(__get_iterator_concept<_Iter>());

namespace ranges {
namespace __find_end {
struct __fn {
  template <forward_iterator _Iter1, sentinel_for<_Iter1> _Sent1,
            forward_iterator _Iter2, sentinel_for<_Iter2> _Sent2,
            class _Pred = ranges::equal_to,
            class _Proj1 = identity,
            class _Proj2 = identity>
    requires indirectly_comparable<_Iter1, _Iter2, _Pred, _Proj1, _Proj2>
  _LIBCPP_HIDE_FROM_ABI constexpr
  subrange<_Iter1> operator()(_Iter1 __first1, _Sent1 __last1,
                              _Iter2 __first2, _Sent2 __last2,
                              _Pred __pred = {},
                              _Proj1 __proj1 = {},
                              _Proj2 __proj2 = {}) const {
    auto __ret = std::__find_end_impl<_RangesIterOps>(
        __first1,
        __last1,
        __first2,
        __last2,
        __pred,
        __proj1,
        __proj2,
        __iterator_concept<_Iter1>(),
        __iterator_concept<_Iter2>());
    return {__ret.first, __ret.second};
  }

  template <forward_range _Range1,
            forward_range _Range2,
            class _Pred = ranges::equal_to,
            class _Proj1 = identity,
            class _Proj2 = identity>
    requires indirectly_comparable<iterator_t<_Range1>, iterator_t<_Range2>, _Pred, _Proj1, _Proj2>
  _LIBCPP_HIDE_FROM_ABI constexpr
  borrowed_subrange_t<_Range1> operator()(_Range1&& __range1,
                                          _Range2&& __range2,
                                          _Pred __pred = {},
                                          _Proj1 __proj1 = {},
                                          _Proj2 __proj2 = {}) const {
    auto __ret = std::__find_end_impl<_RangesIterOps>(
        ranges::begin(__range1),
        ranges::end(__range1),
        ranges::begin(__range2),
        ranges::end(__range2),
        __pred,
        __proj1,
        __proj2,
        __iterator_concept<iterator_t<_Range1>>(),
        __iterator_concept<iterator_t<_Range2>>());
    return {__ret.first, __ret.second};
  }
};
} // namespace __find_end

inline namespace __cpo {
  inline constexpr auto find_end = __find_end::__fn{};
} // namespace __cpo
} // namespace ranges

_LIBCPP_END_NAMESPACE_STD

#endif // _LIBCPP_STD_VER > 17 && !defined(_LIBCPP_HAS_NO_INCOMPLETE_RANGES)

#endif // _LIBCPP___ALGORITHM_RANGES_FIND_END_H
