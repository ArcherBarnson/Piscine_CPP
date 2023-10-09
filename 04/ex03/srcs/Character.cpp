/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:32:10 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/05 15:09:19 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) {
	int i;
	
	for (i = 0; i < 4; i++)
		_inventory[i] = NULL;
	return ;
}

Character::Character( std::string name ) : ICharacter(), _name(name) {
	int i;
	
	for (i = 0; i < 4; i++)
		_inventory[i] = NULL;
	return ;
}

Character::Character(Character const & src) {
	int i;
	for (i = 0; i < 4; i++)
		_inventory[i] = NULL;
	*this = src;
	return ;
}

Character & Character::operator=(Character const & other) {
	int i;
	for (i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
	for (i = 0; i < 4; i++)
		_inventory[i] = other._inventory[i]->clone();
	return *this;
}

Character::~Character( void ) {
	int i;
	for (i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
	return ;
}

std::string const & 	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	int	i = 0;
	while (i < 4)
	{
		if (!_inventory[i])
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
	if (idx > 3 || idx < 0)
		return ;
	if (_inventory[idx])
		_inventory[idx] = NULL;
	else
		std::cout << "Cannot unequip empty slot (duh)" << std::cout;
	return ;
}

void			Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && _inventory[idx] != NULL)
		_inventory[idx]->use(target);
	else
		std::cout << "You have no power here" << std::endl;
	return ;
}
