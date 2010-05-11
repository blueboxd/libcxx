//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <ios>

// class ios_base

// void unsetf(fmtflags mask);

#include <ios>
#include <cassert>

class test
    : public std::ios
{
public:
    test()
    {
        init(0);
    }
};

int main()
{
    test t;
    assert(t.flags() == (test::skipws | test::dec));
    t.unsetf(test::dec | test::right);
    assert(t.flags() == test::skipws);
}
