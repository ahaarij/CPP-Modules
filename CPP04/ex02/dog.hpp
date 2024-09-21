#ifndef DOG_HPP
# define DOG_HPP

#include "animal.hpp"
#include "brain.hpp"

class Dog : public Animal
{
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();
		Dog &operator=(const Dog &copy);
		void	makeSound() const;
		void	getIdeas() const;
		void	setIdea(size_t i, std::string idea);
};

#endif
