#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm(std::string const & target);
		~PresidentialPardonForm();
		std::string	getName();
		void	beSigned(Bureaucrat *b);
		bool	getFormState();
	private:
		std::string _name;
		bool _isSigned;
		unsigned short int _gradeForSigning;
		unsigned short int _gradeForExec;	
};

std::ostream	&operator<<(std::ostream &outfile, PresidentialPardonForm const &f);

#endif