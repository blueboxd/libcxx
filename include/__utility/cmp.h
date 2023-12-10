//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP___UTILITY_CMP_H
#define _LIBCPP___UTILITY_CMP_H

#include <__config>
#include <__type_traits/disjunction.h>
#include <__type_traits/is_integral.h>
#include <__type_traits/is_same.h>
#include <__type_traits/is_signed.h>
#include <__type_traits/make_unsigned.h>
#include <__utility/forward.h>
#include <__utility/move.h>
#include <limits>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#  pragma GCC system_header
#endif

_LIBCPP_PUSH_MACROS
#include <__undef_macros>

_LIBCPP_BEGIN_NAMESPACE_STD

#if _LIBCPP_STD_VER >= 20
template<class _Tp, class... _Up>
struct _IsSameAsAny : _Or<_IsSame<_Tp, _Up>...> {};

template<class _Tp>
concept __is_safe_integral_cmp = is_integral_v<_Tp> &&
                      !_IsSameAsAny<_Tp, bool, char, char16_t, char32_t
#ifndef _LIBCPP_HAS_NO_CHAR8_T
                                    , char8_t
#endif
#ifndef _LIBCPP_HAS_NO_WIDE_CHARACTERS
                                    , wchar_t
#endif
                                    >::value;

template<__is_safe_integral_cmp _Tp, __is_safe_integral_cmp _Up>
_LIBCPP_HIDE_FROM_ABI constexpr
bool cmp_equal(_Tp __t, _Up __u) noexcept
{
  if constexpr (is_signed_v<_Tp> == is_signed_v<_Up>)
    return __t == __u;
  else if constexpr (is_signed_v<_Tp>)
    return __t < 0 ? false : make_unsigned_t<_Tp>(__t) == __u;
  else
    return __u < 0 ? false : __t == make_unsigned_t<_Up>(__u);
}

template<__is_safe_integral_cmp _Tp, __is_safe_integral_cmp _Up>
_LIBCPP_HIDE_FROM_ABI constexpr
bool cmp_not_equal(_Tp __t, _Up __u) noexcept
{
  return !std::cmp_equal(__t, __u);
}

template<__is_safe_integral_cmp _Tp, __is_safe_integral_cmp _Up>
_LIBCPP_HIDE_FROM_ABI constexpr
bool cmp_less(_Tp __t, _Up __u) noexcept
{
  if constexpr (is_signed_v<_Tp> == is_signed_v<_Up>)
    return __t < __u;
  else if constexpr (is_signed_v<_Tp>)
    return __t < 0 ? true : make_unsigned_t<_Tp>(__t) < __u;
  else
    return __u < 0 ? false : __t < make_unsigned_t<_Up>(__u);
}

template<__is_safe_integral_cmp _Tp, __is_safe_integral_cmp _Up>
_LIBCPP_HIDE_FROM_ABI constexpr
bool cmp_greater(_Tp __t, _Up __u) noexcept
{
  return std::cmp_less(__u, __t);
}

template<__is_safe_integral_cmp _Tp, __is_safe_integral_cmp _Up>
_LIBCPP_HIDE_FROM_ABI constexpr
bool cmp_less_equal(_Tp __t, _Up __u) noexcept
{
  return !std::cmp_greater(__t, __u);
}

template<__is_safe_integral_cmp _Tp, __is_safe_integral_cmp _Up>
_LIBCPP_HIDE_FROM_ABI constexpr
bool cmp_greater_equal(_Tp __t, _Up __u) noexcept
{
  return !std::cmp_less(__t, __u);
}

template<__is_safe_integral_cmp _Tp, __is_safe_integral_cmp _Up>
_LIBCPP_HIDE_FROM_ABI constexpr
bool in_range(_Up __u) noexcept
{
  return std::cmp_less_equal(__u, numeric_limits<_Tp>::max()) &&
         std::cmp_greater_equal(__u, numeric_limits<_Tp>::min());
}
#endif // _LIBCPP_STD_VER >= 20

_LIBCPP_END_NAMESPACE_STD

_LIBCPP_POP_MACROS

#endif // _LIBCPP___UTILITY_CMP_H
