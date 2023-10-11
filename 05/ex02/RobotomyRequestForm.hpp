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
		~RobotomyRequestForm();
		void	beSigned(Bureaucrat *b);
	private:
		std::string _name;
		bool _isSigned;
		unsigned short int _gradeForSigning;
		unsigned short int _gradeForExec;	
};

//std::ostream	&operator<<(std::ostream &outfile, RobotomyRequestForm const &f);

#endif