/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:36:09 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/09 15:46:44 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const & copy);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const & other);
		~ShrubberyCreationForm();
		std::string	getName();
		std::string targetGetName();
		void	setFormState(bool state);
		bool	getFormState() const;
		void	execute(Bureaucrat const & executor) const;
	private:
		std::string _name;
		std::string _target;
		bool _isSigned;
		unsigned short int _gradeForSigning;
		unsigned short int _gradeForExec;	
};

std::ostream	&operator<<(std::ostream &outfile, ShrubberyCreationForm const &f);

#endif