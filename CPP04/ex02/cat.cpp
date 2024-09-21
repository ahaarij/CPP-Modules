#include "cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor called!" << std::endl;
	_type = "Cat";
	this->_brain = new Brain();
	if(!this->_brain)
	{
		std::cout << "Memory allocation failed!" << std::endl;
		exit (1);
	}
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor called!" << std::endl;
	_type = copy._type;
	_brain = new Brain(*copy._brain);
	if(!this->_brain)
	{
		std::cout << "Memory allocation failed!" << std::endl;
		exit (1);
	}
}

Cat &Cat::operator=(Cat const &copy)
{
    std::cout << "Cat Assignment overload called!" << std::endl;

    if (this != &copy)
    {
        _type = copy._type;
        delete _brain;
        _brain = new Brain(*copy._brain);
        if (!_brain)
        {
            std::cout << "Memory allocation failed!" << std::endl;
            exit(1);
        }
    }
	_brain = new Brain(*copy._brain);
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
	delete _brain;
}

void	Cat::makeSound() const
{
	std::cout << this->_type << " lets out a meow!" << std::endl;
}

void	Cat::getIdeas() const
{
	int i = 0;
	while(i < 3)
	{
		std::cout << "Cat idea number : " << i << " : '" << this->_brain->getIdea(i) << "' at address " << this->_brain->getIdeaAddress(i) << std::endl;
		i++;
	}
}

void	Cat::setIdea(size_t i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}
