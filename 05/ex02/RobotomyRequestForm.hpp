#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(RobotomyRequestForm const & copy);
		RobotomyRequestForm &operator=(RobotomyRequestForm const & other);
		~RobotomyRequestForm();
		void	beSigned(Bureaucrat const & b);
		void	setFormState(bool state);
		bool	getFormState() const;
		std::string getName() const;
		std::string targetGetName() const;
		void	execute(Bureaucrat const & executor) const;
	private:
		std::string _name;
		std::string _target;
		bool _isSigned;
		unsigned short int _gradeForSigning;
		unsigned short int _gradeForExec;
};

std::ostream	&operator<<(std::ostream &outfile, RobotomyRequestForm const &f);

#endif