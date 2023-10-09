/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:53:58 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/09 15:19:29 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

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
		unsigned short int getGrade() const;
		std::string const & getName() const;
	private:
		std::string const & _name;
		unsigned short int _grade;
};

std::ostream	&operator<<(std::ostream &outfile, Bureaucrat const &b);

#endif
