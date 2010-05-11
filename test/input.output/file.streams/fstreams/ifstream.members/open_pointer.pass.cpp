//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <fstream>

// template <class charT, class traits = char_traits<charT> >
// class basic_ifstream

// void open(const char* s, ios_base::openmode mode = ios_base::in);

#include <fstream>
#include <cassert>

int main()
{
    {
        std::ifstream fs;
        assert(!fs.is_open());
        char c = 'a';
        fs >> c;
        assert(fs.fail());
        assert(c == 'a');
        fs.open("test.dat");
        assert(fs.is_open());
        fs >> c;
        assert(c == 'r');
    }
    {
        std::wifstream fs;
        assert(!fs.is_open());
        wchar_t c = L'a';
        fs >> c;
        assert(fs.fail());
        assert(c == L'a');
        fs.open("test.dat");
        assert(fs.is_open());
        fs >> c;
        assert(c == L'r');
    }
}
