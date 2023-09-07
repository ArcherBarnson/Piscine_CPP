/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:32:10 by bgrulois          #+#    #+#             */
/*   Updated: 2023/09/07 16:36:27 by bgrulois         ###   ########.fr       */
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
