#pragma once

#include <iostream>


template<typename T>
class   Span
{
    private:
        std::vector<int>    _v;
        unsigned int        _n;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &copy);
        Span &operator=(const Span &copy);
        ~Span();

        // members function

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        void    addNumber(std::vector<int>::iterator.begin(), std::vector<int>::iterator.end());
}