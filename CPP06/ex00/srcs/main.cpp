#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Enter a valid Value!" << std::endl << "'char' 'int' 'float' 'double'" << std::endl;
        return (1);
    }
    ScalarConverter::convert(argv[1]);
}
