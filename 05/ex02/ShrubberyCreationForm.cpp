#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("Shrubbery Creation Form", 145, 137), _name(("Shrub.creat_" + target).c_str()), _target(target) {
        std::cout << "A shrubbery creation form was made for " << target << std::endl;
        _isSigned = false;
        _gradeForSigning = 145;
        _gradeForExec = 137;
        
        return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & copy) : AForm("Shrubbery Creation Form", 145, 137), _name(copy._name), _target(copy._target) {
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & other) {
	_name = other._name;
	_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    return ;
}

std::string	ShrubberyCreationForm::getName()
{
	return _name;
}

bool	ShrubberyCreationForm::getFormState() const
{
	return _isSigned;
}

void	ShrubberyCreationForm::setFormState(bool state)
{
	_isSigned = state;
	return ;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > _gradeForExec)
		throw AForm::ExecutorException();
	if (_isSigned == false)
		throw AForm::IllegalFormException();
	std::ofstream out((_target + "_shrubbery").c_str());
        out << "        ###     " << std::endl
            << "        #o###   " << std::endl
            << "     #####o###  " << std::endl
            << "    #o#\\||#/### " << std::endl
            << "     ###\\|/#o#  " << std::endl
            << "     # }|{  # " << std::endl << std::endl
			<< "---- I assure you this is a tree ----" << std::endl;
        out.close();
	return ;
}