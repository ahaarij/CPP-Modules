#include "../includes/RPN.hpp"
#include <sstream>

rpn::rpn()
{
    ;
}

rpn::rpn(const rpn &copy)
{
    this->operator=(copy);
}

rpn::~rpn()
{
    ;
}

rpn     &rpn::operator=(const rpn &copy)
{
    (void)copy;
    return (*this);
}

int    rpn::CalcRes(int n1, int n2, char o)
{
    switch (o)
    {
        case '+':
            return (n1 + n2);
        case '/':
        {
            if(n1 == 0)
                throw std::invalid_argument("Dividing On Zero\n");
            return (n2 / n1);
        }
        case '*':
            return (n1 * n2);
        case '-':
            return (n2 - n1);
    }
    return (0);
}

void rpn::readInput(std::string input)
{
    while (!_numbers.empty())
        _numbers.pop();
    std::istringstream iss(input);
    std::string token;
    std::string operators = "+-*/";

    while (iss >> token)
    {
        if (token.length() == 1 && isdigit(token[0]))
        {
            _numbers.push(token[0] - '0'); // conv int
        }
        else if (token.length() == 1 && operators.find(token[0]) != std::string::npos)
        {
            if (_numbers.size() < 2)
                throw std::invalid_argument("Not enough operands for operator\n");

            int n1 = _numbers.top(); _numbers.pop();
            int n2 = _numbers.top(); _numbers.pop();

            int result = CalcRes(n1, n2, token[0]);
            _numbers.push(result);
        }
        else
        {
            throw std::invalid_argument("Invalid token: '" + token + "'\n");
        }
    }
    if (_numbers.size() != 1)
        throw std::invalid_argument("Invalid RPN expression\n");
    std::cout << _numbers.top() << std::endl;
}
