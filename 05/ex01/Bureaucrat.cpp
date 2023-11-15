/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:02:23 by bgrulois          #+#    #+#             */
/*   Updated: 2023/11/15 10:46:41 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const & name, unsigned short int grade) : _name(name), _grade(grade) {
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		std::cout << "A bureaucrat " << _name << " of grade " << _grade << " was created (bureaucrat grade contructor called)" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & copy) : _name(copy._name), _grade(copy._grade) {
	return ;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & other) {
	(void) other;
	return *this;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat default destructor called" << std::endl;
	return ;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		std::cout << "Cannot increment grade, bureaucrat is aleady exploiting eveyone else" << std::endl;
	else
	{
		std::cout << "Incrementing grade of " << *this << std::endl;
		_grade--;
		std::cout << *this << std::endl;
	}
	return ;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		std::cout << "Cannot decrement grade, bureaucrat is already down on the ground and starving" << std::endl;
	else
	{
		std::cout << "Decrementing grade of " << *this << std::endl;
		_grade++;
		std::cout << *this << std::endl;
	}
	return ;
}

std::string const &	Bureaucrat::getName() const {
	return _name;
}

unsigned short int	Bureaucrat::getGrade() const {
	return _grade;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Error: Grade too low (must be 150 or higher)");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Error: Grade too high (must be 1 or lower)");
}

void	Bureaucrat::signForm(Form &form)
{
	if (form.getFormState() == true)
	{
		std::cout << form.getName() << " is already signed ! What are you doing ?" << std::endl;
		return ;
	}
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " could not sign " << form.getName() << " -> " << e.what() << std::endl;
	}
	return ;
}

std::ostream	&operator<<(std::ostream &outfile, Bureaucrat const &b)
{
	outfile << b.getName() << ", bureaucrat grade : " << b.getGrade();
	return (outfile);
}
