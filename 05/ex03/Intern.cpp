#include "Intern.hpp"

Intern::Intern(void) {
	return ;
}

Intern::Intern(Intern const & copy) {
	(void)copy;
	return ;
}

Intern & Intern::operator=(Intern const & other) {
	(void) other;
	return *this;
}

Intern::~Intern(void) {
	return ;
}

AForm*	Intern::makeForm(std::string formType, std::string target)
{
	int formId = -1;
	std::string formList[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	AForm*	(Intern::*forms[3]) (std::string &);

	forms[0] = &Intern::sForm;
	forms[1] = &Intern::rForm;
	forms[2] = &Intern::pForm;
	formType.compare(formList[0]) == 0 ? formId = 0:formId;
	formType.compare(formList[1]) == 0 ? formId = 1:formId;
	formType.compare(formList[2]) == 0 ? formId = 2:formId;
	if(formId == -1)
		throw InternIsDrunkException();
	else
		return (this->*forms[formId])(target);
	return NULL;
}

const char* Intern::InternIsDrunkException::what() const throw() {
	return ("Error: The intern is drunk, they tried making a form that doesn't exist...");
}

AForm*	Intern::sForm(std::string &target) {
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::rForm(std::string &target) {
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::pForm(std::string &target) {
	return (new PresidentialPardonForm(target));
}