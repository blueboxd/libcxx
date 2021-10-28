//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// UNSUPPORTED: libcpp-has-no-threads
// UNSUPPORTED: c++03, c++11

// This test requires the dylib support introduced in D68480, which shipped in
// macOS 11.0.
// XFAIL: use_system_cxx_lib && target={{.+}}-apple-macosx10.{{9|10|11|12|13|14|15}}

// TODO(ldionne): This test fails on Ubuntu Focal on our CI nodes (and only there), in 32 bit mode.
// UNSUPPORTED: linux && 32bits-on-64bits

// <barrier>

#include <barrier>
#include <thread>

#include "make_test_thread.h"
#include "test_macros.h"

int main(int, char**)
{
  std::barrier<> b(2);

  auto tok = b.arrive();
  std::thread t = support::make_test_thread([&](){
    (void)b.arrive();
  });
  b.wait(std::move(tok));
  t.join();

  auto tok2 = b.arrive(2);
  b.wait(std::move(tok2));
  return 0;
}
