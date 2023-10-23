#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const & target) : AForm("Presidential Pardon Form", 25, 5), _name(("PresidentalPardon_" + target).c_str()), _target(target) {
        std::cout << "A presidential pardon form was made for " << target << std::endl;
        _isSigned = false;
        _gradeForSigning = 25;
        _gradeForExec = 5;

        return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & copy) : AForm("Presidential Pardon Form", 25, 5), _name(copy._name), _target(copy._target) {
	return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & other) {
	_name = other._name;
	_target = other._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    return ;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	std::string exec_msg = _target + " has been pardoned by Zaphod Beeblebrox";
	if (_isSigned == false)
		throw AForm::IllegalFormException();
	if (executor.getGrade() <= _gradeForExec)
		std::cout << exec_msg << std::endl;
	else
		throw AForm::ExecutorException();
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

void    PresidentialPardonForm::setFormState(bool state) {
    _isSigned = state;
}