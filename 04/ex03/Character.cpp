/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:32:10 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/04 11:49:51 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"

Character::Character( void ) {
	return ;
}

Character::Character( std::string name ) : _name(name) {
	return ;
}

Character::Character(Character const & src) {
	*this = src;
	return ;
}

Character & Character operator=(Character const & other) {
	if (other != &src)
		_name = _name.other; //attention a ca
	return *this;
}

Character::~Character( void ) {
	return ;
}

std::string const & 	Character::getName() const
{
	return (_name);
}

void			Character::equip(AMateria* m)
{
	int	i = 0;
	while (i < 4)
	{
		if (!_inventory[i]);
		{
			_inventory[i] = m;
			return ;
		}
		i++;
	}
	std::cout << "No space in inventory !" << std::endl;
	return ;
}

void			Character::unequip(int idx)
{
	if (_invenory[idx])
		_inventory[idx] = NULL;
	else
		std::cout << "Cannot unequip empty slot (duh)" << std::cout;
	return ;
}

void			Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "You have no power here" << std::endl;
	return ;
}
