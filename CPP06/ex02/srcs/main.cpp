#include "../includes/C.hpp"
#include "../includes/B.hpp"
#include "../includes/A.hpp"
#include "../includes/Base.hpp"


static Base    *generate(void)
{
    switch(rand() % 3)
    {
        case 0:
        {
            return (new A());
            break;
        }
        case 1:
        {
            return (new B());
            break;
        }
        case 2:
        {
            return (new C());
            break;
        }
        default:
        {
            std::cerr << "RNG Broke!" << std::endl;
            return NULL;
        }
    }
}

static void     identify(Base *check)
{
    if(dynamic_cast<A *>(check))
        std::cout << "Identified class type as A!" << std::endl;
    else if(dynamic_cast<B *>(check))
        std::cout << "Identified class type as A!" << std::endl;
    else if(dynamic_cast<C *>(check))
        std::cout << "Identified class type as A!" << std::endl;
    else
        std::cout << "Error! Unknown Type!?!?!?" << std::endl;
}

static void     identify(Base &check)
{
    try
    {
        A &a = dynamic_cast<A &>(check); // if this fails it throws a std::bad_cast
        (void)a;
        std::cout << "Successfully identified class type as A!" << std::endl;
    }
    catch (std::exception &e)
    {
    }
    try
    {
        B &b = dynamic_cast<B &>(check);
        (void)b;
        std::cout << "Successfully identified class type as B!" << std::endl;
    }
    catch (std::exception &e)
    {
    }
    try
    {
        C &c = dynamic_cast<C &>(check);
        (void)c;
        std::cout << "Successfully identified class type as C!" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
}

int main()
{
    srand(time(0));
    for(int i = 0; i < 5; i++)
    {
        Base *based = generate();
        if (based == NULL)
        {
            std::cerr << "Error generating Base Class!" << std::endl;
            return (1);
        }
        else
        {
            identify(based);
            identify(*based);
            delete(based);
            std::cout << std::endl;
        }
    }
    return (0);
}