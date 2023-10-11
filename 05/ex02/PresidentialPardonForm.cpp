#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("Presidential Pardon Form", 145, 137), _name(("Shrub.creat_" + target).c_str()) {
        std::cout << "A presidential pardon form was made for " << target << std::endl;
        _isSigned = false;
        _gradeForSigning = 25;
        _gradeForExec = 5;
		std::cout << target << " was pardoned by Zaphod Beeblebox" << std::endl;
        return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    return ;
}

std::string	PresidentialPardonForm::getName()
{
	return _name;
}

bool	PresidentialPardonForm::getFormState()
{
	return _isSigned;
}

void    PresidentialPardonForm::beSigned(Bureaucrat *b)
{
    b->getGrade() <= _gradeForSigning ? _isSigned = 1 : std::cout << b->getName() << " could not sign form : grade too low exception (permission denied)" << std::endl;
    if (_isSigned == 0)
        throw AForm::GradeTooLowException();
	else
		std::cout << b->getName() << " signed Form " << _name << std::endl;
    return ;
}