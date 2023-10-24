/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:36:09 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/24 11:39:37 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
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
		Form(std::string const name, unsigned short int gS, unsigned short int gE);
		Form(Form const & copy);
		Form &operator=(Form const & other);
		virtual ~Form();
		virtual void	setFormState(bool state);
		std::string const & getName() const;
		unsigned short int getGs() const;
		unsigned short int getGe() const;
		virtual bool	getFormState() const;
		void	beSigned(Bureaucrat const & b);
	private:
		std::string const _name;
		bool _isSigned;
		const unsigned short int _gradeForSigning;
		const unsigned short int _gradeForExec;	
};

std::ostream	&operator<<(std::ostream &outfile, Form const &f);

#endif
