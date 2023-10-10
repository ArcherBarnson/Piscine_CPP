/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:36:09 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/09 15:46:44 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		Form(std::string const & name, unsigned short int gS, unsigned short int gE);
		~Form();
		std::string const & getName() const;
		unsigned short int getGs() const;
		unsigned short int getGe() const;
		bool	getFormState();
		void	beSigned(Bureaucrat b);
	private:
		std::string const & _name;
		bool _isSigned;
		unsigned short int _gradeForSigning;
		unsigned short int _gradeForExec;	
};

std::ostream	&operator<<(std::ostream &outfile, Form const &f);

#endif
