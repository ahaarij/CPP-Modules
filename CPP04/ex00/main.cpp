#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		// const WrongAnimal* j = new WrongCat();
		const Animal* i = new Cat();
		// std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		// j->makeSound();
		meta->makeSound();
		delete i;
		// delete j;
		delete meta;
	}
	std::cout << "----------------------------------" << std::endl;
	{
		const Animal* meta = new Animal();
		const Dog* j1 = new Dog();
		const Cat* i1 = new Cat();
		std::cout << j1->getType() << " " << std::endl;
		std::cout << i1->getType() << " " << std::endl;
		i1->makeSound(); //will output the cat sound!
		j1->makeSound();
		meta->makeSound();
		delete i1;
		delete j1;
		delete meta;
	}
}
