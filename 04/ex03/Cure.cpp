/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:32:10 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/04 11:14:26 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"

Cure::Cure( void ) : type("cure") {
	return ;
}

Cure::Cure(Cure const & src) {
	*this = src;
	return;
}

Cure & Cure operator=(Cure const & other) type("cure") {
	(void) other;
	return *this;
}

Cure::~Cure( void ) {
	return ;
}

AMateria*	Cure::clone()
{
	AMateria* clone = new Cure();
	return clone;
}

void		Cure::use(ICharacter& target)
{
	std::cout << "*Heals " << target->getName() << "'s wounds*" << std::endl;
	return ;
}
