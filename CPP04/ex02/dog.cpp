#include "dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called!" << std::endl;
	_type = "Dog";
	this->_brain = new Brain();
	if(!this->_brain)
	{
		std::cout << "Memory allocation failed!" << std::endl;
		exit (1);
	}
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor called!" << std::endl;
	_type = copy._type;
	_brain = new Brain(*copy._brain);
	if(!this->_brain)
	{
		std::cout << "Memory allocation failed!" << std::endl;
		exit (1);
	}
}

Dog &Dog::operator=(Dog const &copy)
{
    std::cout << "Dog Assignment overload called!" << std::endl;

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

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
	delete _brain;
}

void	Dog::makeSound() const
{
	std::cout << this->_type << " lets out a woof!" << std::endl;
}

void	Dog::getIdeas() const
{
	int i = 0;
	while(i < 3)
	{
		std::cout << "Dog idea number : " << i << " : '" << this->_brain->getIdea(i) << "' at address " << this->_brain->getIdeaAddress(i) << std::endl;
		i++;
	}
}

void	Dog::setIdea(size_t i, std::string idea)
{
	this->_brain->setIdea(i, idea);
}
