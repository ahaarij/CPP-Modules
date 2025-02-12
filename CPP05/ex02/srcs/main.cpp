#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"


void testBasicFormSigning()
{
    Bureaucrat *King = new Bureaucrat();
    Form *PresidentForm = new PresidentialPardonForm("Aarij");
    std::cout << std::endl;

    std::cout << *King << std::endl << *PresidentForm << std::endl;

    try
	{
        PresidentForm->beSigned(*King);
    }
	catch (Bureaucrat::GradeTooLowException &e)
	{
        std::cerr << King->getName() << " was not able to sign " << PresidentForm->getName() << ": " << e.what() << std::endl;
    }

    std::cout << *PresidentForm << std::endl;

    delete King;
    delete PresidentForm;
    std::cout << std::endl;
}

void testMultipleBureaucrats()
{
    Bureaucrat *Assistant = new Bureaucrat("Assistant", 145);
    Bureaucrat *CEO = new Bureaucrat("CEO", 1);
    Form *PresidentForm = new PresidentialPardonForm("Aarij");
    std::cout << std::endl;

    std::cout << *Assistant << std::endl << *CEO << std::endl << *PresidentForm << std::endl;

    try
	{
        PresidentForm->execute(*CEO);
    }
	catch (Form::FormNotSignedException &e)
	{
        std::cerr << Assistant->getName() << " was not able to execute the Form " << PresidentForm->getName() << ": " << e.what() << std::endl;
    }

    try
	{
        PresidentForm->beSigned(*Assistant);
    }
	catch (Bureaucrat::GradeTooLowException &e)
	{
        std::cerr << Assistant->getName() << " was not able to sign the Form " << PresidentForm->getName() << ": " << e.what() << std::endl;
    }

    std::cout << *PresidentForm << std::endl;
    try
	{
        PresidentForm->beSigned(*CEO);
    }
	catch (Bureaucrat::GradeTooLowException &e)
	{
        std::cerr << CEO->getName() << " was not able to sign the Form " << PresidentForm->getName() << ": " << e.what() << std::endl;
    }

    std::cout << *PresidentForm << std::endl;

    CEO->signForm(*PresidentForm);

    try
	{
        PresidentForm->execute(*Assistant);
    }
	catch (Bureaucrat::GradeTooLowException &e)
	{
        std::cerr << Assistant->getName() << " was not able to execute the Form " << PresidentForm->getName() << ": " << e.what() << std::endl;
    }

    try
	{
        PresidentForm->execute(*CEO);
    }
	catch (Bureaucrat::GradeTooLowException &e)
	{
        std::cerr << CEO->getName() << " was not able to execute the Form " << PresidentForm->getName() << ": " << e.what() << std::endl;
    }

    delete Assistant;
    delete CEO;
    delete PresidentForm;
    std::cout << std::endl;
}

void executeRobotomyTests()
{
    Bureaucrat *Nosferatu = new Bureaucrat("Nosferatu", 1);
    RobotomyRequestForm *Orlok = new RobotomyRequestForm("Orlok");
    std::cout << std::endl;

    std::cout << *Nosferatu << std::endl;
    std::cout << *Orlok << std::endl;
    Orlok->beSigned(*Nosferatu);
	srand(time(0));
    for (int i = 0; i < 10; i++)
	{
        try
		{
            Orlok->execute(*Nosferatu);
        }
		catch (std::exception &e)
		{
            std::cerr << "Execution failed: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;

    delete Nosferatu;
    delete Orlok;
    std::cout << std::endl;
}

void executeShrubberyTests()
{
    Bureaucrat *Grinch = new Bureaucrat("Grinch", 1);
    ShrubberyCreationForm *Christmas = new ShrubberyCreationForm("Christmas");
    std::cout << std::endl;

    std::cout << *Grinch << std::endl;
    std::cout << *Christmas << std::endl;
    Christmas->beSigned(*Grinch);

    try
	{
        Christmas->execute(*Grinch);
    }
	catch (std::exception &e)
	{
        std::cerr << "Execution failed: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    delete Grinch;
    delete Christmas;
    std::cout << std::endl;
}

int	main()
{
    testBasicFormSigning();
    std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
    testMultipleBureaucrats();
    std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	executeRobotomyTests();
    std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
	executeShrubberyTests();
    std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
    return 0;
}