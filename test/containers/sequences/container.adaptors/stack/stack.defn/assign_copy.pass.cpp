//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <stack>

// stack& operator=(const stack& q);

#include <stack>
#include <cassert>

template <class C>
C
make(int n)
{
    C c;
    for (int i = 0; i < n; ++i)
        c.push_back(i);
    return c;
}

int main()
{
    std::stack<int> q(make<std::deque<int> >(5));
    std::stack<int> q2;
    q2 = q;
    assert(q2 == q);
}
