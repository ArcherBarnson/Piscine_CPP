#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("Presidential Pardon Form", 145, 137), _name(("Shrub.creat_" + target).c_str()), _target(target) {
        std::cout << "A presidential pardon form was made for " << target << std::endl;
        _isSigned = false;
        _gradeForSigning = 25;
        _gradeForExec = 5;

        return ;
}

void	PresidentialPardonForm::beSigned(Bureaucrat const & b) const
{
	b.getGrade() <= _gradeForSigning ? _isSigned = true : throw AForm::GradeTooLowException();
	return ;
}

void	PresidentialFormPardon::execute(Bureaucrat const & executor) const
{
	std::string exec_msg = _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	if (_isSigned == false)
		throw AForm::IllegalFormException();
	executor.getGrade() <= _gradeForExec ? std::cout << exec_msg << std::endl : throw AForm::ExecutorException();
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    return ;
}

std::string	PresidentialPardonForm::getName() {
	return _name;
}

std::string PresidentialPadronForm::targetGetName() {
	return _target;
}

bool	PresidentialPardonForm::getFormState()
{
	return _isSigned;
}