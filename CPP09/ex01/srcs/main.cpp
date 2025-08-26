#include "../includes/RPN.hpp"
#include <iomanip>

int main(int argc, char **argv)
{
    rpn obj;
    if(argc != 2)
    {
        std::cerr << "Error!\nUsage: ./RPN \"(Arguments)\"\n";
        exit(0);
    }
    else
    {
        try
        {
            obj.readInput(argv[1]);
        }
        catch(const std::exception &e)
        {
            std::cerr << e.what();
        }
    }
}