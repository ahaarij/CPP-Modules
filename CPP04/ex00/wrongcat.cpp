#include "wrongcat.hpp"

wrongcat::wrongcat()
{
	std::cout << "Wrongcat Constructor called!" << std::endl;
	_type = "wrongcat";
}

wrongcat::wrongcat(const wrongcat &copy)
{
	std::cout << "wrongcat copy constructor called!" << std::endl;
	operator=(copy);
}

wrongcat &wrongcat::operator=(wrongcat const &copy)
{
	std::cout << ""
}
