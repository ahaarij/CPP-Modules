#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():Form("RobotomyRequestForm", 72, 45),_target("Aarij")
{
    std::cout << "Default constructor for RobotomyRequestForm called for " << this->getTarget() << "!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):Form("RobotomyRequestForm", 72, 45),_target(target)
{
    std::cout << "Constructor for RobotomyRequestForm called for " << this->getTarget() << "!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy):Form("RobotomyRequestForm", 72, 45),_target(copy.getTarget())
{
    std::cout << "Copy constructor for RobotomyRequestForm " << this->getTarget() << " called!" << std::endl;
    *this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if(this == &copy)
        return (*this);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor for RobotomyRequestForm " << this->getTarget() << " called!" << std::endl;
}

int RNG()
{
    int random = rand() % 100;
    return (random);
}

void    RobotomyRequestForm::execute(Bureaucrat const &copy) const
{
    int randomnum;
    if(copy.getGrade() > this->getExecGrade())
        throw(Bureaucrat::GradeTooLowException());
    else if(this->getisSignedboolean() == false)
        throw(Form::FormNotSignedException());
    else
    {
        if((randomnum = RNG()) % 2 == 0)
            std::cout << "BZZZZTTTTT!!" << std::endl << this->getTarget() << " is now a robot!" << std::endl;
        else
            std::cout << "BOOOOOOOMMMM!!" << std::endl << this->getTarget() << "'s Robotomy Failed! (What a loser haha)" << std::endl;
    }
}

std::string RobotomyRequestForm::getTarget(void)const
{
    return (this->_target);
}

std::ostream    &operator<<(std::ostream &c, RobotomyRequestForm &copy)
{
    c << "Form: " << copy.getName() << std::endl << "Sign Grade: " << copy.getGrade() << std::endl << "Exec Grade: " << copy.getExecGrade() << std::endl << "Is Signed: " << copy.getisSigned() << std::endl;
    return (c);
}
