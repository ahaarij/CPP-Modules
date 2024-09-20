#include "brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called!" << std::endl;
}

Brain::Brain(Brain const &copy)
{
	std::cout << "Brain copy constructor called!" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called!" << std::endl;
}
