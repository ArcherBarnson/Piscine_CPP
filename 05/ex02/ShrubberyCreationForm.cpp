#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & name) : AForm(name, 145, 137), _name(name) {
        std::cout << "A shrubbery creation form " << _name << " was made" << std::endl;
        _isSigned = false;
        _gradeForSigning = 145;
        _gradeForExec = 137;
        return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    return ;
}

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw() {
	return ("Error: Grade too low, are you trying to forge a document ?");
}

void    ShrubberyCreationForm::beSigned(Bureaucrat *b)
{
    b->getGrade() <= _gradeForSigning ? _isSigned = 1 : std::cout << b->getName() << " could not sign form : grade too low exception (permission denied)" << std::endl;
    if (_isSigned == 0)
        throw ShrubberyCreationForm::GradeTooLowException();
    return ;
}