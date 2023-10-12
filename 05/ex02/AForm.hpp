/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:36:09 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/09 15:46:44 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class ExecutorException : public std::exception {
			public:
				const char* what() const throw();
		};
		class IllegalFormException : public std::exception {
			public:
				const char* what() const throw();
		};
		AForm(std::string const & name, unsigned short int gS, unsigned short int gE);
		virtual ~AForm();
		std::string const & getName() const;
		unsigned short int getGs() const;
		unsigned short int getGe() const;
		virtual bool	getFormState() const;
		virtual void	execute(Bureaucrat const & executor) = 0;
		virtual void	beSigned(Bureaucrat const & b) = 0;
	private:
		std::string const & _name;
		bool _isSigned;
		unsigned short int _gradeForSigning;
		unsigned short int _gradeForExec;	
};

//std::ostream	&operator<<(std::ostream &outfile, AForm const &f);

#endif
