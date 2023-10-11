#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("Robotomy Request Form", 72, 45), _name(("Robo.request_" + target).c_str()), _target(target) {
        std::cout << "A robotomy request form was made for " << target << std::endl;
        _isSigned = false;
        _gradeForSigning = 72;
        _gradeForExec = 25;	
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

void    RobotomyRequestForm::beSigned(Bureaucrat const & b)
{
    b.getGrade() <= _gradeForSigning ? _isSigned = 1 : std::cout << b.getName() << " could not sign form : grade too low exception (permission denied)" << std::endl;
    if (_isSigned == 0)
        throw AForm::GradeTooLowException();
	else
		std::cout << b.getName() << " signed Form " << _name << std::endl;
    return ;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	if (executor.getGrade() > _gradeForExec)
		throw AForm::ExecutorException();
	if (_isSigned == false)
		throw AForm::IllegalFormException();
	srand(time(NULL));
	int success = rand() % 2;
	std::cout << "***Very uncomfortable drilling noises***" << std::endl;
	if (success)
		std::cout << _target << " was successfully robotomised, i hope you're happy" << std::endl;
	else
		std::cout << "Robotomy on " << _target << " failed terribly, now someone has to clean this up" << std::endl;
	return ;
}