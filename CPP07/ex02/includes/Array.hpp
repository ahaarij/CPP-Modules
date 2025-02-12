#pragma once

#include <iostream>
#include <string>

template <typename X>

class   Array
{
    private:
        X   *_array;
        unsigned int    _size;
    public:
        Array():_size(0)
        {
            std::cout << "Default Constructor Called! Array size is (0)!" << std::endl;
            this->_array = new X[this->_size];
        }
        ~Array()
        {
            if(this->_array != NULL)
                delete [] this->_array;
        }
        Array(unsigned int n):_size(n)
        {
            std::cout << "Constructor Called! Array size is (" << n << ")!" << std::endl;
            this->_array = new X[this->_size];
        }
        Array(const Array &copy): _size(copy.size())
        {
            std::cout << "Copy Constructor Called!" << std::endl;
            this->_array = NULL;
            *this = copy;
        }
        Array &operator=(const Array &copy)
        {
            if (this->_array != NULL)
                delete [] this->_array;
            if (copy.size() != 0)
            {
                this->_size = copy.size();
                this->_array = new X[this->_size];
                for (unsigned int i = 0; i < this->_size; i++)
                    this->_array[i] = copy._array[i];
            }
            return (*this);
        }
        X &operator[](unsigned int index)
        {
            if(index >= this->_size || this->_array == NULL)
            {
                std::cout << "Index: " << index << std::endl;
                throw Array<X>::InvalidIndexException();
            }
            return (this->_array[index]);
        }
        unsigned int    size() const
        {
            return (this->_size);
        }
        class   InvalidIndexException : public std::exception
        {
            public:
                virtual const char  *what() const throw();
        };
};

template <typename X>
const char    *Array<X>::InvalidIndexException::what() const throw()
{
    return ("Error: Invalid Index!\n");
}
