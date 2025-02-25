#pragma once

#include <iostream>
#include <stack>


template <typename X>
class   MutantStack : public std::stack<X>
{
    public:
        MutantStack();
        MutantStack(const MutantStack &copy);
        MutantStack &operator=(const MutantStack &copy);
        ~MutantStack();

        typedef typename std::stack<X>::container_type::iterator iterator; // start 2 finish, can modify elemtns while going thru
        typedef typename std::stack<X>::container_type::const_iterator const_iterator; // cant modify elements while going thru
        typedef typename std::stack<X>::container_type::reverse_iterator reverse_iterator; // end to beginning, can modify
        typedef typename std::stack<X>::container_type::const_reverse_iterator const_reverse_iterator; // cant modify

        iterator begin();
        iterator end();

        const_iterator begin() const;
        const_iterator end() const;

        reverse_iterator rev_begin();
        reverse_iterator rev_end();
        
        const_reverse_iterator rev_begin() const;
        const_reverse_iterator rev_end() const;
};

#include "MutantStack.tpp"
