# Build a libc++ shared library, but merge libc++abi and libunwind into it.
set(LIBCXX_ENABLE_SHARED ON CACHE BOOL "")
set(LIBCXX_ENABLE_ABI_LINKER_SCRIPT OFF CACHE BOOL "")
set(LIBCXX_ENABLE_STATIC_ABI_LIBRARY ON CACHE BOOL "")
set(LIBCXX_STATICALLY_LINK_ABI_IN_SHARED_LIBRARY ON CACHE BOOL "")

set(LIBCXXABI_ENABLE_SHARED OFF CACHE BOOL "")
set(LIBCXXABI_USE_LLVM_UNWINDER ON CACHE BOOL "")
set(LIBCXXABI_ENABLE_STATIC_UNWINDER ON CACHE BOOL "")
set(LIBCXXABI_STATICALLY_LINK_UNWINDER_IN_STATIC_LIBRARY ON CACHE BOOL "")

set(LIBUNWIND_ENABLE_SHARED OFF CACHE BOOL "")