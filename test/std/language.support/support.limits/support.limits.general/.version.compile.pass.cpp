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

// <>

// Test the feature test macros defined by <>

/*  Constant                           Value
    __cpp_lib_format_uchar             202311L [C++20]
    __cpp_lib_saturation_arithmetic    202311L [C++26]
*/

#include <>
#include "test_macros.h"

#if TEST_STD_VER < 14

# ifdef __cpp_lib_format_uchar
#   error "__cpp_lib_format_uchar should not be defined before c++20"
# endif

# ifdef __cpp_lib_saturation_arithmetic
#   error "__cpp_lib_saturation_arithmetic should not be defined before c++26"
# endif

#elif TEST_STD_VER == 14

# ifdef __cpp_lib_format_uchar
#   error "__cpp_lib_format_uchar should not be defined before c++20"
# endif

# ifdef __cpp_lib_saturation_arithmetic
#   error "__cpp_lib_saturation_arithmetic should not be defined before c++26"
# endif

#elif TEST_STD_VER == 17

# ifdef __cpp_lib_format_uchar
#   error "__cpp_lib_format_uchar should not be defined before c++20"
# endif

# ifdef __cpp_lib_saturation_arithmetic
#   error "__cpp_lib_saturation_arithmetic should not be defined before c++26"
# endif

#elif TEST_STD_VER == 20

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_format_uchar
#     error "__cpp_lib_format_uchar should be defined in c++20"
#   endif
#   if __cpp_lib_format_uchar != 202311L
#     error "__cpp_lib_format_uchar should have the value 202311L in c++20"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_format_uchar
#     error "__cpp_lib_format_uchar should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# ifdef __cpp_lib_saturation_arithmetic
#   error "__cpp_lib_saturation_arithmetic should not be defined before c++26"
# endif

#elif TEST_STD_VER == 23

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_format_uchar
#     error "__cpp_lib_format_uchar should be defined in c++23"
#   endif
#   if __cpp_lib_format_uchar != 202311L
#     error "__cpp_lib_format_uchar should have the value 202311L in c++23"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_format_uchar
#     error "__cpp_lib_format_uchar should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# ifdef __cpp_lib_saturation_arithmetic
#   error "__cpp_lib_saturation_arithmetic should not be defined before c++26"
# endif

#elif TEST_STD_VER > 23

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_format_uchar
#     error "__cpp_lib_format_uchar should be defined in c++26"
#   endif
#   if __cpp_lib_format_uchar != 202311L
#     error "__cpp_lib_format_uchar should have the value 202311L in c++26"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_format_uchar
#     error "__cpp_lib_format_uchar should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_saturation_arithmetic
#     error "__cpp_lib_saturation_arithmetic should be defined in c++26"
#   endif
#   if __cpp_lib_saturation_arithmetic != 202311L
#     error "__cpp_lib_saturation_arithmetic should have the value 202311L in c++26"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_saturation_arithmetic
#     error "__cpp_lib_saturation_arithmetic should not be defined because it is unimplemented in libc++!"
#   endif
# endif

#endif // TEST_STD_VER > 23

