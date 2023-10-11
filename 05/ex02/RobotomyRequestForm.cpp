#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("Robotomy Request Form", 72, 45), _name(("Robo.request_" + target).c_str()) {
        std::cout << "A robotomy request form was made for " << target << std::endl;
        _isSigned = false;
        _gradeForSigning = 72;
        _gradeForExec = 25;
		srand(time(NULL));
		int success = rand() % 2;
		std::cout << "***Very uncomfortable drilling noises***" << std::endl;
		if (success)
			std::cout << target << " was successfully robotomised, i hope you're happy" << std::endl;
		else
			std::cout << "Robotomy on " << target << " failed terribly, now someone has to clean this up" << std::endl;
        return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    return ;
}

std::string RobotomyRequestForm::getName()
{
	return _name;
}

bool	RobotomyRequestForm::getFormState()
{
	return _isSigned;
}

void    RobotomyRequestForm::beSigned(Bureaucrat *b)
{
    b->getGrade() <= _gradeForSigning ? _isSigned = 1 : std::cout << b->getName() << " could not sign form : grade too low exception (permission denied)" << std::endl;
    if (_isSigned == 0)
        throw AForm::GradeTooLowException();
	else
		std::cout << b->getName() << " signed Form " << _name << std::endl;
    return ;
}