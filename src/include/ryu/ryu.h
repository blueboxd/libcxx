// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// Copyright (c) Microsoft Corporation.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception


// Copyright 2018 Ulf Adams
// Copyright (c) Microsoft Corporation. All rights reserved.

// Boost Software License - Version 1.0 - August 17th, 2003

// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:

// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#ifndef _LIBCPP_SRC_INCLUDE_RYU_RYU_H
#define _LIBCPP_SRC_INCLUDE_RYU_RYU_H

// Avoid formatting to keep the changes with the original code minimal.
// clang-format off

#include "__charconv/chars_format.h"
#include "__charconv/to_chars_result.h"
#include "__config"
#include "__debug"
#include "__errc"
#include "cstdint"
#include "cstring"
#include "type_traits"
#include "include/ryu/f2s.h"
#include "include/ryu/d2s.h"
#include "include/ryu/d2fixed.h"

#if defined(_M_X64) && defined(_LIBCPP_COMPILER_MSVC)
#include <intrin0.h> // for _umul128() and __shiftright128()
#endif // defined(_M_X64) && defined(_LIBCPP_COMPILER_MSVC)

#if defined(_WIN64) || defined(_M_AMD64) || defined(__x86_64__) ||  defined(__aarch64__)
#define _LIBCPP_64_BIT
#endif

_LIBCPP_BEGIN_NAMESPACE_STD

// https://github.com/ulfjack/ryu/tree/59661c3/ryu

#if !defined(_LIBCPP_COMPILER_MSVC)
_LIBCPP_HIDE_FROM_ABI inline unsigned char _BitScanForward64(unsigned long* __index, unsigned long long __mask) {
  if (__mask == 0) {
    return false;
  }
  *__index = __builtin_ctzll(__mask);
  return true;
}

_LIBCPP_HIDE_FROM_ABI inline unsigned char _BitScanForward(unsigned long* __index, unsigned int __mask) {
  if (__mask == 0) {
    return false;
  }
  *__index = __builtin_ctz(__mask);
  return true;
}
#endif  // _LIBCPP_COMPILER_MSVC

template <class _Floating>
[[nodiscard]] to_chars_result _Floating_to_chars_ryu(
    char* const _First, char* const _Last, const _Floating _Value, const chars_format _Fmt) noexcept {
    if constexpr (_IsSame<_Floating, float>::value) {
        return __f2s_buffered_n(_First, _Last, _Value, _Fmt);
    } else {
        return __d2s_buffered_n(_First, _Last, _Value, _Fmt);
    }
}

template <class _Floating>
[[nodiscard]] _LIBCPP_HIDE_FROM_ABI to_chars_result _Floating_to_chars_scientific_precision(
    char* const _First, char* const _Last, const _Floating _Value, int _Precision) noexcept {

    // C11 7.21.6.1 "The fprintf function"/5:
    // "A negative precision argument is taken as if the precision were omitted."
    // /8: "e,E [...] if the precision is missing, it is taken as 6"

    if (_Precision < 0) {
        _Precision = 6;
    } else if (_Precision < 1'000'000'000) { // Match ' to fix compilation with GCC in C++11 mode
        // _Precision is ok.
    } else {
        // Avoid integer overflow.
        // (This defensive check is slightly nonconformant; it can be carefully improved in the future.)
        return {_Last, errc::value_too_large};
    }

    return __d2exp_buffered_n(_First, _Last, _Value, static_cast<uint32_t>(_Precision));
}

template <class _Floating>
[[nodiscard]] _LIBCPP_HIDE_FROM_ABI to_chars_result _Floating_to_chars_fixed_precision(
    char* const _First, char* const _Last, const _Floating _Value, int _Precision) noexcept {

    // C11 7.21.6.1 "The fprintf function"/5:
    // "A negative precision argument is taken as if the precision were omitted."
    // /8: "f,F [...] If the precision is missing, it is taken as 6"

    if (_Precision < 0) {
        _Precision = 6;
    } else if (_Precision < 1'000'000'000) { // Match ' to fix compilation with GCC in C++11 mode
        // _Precision is ok.
    } else {
        // Avoid integer overflow.
        // (This defensive check is slightly nonconformant; it can be carefully improved in the future.)
        return {_Last, errc::value_too_large};
    }

    return __d2fixed_buffered_n(_First, _Last, _Value, static_cast<uint32_t>(_Precision));
}

#undef _LIBCPP_64_BIT
#undef _LIBCPP_INTRINSIC128

_LIBCPP_END_NAMESPACE_STD

// clang-format on

#endif // _LIBCPP_SRC_INCLUDE_RYU_RYU_H
