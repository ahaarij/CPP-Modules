#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

typedef struct Data
{
    std::string name;
    size_t      age;
    Data        *next;
}				Data;

class	Serializer
{
	private:
	public:
		Serializer();
		Serializer(const Serializer &copy);
		~Serializer();
		Serializer &operator=(const Serializer &copy);
		uintptr_t	serialize(Data *ptr);
		Data		*unserialize(uintptr_t raw);
};

std::ostream	&operator<<(std::ostream &c, const Data &copy);
