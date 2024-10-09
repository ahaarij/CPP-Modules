#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called!" << std::endl;
}

Brain::Brain(Brain const &copy)
{
	std::cout << "Brain copy constructor called!" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        this->_ideas[i] = copy._ideas[i];
    }
}

Brain &Brain::operator=(Brain const &copy)
{
	std::cout << "Brain Assignment overload called!" << std::endl;
	if(this != &copy)
	{
		for (int i = 0; i < 100; i++)
		{
			if (copy._ideas[i].length() > 0)
				this->_ideas[i] = copy._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called!" << std::endl;
}

const std::string Brain::getIdea(const size_t i)
{
	if(i < 100)
		return (this->_ideas[i]);
	else
		return ("I cant have those many ideas :(");
}

const std::string *Brain::getIdeaAddress(const size_t i)
{
	if (i < 100)
	{
		return &(this->_ideas[i]);
	}
	else
		return NULL;
}

void	Brain::setIdea(size_t i, std::string idea)
{
	if (i < 100)
		this->_ideas[i] = idea;
	std::cout << "Dont get too many ideas now pal!" << std::endl;
}
