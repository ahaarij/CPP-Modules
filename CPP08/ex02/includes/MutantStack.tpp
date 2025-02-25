#include "MutantStack.hpp"

template <typename X>
MutantStack<X>::MutantStack(): std::stack<X>()
{
	;
}

template <typename X>
MutantStack<X>::MutantStack(const MutantStack &copy) : std::stack<X>(copy)
{
	;
}

template <typename X>
MutantStack<X> &MutantStack<X>::operator=(const MutantStack &copy)
{
	if (this != copy)
		std::stack<X>::operator=(copy);
	return (*this);
}

template <typename X>
MutantStack<X>::~MutantStack()
{
	;
}

template <typename X>
typename MutantStack<X>::iterator   MutantStack<X>::begin()
{
	return(std::stack<X>::c.begin());
}

template <typename X>
typename MutantStack<X>::iterator   MutantStack<X>::end()
{
	return(std::stack<X>::c.end());
}

template <typename X>
typename MutantStack<X>::const_iterator   MutantStack<X>::begin() const
{
    return(std::stack<X>::c.begin());
}

template <typename X>
typename MutantStack<X>::const_iterator   MutantStack<X>::end() const
{
    return(std::stack<X>::c.end());
}

template <typename X>
typename MutantStack<X>::reverse_iterator   MutantStack<X>::rev_begin()
{
    return(std::stack<X>::c.rbegin());
}

template <typename X>
typename MutantStack<X>::reverse_iterator   MutantStack<X>::rev_end()
{
    return(std::stack<X>::c.rend());
}

template <typename X>
typename MutantStack<X>::const_reverse_iterator   MutantStack<X>::rev_begin() const
{
	return(std::stack<X>::c.rbegin());
}

template <typename X>
typename MutantStack<X>::const_reverse_iterator   MutantStack<X>::rev_end() const
{
	return(std::stack<X>::c.rend());
}