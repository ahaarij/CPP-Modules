#include "../includes/Serializer.hpp"

int main()
{
    Data    ptr1;
    Data    ptr2;

    ptr2.name = "Pierce";
    ptr2.age = 23;
    ptr2.next = NULL;

    ptr1.name = "Aarij";
    ptr1.age = 19;
    ptr1.next = &ptr2;

    std::cout << ptr2 << std::endl;
    std::cout << ptr1 << std::endl;

    Serializer a;
    Data        *reserialized_res = a.unserialize(a.serialize(&ptr1));

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << std::endl << "After reserializing" << std::endl << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    std::cout << *reserialized_res << std::endl;;
    std::cout << ptr2;
}