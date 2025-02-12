#pragma once

#include <iostream>
#include <string>

template <typename X>

void    iter(X *array, size_t arr_len, void(*func)(X &))
{
    if(array == NULL || func == NULL)
        return ;
    for (size_t i = 0; i < arr_len; i++)
        func(array[i]);
}