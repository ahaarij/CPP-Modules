#pragma once

#include <iostream>
#include <stack>
#include <cstdlib>


class   rpn
{
    private:
        std::stack<int> _numbers;
    public:
        rpn();
        rpn(const rpn &copy);
        ~rpn();
        rpn &operator=(const rpn &copy);

        void    readInput(std::string input);
        int     CalcRes(int n1, int n2, char o);
};
