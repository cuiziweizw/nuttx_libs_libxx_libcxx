//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <istream>

// pos_type tellg();

#include <istream>
#include <cassert>

#include "test_macros.h"

template <class CharT>
struct testbuf
    : public std::basic_streambuf<CharT>
{
    typedef std::basic_string<CharT> string_type;
    typedef std::basic_streambuf<CharT> base;
private:
    string_type str_;
public:

    testbuf() {}
    testbuf(const string_type& str)
        : str_(str)
    {
        base::setg(const_cast<CharT*>(str_.data()),
                   const_cast<CharT*>(str_.data()),
                   const_cast<CharT*>(str_.data()) + str_.size());
    }

    CharT* eback() const {return base::eback();}
    CharT* gptr() const {return base::gptr();}
    CharT* egptr() const {return base::egptr();}
protected:
    typename base::pos_type seekoff(typename base::off_type off,
                                    std::ios_base::seekdir way,
                                    std::ios_base::openmode which)
    {
        assert(off == 0);
        assert(way == std::ios_base::cur);
        assert(which == std::ios_base::in);
        return 5;
    }
};

extern "C" int main(int, char**)
{
    {
        testbuf<char> sb(" 123456789");
        std::istream is(&sb);
        assert(is.tellg() == 5);
    }
#ifndef TEST_HAS_NO_WIDE_CHARACTERS
    {
        testbuf<wchar_t> sb(L" 123456789");
        std::wistream is(&sb);
        assert(is.tellg() == 5);
    }
#endif

  return 0;
}
