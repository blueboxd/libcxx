// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#ifndef _LIBCPP___RANGES_RBEGIN_H
#define _LIBCPP___RANGES_RBEGIN_H

#include <__concepts/class_or_enum.h>
#include <__concepts/same_as.h>
#include <__config>
#include <__iterator/concepts.h>
#include <__iterator/readable_traits.h>
#include <__iterator/reverse_iterator.h>
#include <__ranges/access.h>
#include <__utility/auto_cast.h>
#include <type_traits>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#  pragma GCC system_header
#  pragma clang include_instead(<ranges>)
#endif

_LIBCPP_BEGIN_NAMESPACE_STD

#if !defined(_LIBCPP_HAS_NO_CONCEPTS) && !defined(_LIBCPP_HAS_NO_INCOMPLETE_RANGES)

// [ranges.access.rbegin]

namespace ranges {
namespace __rbegin {
template <class _Tp>
concept __member_rbegin =
  __can_borrow<_Tp> &&
  __workaround_52970<_Tp> &&
  requires(_Tp&& __t) {
    { _LIBCPP_AUTO_CAST(__t.rbegin()) } -> input_or_output_iterator;
  };

void rbegin(auto&) = delete;
void rbegin(const auto&) = delete;

template <class _Tp>
concept __unqualified_rbegin =
  !__member_rbegin<_Tp> &&
  __can_borrow<_Tp> &&
  __class_or_enum<remove_cvref_t<_Tp>> &&
  requires(_Tp&& __t) {
    { _LIBCPP_AUTO_CAST(rbegin(__t)) } -> input_or_output_iterator;
  };

template <class _Tp>
concept __can_reverse =
  __can_borrow<_Tp> &&
  !__member_rbegin<_Tp> &&
  !__unqualified_rbegin<_Tp> &&
  requires(_Tp&& __t) {
    { ranges::begin(__t) } -> same_as<decltype(ranges::end(__t))>;
    { ranges::begin(__t) } -> bidirectional_iterator;
  };

struct __fn {
  template <class _Tp>
    requires __member_rbegin<_Tp>
  [[nodiscard]] _LIBCPP_HIDE_FROM_ABI constexpr auto operator()(_Tp&& __t) const
    noexcept(noexcept(_LIBCPP_AUTO_CAST(__t.rbegin())))
  {
    return _LIBCPP_AUTO_CAST(__t.rbegin());
  }

  template <class _Tp>
    requires __unqualified_rbegin<_Tp>
  [[nodiscard]] _LIBCPP_HIDE_FROM_ABI constexpr auto operator()(_Tp&& __t) const
    noexcept(noexcept(_LIBCPP_AUTO_CAST(rbegin(__t))))
  {
    return _LIBCPP_AUTO_CAST(rbegin(__t));
  }

  template <class _Tp>
    requires __can_reverse<_Tp>
  [[nodiscard]] _LIBCPP_HIDE_FROM_ABI constexpr auto operator()(_Tp&& __t) const
    noexcept(noexcept(ranges::end(__t)))
  {
    return std::make_reverse_iterator(ranges::end(__t));
  }

  void operator()(auto&&) const = delete;
};
} // namespace __rbegin

inline namespace __cpo {
  inline constexpr auto rbegin = __rbegin::__fn{};
} // namespace __cpo
} // namespace ranges

// [range.access.crbegin]

namespace ranges {
namespace __crbegin {
struct __fn {
  template <class _Tp>
    requires is_lvalue_reference_v<_Tp&&>
  [[nodiscard]] _LIBCPP_HIDE_FROM_ABI
  constexpr auto operator()(_Tp&& __t) const
    noexcept(noexcept(ranges::rbegin(static_cast<const remove_reference_t<_Tp>&>(__t))))
    -> decltype(      ranges::rbegin(static_cast<const remove_reference_t<_Tp>&>(__t)))
    { return          ranges::rbegin(static_cast<const remove_reference_t<_Tp>&>(__t)); }

  template <class _Tp>
    requires is_rvalue_reference_v<_Tp&&>
  [[nodiscard]] _LIBCPP_HIDE_FROM_ABI
  constexpr auto operator()(_Tp&& __t) const
    noexcept(noexcept(ranges::rbegin(static_cast<const _Tp&&>(__t))))
    -> decltype(      ranges::rbegin(static_cast<const _Tp&&>(__t)))
    { return          ranges::rbegin(static_cast<const _Tp&&>(__t)); }
};
} // namespace __crbegin

inline namespace __cpo {
  inline constexpr auto crbegin = __crbegin::__fn{};
} // namespace __cpo
} // namespace ranges

#endif // !defined(_LIBCPP_HAS_NO_CONCEPTS) && !defined(_LIBCPP_HAS_NO_INCOMPLETE_RANGES)

_LIBCPP_END_NAMESPACE_STD

#endif // _LIBCPP___RANGES_RBEGIN_H
