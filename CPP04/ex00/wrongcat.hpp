#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "wronganimal.hpp"

class	wrongcat : public wronganimal
{
	public:
		wrongcat();
		wrongcat(const cat &copy);
		~wrongcat();
		wrongcat &operator=(const wrongcat &copy);
		void	makeSound() const;
}

#endif
