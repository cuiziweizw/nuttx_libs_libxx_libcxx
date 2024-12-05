//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// UNSUPPORTED: no-threads
// UNSUPPORTED: c++03

// <future>

// class future<R>

// R future::get();
// R& future<R&>::get();
// void future<void>::get();

#include <future>
#include <cassert>

#include "make_test_thread.h"
#include "test_macros.h"

static void func1(std::promise<int> p)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    p.set_value(3);
}

static void func2(std::promise<int> p)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    p.set_exception(std::make_exception_ptr(3));
}

static int j = 0;

static void func3(std::promise<int&> p)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    j = 5;
    p.set_value(j);
}

static void func4(std::promise<int&> p)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    p.set_exception(std::make_exception_ptr(3.5));
}

static void func5(std::promise<void> p)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    p.set_value();
}

static void func6(std::promise<void> p)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    p.set_exception(std::make_exception_ptr('c'));
}

extern "C" int main(int, char**)
{
    {
        typedef int T;
        {
            std::promise<T> p;
            std::future<T> f = p.get_future();
            support::make_test_thread(func1, std::move(p)).detach();
            assert(f.valid());
            assert(f.get() == 3);
            assert(!f.valid());
        }
#ifndef TEST_HAS_NO_EXCEPTIONS
        {
            std::promise<T> p;
            std::future<T> f = p.get_future();
            support::make_test_thread(func2, std::move(p)).detach();
            try
            {
                assert(f.valid());
                assert(f.get() == 3);
                assert(false);
            }
            catch (int i)
            {
                assert(i == 3);
            }
            assert(!f.valid());
        }
#endif
    }
    {
        typedef int& T;
        {
            std::promise<T> p;
            std::future<T> f = p.get_future();
            support::make_test_thread(func3, std::move(p)).detach();
            assert(f.valid());
            assert(f.get() == 5);
            assert(!f.valid());
        }
#ifndef TEST_HAS_NO_EXCEPTIONS
        {
            std::promise<T> p;
            std::future<T> f = p.get_future();
            support::make_test_thread(func4, std::move(p)).detach();
            try
            {
                assert(f.valid());
                assert(f.get() == 3);
                assert(false);
            }
            catch (double i)
            {
                assert(i == 3.5);
            }
            assert(!f.valid());
        }
#endif
    }
    {
        typedef void T;
        {
            std::promise<T> p;
            std::future<T> f = p.get_future();
            support::make_test_thread(func5, std::move(p)).detach();
            assert(f.valid());
            f.get();
            assert(!f.valid());
        }
#ifndef TEST_HAS_NO_EXCEPTIONS
        {
            std::promise<T> p;
            std::future<T> f = p.get_future();
            support::make_test_thread(func6, std::move(p)).detach();
            try
            {
                assert(f.valid());
                f.get();
                assert(false);
            }
            catch (char i)
            {
                assert(i == 'c');
            }
            assert(!f.valid());
        }
#endif
    }

  return 0;
}
