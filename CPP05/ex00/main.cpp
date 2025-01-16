#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat *a = new Bureaucrat();
    std::cout << *a;
    try
    {
        a->Increment();
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Incrementing grade of " << a->getName() << " failed!" <<
    }
    delete a;
}