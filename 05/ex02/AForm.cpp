/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:41:41 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/12 13:31:22 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string const & name, unsigned short int gS, unsigned short int gE) : 
    _name(name), _isSigned(0), _gradeForSigning(gS), _gradeForExec(gE) {
        std::cout << "A " << _name << " was created - grade required to sign : "
            << _gradeForSigning << " or higher" << std::endl;
        return ;
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

bool    AForm::getFormState() const {
    return _isSigned;
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