#ifndef CAT_HPP
# define CAT_HPP

#include "animal.hpp"
#include "brain.hpp"

class Cat : public Animal
{
	private:
		Brain *_brain;
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();
		Cat &operator=(const Cat &copy);
		void	makeSound() const;
		void	getIdeas() const;
		void	setIdea(size_t i, std::string idea);
};

#endif
