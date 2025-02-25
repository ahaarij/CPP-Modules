#include "../includes/Span.hpp"

Span::Span(): _n(0)
{
    ;
}

Span::Span(unsigned int n): _n(n)
{
    ;
}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span    &Span::operator=(const Span &copy)
{
    if(this != &copy)
    {
        this->_n = copy._n;
        this->_v = copy._v;
    }
    return (*this);
}

Span::~Span()
{
    ;
}

void    Span::addNumber(int n)
{
    if(_v.size() >= _n)
        throw   ContainerFullException();
    _v.push_back(n);
}

int Span::shortestSpan()
{
    if(_v.size() <= 1)
        throw NotEnoughNumbersException();
    std::vector<int> temp = _v;
    std::sort(temp.begin(), temp.end());
    int min = temp[1] - temp[0];
    for(unsigned int i = 1; i < temp.size(); i++)
    {
        if(temp[i] - temp[i - 1] < min)
            min = temp[i] - temp[i - 1];
    }
    return (min);
}

int Span::longestSpan()
{
    if(_v.size() <= 1)
        throw NotEnoughNumbersException();
    std::vector<int> temp = _v;
    std::sort(temp.begin(), temp.end());
    return (temp[temp.size() - 1] - temp[0]);
}

void    Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if(_v.size() + std::distance(begin, end) > _n)
        throw ContainerFullException();
    _v.insert(_v.end(), begin, end);
}

const char *Span::ContainerFullException::what() const throw()
{
    return ("Container is full!");
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
    return ("Not enough numbers in container!");
}
