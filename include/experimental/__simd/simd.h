// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP_EXPERIMENTAL___SIMD_SIMD_H
#define _LIBCPP_EXPERIMENTAL___SIMD_SIMD_H

#include <experimental/__simd/abi_tag.h>
#include <experimental/__simd/declaration.h>
#include <experimental/__simd/traits.h>

#if _LIBCPP_STD_VER >= 17 && defined(_LIBCPP_ENABLE_EXPERIMENTAL)

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL
inline namespace parallelism_v2 {

// class template simd [simd.class]
// TODO: implement simd class
template <class _Tp, class _Abi>
class simd {
public:
  using value_type = _Tp;
  using mask_type  = simd_mask<_Tp, _Abi>;
  using abi_type   = _Abi;

  static _LIBCPP_HIDE_FROM_ABI constexpr size_t size() noexcept { return simd_size_v<value_type, abi_type>; }
};

template <class _Tp>
using native_simd = simd<_Tp, simd_abi::native<_Tp>>;

template <class _Tp, int _Np>
using fixed_size_simd = simd<_Tp, simd_abi::fixed_size<_Np>>;

} // namespace parallelism_v2
_LIBCPP_END_NAMESPACE_EXPERIMENTAL

#endif // _LIBCPP_STD_VER >= 17 && defined(_LIBCPP_ENABLE_EXPERIMENTAL)
#endif // _LIBCPP_EXPERIMENTAL___SIMD_SIMD_H
