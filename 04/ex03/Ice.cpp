/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:32:10 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/04 11:14:22 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"

Ice::Ice( void ) : type("ice") {
	return ;
}

Ice::Ice(Ice const & src) {
	*this = src;
	return;
}

Ice & Ice operator=(Ice const & other) type("ice") {
	(void) other;
	return *this;
}

Ice::~Ice( void ) {
	return ;
}

//Amateria virtual functions impl

AMateria*	Ice::clone()
{
	AMateria* clone = new Ice();
	return clone;
}

void		Ice::use(ICharacter& target)
{
	std::cout << "*Shoots ice at " << target->getName() << "*" << std::endl;
	return ;
}
