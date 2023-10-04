/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:13:09 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/04 12:22:51 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : type("default") {
	return ;
}

AMateria::AMateria(std::string const & type) : type(type) {
	return ;
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
	return ;
}

AMateria & AMateria::operator=(AMateria const & other) {
	if (this != &other)
		type = other.type;
	return *this;
}

AMateria::~AMateria( void ) {
	std::cout << "AMateria pure virtual destructor called." << std::endl;
	return ;
}

std::string const & AMateria::getType() const {
	return (type);
}
