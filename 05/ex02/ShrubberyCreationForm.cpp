#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("Shrubbery Creation Form", 145, 137), _name(("Shrub.creat_" + target).c_str()) {
        std::cout << "A shrubbery creation form was made for " << target << std::endl;
        _isSigned = false;
        _gradeForSigning = 145;
        _gradeForExec = 137;
        std::ofstream out((target + "_shrubbery").c_str());
        out << "        ###     " << std::endl
            << "        #o###   " << std::endl
            << "     #####o###  " << std::endl
            << "    #o#\\||#/### " << std::endl
            << "     ###\\|/#o#  " << std::endl
            << "     # }|{  # " << std::endl;
        out.close();
        return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    return ;
}

std::string	ShrubberyCreationForm::getName()
{
	return _name;
}

bool	ShrubberyCreationForm::getFormState()
{
	return _isSigned;
}

void    ShrubberyCreationForm::beSigned(Bureaucrat *b)
{
    b->getGrade() <= _gradeForSigning ? _isSigned = 1 : std::cout << b->getName() << " could not sign form : grade too low exception (permission denied)" << std::endl;
    if (_isSigned == 0)
        throw AForm::GradeTooLowException();
	else
		std::cout << b->getName() << " signed Form " << _name << std::endl;
    return ;
}