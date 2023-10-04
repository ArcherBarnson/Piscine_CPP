/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:32:10 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/04 16:10:02 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {
	return ;
}

Ice::Ice(Ice const & src) : AMateria(src) {
	*this = src;
	return;
}

Ice & Ice::operator=(Ice const & other) {
	(void) other;
	return *this;
}

Ice::~Ice( void ) {
	return ;
}

//Amateria virtual functions impl

AMateria*	Ice::clone() const
{
	return (new Ice());
}

void		Ice::use(ICharacter& target)
{
	std::cout << "*Shoots ice at " << target.getName() << "*" << std::endl;
	return ;
}
