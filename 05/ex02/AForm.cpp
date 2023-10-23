/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:41:41 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/23 12:57:48 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const name, unsigned short int gS, unsigned short int gE) : 
    _name(name), _isSigned(0), _gradeForSigning(gS), _gradeForExec(gE) {
        //std::cout << "A " << _name << " was created - grade required to sign : "
        //    << _gradeForSigning << " or higher" << std::endl;
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
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Error: Grade too low, are you trying to forge a document ?");
}

const char* AForm::ExecutorException::what() const throw() {
	return ("Error: Cannot execute form, are you habilitated or debilitated ?");
}

const char* AForm::IllegalFormException::what() const throw() {
	return ("Error: Cannot execute an unsigned form, that would be treason !");
}