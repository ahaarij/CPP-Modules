#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"

void	testInternForms()
{
	Bureaucrat *Boss = new Bureaucrat();
	Intern *Aarij = new Intern();

	Form *idk = Aarij->makeForm("PresidentialPardonForm", "Chris Martin");
	std::cout << "testing" << std::endl;

	std::cout << *Boss << std::endl;
	std::cout << *idk << std::endl;

	try
	{
		idk->beSigned(*Boss);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << Boss->getName() << " was not able to sign "  << idk->getName() << ": " << e.what() << std::endl;
	}

	std::cout << std::endl << *idk << std::endl;
	delete Boss;
	delete Aarij;
	delete idk;
	std::cout << std::endl;
}

void testBureaucrat()
{
    Bureaucrat *Assistant = new Bureaucrat("Assistant", 145);
    Bureaucrat *CEO = new Bureaucrat("CEO", 1);
    Form *PresidentForm = new PresidentialPardonForm("Aarij");

    std::cout << *Assistant << std::endl << *CEO << std::endl << *PresidentForm << std::endl;

    try
	{
        PresidentForm->execute(*CEO);
    }
	catch (Form::FormNotSignedException &e)
	{
        std::cerr << Assistant->getName() << " was not able to execute the Form " << PresidentForm->getName() << ": " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try
	{
        PresidentForm->beSigned(*Assistant);
    }
	catch (Bureaucrat::GradeTooLowException &e)
	{
        std::cerr << Assistant->getName() << " was not able to sign the Form " << PresidentForm->getName() << ": " << e.what() << std::endl;
    }

    std::cout << std::endl << *PresidentForm << std::endl;

    CEO->signForm(*PresidentForm);
    std::cout << std::endl;

    try
	{
        PresidentForm->execute(*Assistant);
    }
	catch (Bureaucrat::GradeTooLowException &e)
	{
        std::cerr << Assistant->getName() << " was not able to execute the Form " << PresidentForm->getName() << ": " << e.what() << std::endl;
    }

    std::cout << std::endl;

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

void testMultipleForms()
{
    Bureaucrat *Izzy = new Bureaucrat("KingIzzy", 1);
    Intern *Noob = new Intern();

    Form *RobotReq = Noob->makeForm("RobotomyRequestForm", "Bender");
    Form *ShrubCreate = Noob->makeForm("ShrubberyCreationForm", "Christmas");
    std::cout << std::endl;

    std::cout << *Izzy << std::endl << *RobotReq << std::endl << *ShrubCreate << std::endl << std::endl;

    RobotReq->beSigned(*Izzy);
    Izzy->signForm(*ShrubCreate);
    std::cout << std::endl << *RobotReq << std::endl << *ShrubCreate << std::endl;

	srand(time(0));
    for (int i = 0; i < 10; i++)
        RobotReq->execute(*Izzy);

    Izzy->executeForm(*ShrubCreate);
    std::cout << std::endl;

    delete Izzy;
    delete Noob;
    delete RobotReq;
    delete ShrubCreate;
    std::cout << std::endl;
}

int	main()
{
	testInternForms();
    std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
    
    testBureaucrat();
    std::cout << "--------------------------------------------------------------------------------------------------------------" << std::endl;
    
    testMultipleForms();
}