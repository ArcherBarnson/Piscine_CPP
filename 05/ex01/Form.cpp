/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:41:41 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/24 11:47:09 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const name, unsigned short int gS, unsigned short int gE) : 
    _name(name), _isSigned(0), _gradeForSigning(gS), _gradeForExec(gE) {
        if (_gradeForSigning < 1 || _gradeForExec < 1)
			throw Form::GradeTooHighException();
		if (_gradeForSigning > 150 || _gradeForExec > 150)
			throw Form::GradeTooLowException();
        return ;
}

Form::Form(Form const & copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeForSigning(copy._gradeForSigning), _gradeForExec(copy._gradeForExec) {
    return ;
}

Form & Form::operator=(Form const & other) {
    (void)other;
    return *this;
}

Form::~Form(void) {
    return ;
}

std::string const & Form::getName() const {
    return _name;
}

unsigned short int Form::getGs() const {
    return _gradeForSigning;
}

unsigned short int Form::getGe() const {
    return _gradeForExec;
}

void    Form::setFormState(bool state) {
    _isSigned = state;
}

bool    Form::getFormState() const {
    return _isSigned;
}

void	Form::beSigned(Bureaucrat const & b) 
{
	if (b.getGrade() <= _gradeForSigning)
		setFormState(true);
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Error: Grade out of range (too high)");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Error: Grade out of range (too low)");
}

const char* Form::ExecutorException::what() const throw() {
	return ("Error: Cannot execute form, are you habilitated or debilitated ?");
}

const char* Form::IllegalFormException::what() const throw() {
	return ("Error: Cannot execute an unsigned form, that would be treason !");
}

std::ostream	&operator<<(std::ostream &outfile, Form const &f)
{
	outfile << f.getName() << ", grade required|" << std::endl
        << "-For signing : " << f.getGs() << std::endl
        << "-For executing : " << f.getGe() << std::endl;
	return (outfile);
}
