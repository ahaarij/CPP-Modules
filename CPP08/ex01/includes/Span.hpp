#pragma once

#include <iostream>
#include <exception>
#include <vector>

class   Span
{
    private:
        std::vector<int>    _v;
        unsigned int        _n;
    public:
        Span();
        ~Span();
        Span(unsigned int n);
        Span(const Span &copy);
        Span &operator=(const Span &copy);

        // members function

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        void    addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

        class ContainerFullException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class NotEnoughNumbersException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};
