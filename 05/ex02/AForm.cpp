/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:41:41 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/24 14:45:49 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const name, unsigned short int gS, unsigned short int gE) : 
    _name(name), _isSigned(0), _gradeForSigning(gS), _gradeForExec(gE) {
		if (_gradeForSigning < 1 || _gradeForExec < 1)
			throw AForm::GradeTooHighException();
		if (_gradeForSigning > 150 || _gradeForExec > 150)
			throw AForm::GradeTooLowException();
        return ;
}

AForm::AForm(AForm const & copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeForSigning(copy._gradeForSigning), _gradeForExec(copy._gradeForExec) {
    return ;
}

AForm & AForm::operator=(AForm const & other) {
    (void)other;
    return *this;
}

AForm::~AForm(void) {
    return ;
}

std::string const & AForm::getName() const {
    return _name;
}

unsigned short int AForm::getGs() const {
    return _gradeForSigning;
}

unsigned short int AForm::getGe() const {
    return _gradeForExec;
}

void    AForm::setFormState(bool state) {
    _isSigned = state;
}

bool    AForm::getFormState() const {
    return _isSigned;
}

void	AForm::beSigned(Bureaucrat const & b) 
{
	if (b.getGrade() <= _gradeForSigning)
		setFormState(true);
	else
		throw AForm::IllegalFormException();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Error: Grade out of range (too high)");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Error: Grade out of range (too low)");
}

const char* AForm::ExecutorException::what() const throw() {
	return ("Error: Cannot execute form, are you habilitated or debilitated ?");
}

const char* AForm::IllegalFormException::what() const throw() {
	return ("Error: Cannot sign form, that would be treason !");
}

std::ostream	&operator<<(std::ostream &outfile, AForm const &f)
{
	outfile << f.getName() << ", grade required|" << std::endl
        << "-For signing : " << f.getGs() << std::endl
        << "-For executing : " << f.getGe() << std::endl;
	return (outfile);
}