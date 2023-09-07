/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:32:10 by bgrulois          #+#    #+#             */
/*   Updated: 2023/09/07 16:52:38 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"

Character::Character( std::string name ) : _name(name) {
	return ;
}

Character::Character(Character const & src) {
	*this = src;
	return;
}

Character & Character operator=(Character const & other) {
	if (other != &src)
		_name = _name.other; //attention a ca
	return *this;
}

Character::~Character( void ) {
	return ;
}
