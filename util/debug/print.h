#pragma once

#include <cstdarg>
#include <iostream>

static void print(){}

template<typename T, typename... Args>
static void print(const T& head, const Args&... tail)
{
    std::cout << head;
    print(tail...);
}
