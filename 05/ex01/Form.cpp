/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:41:41 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/09 15:45:51 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string const & name, unsigned short int gS, unsigned short int gE) : 
    _name(name), _isSigned(0), _gradeForSigning(gS), _gradeForExec(gE) {
        std::cout << "A form " << _name << " was created - grade required to sign : "
            << _gradeForSigning << " or higher" << std::endl;
        return ;
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

bool    Form::getFormState() {
    return _isSigned;
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Error: Grade too low, are you trying to forge a document ?");
}

void    Form::beSigned(Bureaucrat *b)
{
    b->getGrade() <= _gradeForSigning ? _isSigned = 1 : std::cout << b->getName() << " could not sign form : grade too low exception (permission denied)" << std::endl;
    if (_isSigned == 0)
        throw Form::GradeTooLowException();
    return ;
}