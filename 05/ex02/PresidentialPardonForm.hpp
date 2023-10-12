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
		std::string targetGetName();
		bool	getFormState();
		void	execute(Bureaucrat const & executor) const;
		void	beSigned(Bureaucrat const & b) const;
	private:
		std::string _name;
		std::string _target;
		bool _isSigned;
		unsigned short int _gradeForSigning;
		unsigned short int _gradeForExec;	
};

std::ostream	&operator<<(std::ostream &outfile, PresidentialPardonForm const &f);

#endif