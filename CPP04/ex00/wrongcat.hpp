#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "wronganimal.hpp"

class	Wrongcat : public Wronganimal
{
	public:
		Wrongcat();
		Wrongcat(const Wrongcat &copy);
		~Wrongcat();
		Wrongcat &operator=(const Wrongcat &copy);
		void	makeSound() const;
};

#endif
