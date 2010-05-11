//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <forward_list>

// void sort();

#include <forward_list>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cassert>

void test(int N)
{
    typedef int T;
    typedef std::forward_list<T> C;
    typedef std::vector<T> V;
    V v;
    for (int i = 0; i < N; ++i)
        v.push_back(i);
    std::random_shuffle(v.begin(), v.end());
    C c(v.begin(), v.end());
    c.sort();
    assert(distance(c.begin(), c.end()) == N);
    C::const_iterator j = c.begin();
    for (int i = 0; i < N; ++i, ++j)
        assert(*j == i);
}

int main()
{
    for (int i = 0; i < 40; ++i)
        test(i);
}
