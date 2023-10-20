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
		PresidentialPardonForm(PresidentialPardonForm const & copy);
		PresidentialPardonForm &operator=(PresidentialPardonForm const & other);
		~PresidentialPardonForm();
		std::string	getName() const;
		std::string targetGetName();
		void    setFormState(bool state);
		bool	getFormState() const;
		void	execute(Bureaucrat const & executor) const;
	private:
		std::string _name;
		std::string _target;
		bool _isSigned;
		unsigned short int _gradeForSigning;
		unsigned short int _gradeForExec;	
};

std::ostream	&operator<<(std::ostream &outfile, PresidentialPardonForm const &f);

#endif