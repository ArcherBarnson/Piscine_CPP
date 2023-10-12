#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("Presidential Pardon Form", 145, 137), _name(("PresidentalPardon_" + target).c_str()), _target(target) {
        std::cout << "A presidential pardon form was made for " << target << std::endl;
        _isSigned = false;
        _gradeForSigning = 25;
        _gradeForExec = 5;

        return ;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	std::string exec_msg = _target + " has been pardoned by Zaphod Beeblebrox";
	if (_isSigned == false)
		throw AForm::IllegalFormException();
	//executor.getGrade() >= _gradeForExec ? std::cout << exec_msg << std::endl; : throw AForm::ExecutorException();
	if (executor.getGrade() <= _gradeForExec)
	{
		std::cout << "EH OH" << std::endl;
		std::cout << exec_msg << std::endl;
	}
	else
	{
		std::cout << "va te faire" << std::endl;
		throw AForm::ExecutorException();
	}
	std::cout << "hello ?" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    return ;
}

std::string	PresidentialPardonForm::getName() const {
	return _name;
}

std::string PresidentialPardonForm::targetGetName() {
	return _target;
}

bool	PresidentialPardonForm::getFormState() const
{
	return _isSigned;
}