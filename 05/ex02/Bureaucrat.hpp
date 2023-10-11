/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:53:58 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/11 15:15:46 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
	public:
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		Bureaucrat(std::string const & name, unsigned short int grade);
		~Bureaucrat(void);
		void	incrementGrade(void);
		void	decrementGrade(void);
		void	signForm(AForm *f);
		unsigned short int getGrade() const;
		std::string const & getName() const;
		executeForm(Form const & form);
	private:
		std::string const & _name;
		unsigned short int _grade;
};

std::ostream	&operator<<(std::ostream &outfile, Bureaucrat const &b);

#endif
