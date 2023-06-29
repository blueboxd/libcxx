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

// <cstdlib>

// Test the feature test macros defined by <cstdlib>

/*  Constant                     Value
    __cpp_lib_constexpr_cmath    202202L [C++23]
*/

#include <cstdlib>
#include "test_macros.h"

#if TEST_STD_VER < 14

# ifdef __cpp_lib_constexpr_cmath
#   error "__cpp_lib_constexpr_cmath should not be defined before c++23"
# endif

#elif TEST_STD_VER == 14

# ifdef __cpp_lib_constexpr_cmath
#   error "__cpp_lib_constexpr_cmath should not be defined before c++23"
# endif

#elif TEST_STD_VER == 17

# ifdef __cpp_lib_constexpr_cmath
#   error "__cpp_lib_constexpr_cmath should not be defined before c++23"
# endif

#elif TEST_STD_VER == 20

# ifdef __cpp_lib_constexpr_cmath
#   error "__cpp_lib_constexpr_cmath should not be defined before c++23"
# endif

#elif TEST_STD_VER == 23

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_constexpr_cmath
#     error "__cpp_lib_constexpr_cmath should be defined in c++23"
#   endif
#   if __cpp_lib_constexpr_cmath != 202202L
#     error "__cpp_lib_constexpr_cmath should have the value 202202L in c++23"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_constexpr_cmath
#     error "__cpp_lib_constexpr_cmath should not be defined because it is unimplemented in libc++!"
#   endif
# endif

#elif TEST_STD_VER > 23

# if !defined(_LIBCPP_VERSION)
#   ifndef __cpp_lib_constexpr_cmath
#     error "__cpp_lib_constexpr_cmath should be defined in c++26"
#   endif
#   if __cpp_lib_constexpr_cmath != 202202L
#     error "__cpp_lib_constexpr_cmath should have the value 202202L in c++26"
#   endif
# else // _LIBCPP_VERSION
#   ifdef __cpp_lib_constexpr_cmath
#     error "__cpp_lib_constexpr_cmath should not be defined because it is unimplemented in libc++!"
#   endif
# endif

#endif // TEST_STD_VER > 23

