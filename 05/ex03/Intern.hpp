#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
	class InternIsDrunkException : public std::exception {
			public:
				const char* what() const throw();
		};
		Intern(void);
		Intern(Intern const & copy);
		Intern &operator=(Intern const & other);
		~Intern(void);
		AForm* makeForm(std::string formType, std::string target);
	private:
		AForm *sForm(std::string &target);
		AForm *rForm(std::string &target);
		AForm *pForm(std::string &target);
};

#endif