#pragma once

#include <iostream>
#include <string>

template <typename X>
void    swap(X &a, X &b)
{
    X temp;
    temp = a;
    a = b;
    b = temp;
}

template <typename Y>
const   Y &max(const Y &a, const Y &b)
{
    return(a >= b ? a : b);
}

template <typename Z>
const   Z &min(const Z &a, const Z &b)
{
    return(a <= b ? a : b);
}