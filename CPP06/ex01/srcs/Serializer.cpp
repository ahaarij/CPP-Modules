#include "../includes/Serializer.hpp"

Serializer::Serializer()
{
    // std::cout << "Serializer constructor called!" << std::endl;
    ;
}

Serializer::Serializer(const Serializer &copy)
{
    std::cout << "Serializer copy constructor called!" << std::endl;
    *this = copy;
}

Serializer::~Serializer()
{
    // std::cout << "Serializer destructor called!" << std::endl;
    ;
}

Serializer  &Serializer::operator=(const Serializer &copy)
{
    std::cout << "Serializer operator overload called!" << std::endl;
    if (this == &copy)
        return *this;
    return *this;
}

uintptr_t   Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data    *Serializer::unserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data*>(raw));
}

std::ostream &operator<<(std::ostream &c, const Data &copy)
{
    c << "Address: " << &copy << "\nName: " << copy.name <<"\nAge: " << copy.age << "\nNext: " << copy.next << std::endl;
    return (c);
}