/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:32:10 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/04 17:26:32 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"

Cure::Cure( void ) : AMateria("cure") {
	return ;
}

Cure::Cure(Cure const & src) :  AMateria(src)  {
	*this = src;
	return;
}

Cure & Cure::operator=(Cure const & other) {
	(void)other;
	return *this;
}

Cure::~Cure( void ) {
	return ;
}

AMateria*	Cure::clone() const
{
	return (new Cure());
}

void		Cure::use(ICharacter& target)
{
	std::cout << "*Heals " << target.getName() << "'s wounds*" << std::endl;
	return ;
}
