#include "../includes/iter.hpp"

void    ft_tolower(char &arr)
{
    arr = std::tolower(static_cast<unsigned char>(arr));
}

void    ft_toupper(char &arr)
{
    arr = std::toupper(static_cast<unsigned char>(arr));
}

int main()
{
    char a[] = {'A', 'B', 'C'};
    std::cout << "Array Values\n" << "Array[0]: " << a[0] << "\nArray[1]: " << a[1] << "\nArray[2]: " << a[2] << std::endl << std::endl;

    std::cout << "Running ToLower! vvvvvv" << std::endl << std::endl;
    ::iter(a, sizeof(a) / sizeof(char), ft_tolower);

    std::cout << "Array Values\n" << "Array[0]: " << a[0] << "\nArray[1]: " << a[1] << "\nArray[2]: " << a[2] << std::endl << std::endl;

    std::cout << "Running ToUpper! vvvvvv" << std::endl << std::endl;
    ::iter(a, sizeof(a) / sizeof(char), ft_toupper);

    std::cout << "Array Values\n" << "Array[0]: " << a[0] << "\nArray[1]: " << a[1] << "\nArray[2]: " << a[2] << std::endl;
}