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
	class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
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
		AForm(std::string const name, unsigned short int gS, unsigned short int gE);
		AForm(AForm const & copy);
		AForm &operator=(AForm const & other);
		virtual ~AForm();
		virtual void	setFormState(bool state);
		std::string const & getName() const;
		unsigned short int getGs() const;
		unsigned short int getGe() const;
		virtual bool	getFormState() const;
		virtual void	execute(Bureaucrat const & executor) const = 0;
		void	beSigned(Bureaucrat const & b);
	private:
		std::string const _name;
		bool _isSigned;
		const unsigned short int _gradeForSigning;
		const unsigned short int _gradeForExec;	
};

std::ostream	&operator<<(std::ostream &outfile, AForm const &f);

#endif
