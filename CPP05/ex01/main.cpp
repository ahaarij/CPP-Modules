#include "Bureaucrat.hpp"

int main()
{
    std::cout << YELLOW << BOLD << UNDER << "Test 1: Testing NO Exceptions" << RESET << std::endl << std::endl;
    // test 1; blank constructor;
    {
        Bureaucrat *a = new Bureaucrat();
        std::cout << *a << std::endl;
        try
        {
            a->Increment();
        }
        catch(Bureaucrat::GradeTooHighException &e)
        {
            std::cerr << "+-------------------------------------------------------+" << std::endl;
            std::cerr << RED << "Incrementing grade of " << a->getName() << " failed!\nReason: " << BOLD << e.what() << RESET;
            std::cerr << "+-------------------------------------------------------+" << std::endl;

        }

        std::cout << *a << std::endl;
        
        try
        {
            a->Decrement();
        }
        catch(Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << "=-------------------------------------------------------=" << std::endl;
            std::cerr << RED << "Decrementing grade of " << a->getName() << " failed!\nReason: " << BOLD << e.what() << RESET;
            std::cerr << "=-------------------------------------------------------=" << std::endl;
        }

        std::cout << *a << std::endl;


        delete a;
    }

    std::cout << std::endl << std::endl << YELLOW << BOLD << UNDER << "Test 2: Testing GradeTooHighException" << RESET << std::endl << std::endl;

    // test 2;
    {
        Bureaucrat *a = new Bureaucrat(1);
        std::cout << *a << std::endl;
        try
        {
            a->Increment();
        }
        catch(Bureaucrat::GradeTooHighException &e)
        {
            std::cerr << "+-------------------------------------------------------+" << std::endl;
            std::cerr << RED << "Incrementing grade of " << a->getName() << " failed!\nReason: " << BOLD << e.what() << RESET;
            std::cerr << "+-------------------------------------------------------+" << std::endl;
        }

        std::cout << *a << std::endl;

        try
        {
            a->Decrement();
        }
        catch(Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << "=-------------------------------------------------------=" << std::endl;
            std::cerr << RED << "Decrementing grade of " << a->getName() << " failed!\nReason: " << BOLD << e.what() << RESET;
            std::cerr << "=-------------------------------------------------------=" << std::endl;   
        }

        std::cout << *a << std::endl;

        delete a;
    }

    std::cout << std::endl << std::endl << YELLOW << BOLD << UNDER << "Test 3: Testing GradeTooLowException" << RESET << std::endl << std::endl;

    //test 3;
    {
        Bureaucrat *a = new Bureaucrat(150);
        std::cout << *a << std::endl;
        try
        {
            a->Increment();
        }
        catch(Bureaucrat::GradeTooHighException &e)
        {
            std::cerr << "+-------------------------------------------------------+" << std::endl;
            std::cerr << RED << "Incrementing grade of " << a->getName() << " failed!\nReason: " << BOLD << e.what() << RESET;
            std::cerr << "+-------------------------------------------------------+" << std::endl;
        }

        std::cout << *a << std::endl;

        try
        {
            a->Decrement();
        }
        catch(Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << "=-------------------------------------------------------=" << std::endl;
            std::cerr << RED << "Decrementing grade of " << a->getName() << " failed!\nReason: " << BOLD << e.what() << RESET;
            std::cerr << "=-------------------------------------------------------=" << std::endl;   
        }

        std::cout << *a << std::endl;

        try
        {
            a->Decrement();
        }
        catch(Bureaucrat::GradeTooLowException &e)
        {
            std::cerr << "=-------------------------------------------------------=" << std::endl;
            std::cerr << RED << "Decrementing grade of " << a->getName() << " failed!\nReason: " << BOLD << e.what() << RESET;
            std::cerr << "=-------------------------------------------------------=" << std::endl;   
        }

        std::cout << *a << std::endl;

        delete a;
    }


}