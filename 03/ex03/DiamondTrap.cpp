/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:23:36 by bgrulois          #+#    #+#             */
/*   Updated: 2023/09/06 13:55:34 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string const & name) : ClapTrap(name), ScavTrap(name), FragTrap(name), _name(name) {
	std::cout << "DiamondTrap constructor called" << std::endl;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(src._name), ScavTrap(src._name), FragTrap(src._name), _name(src._name) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	//*this = src;
	return ;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & other) {
	std::cout << "DiamondTrap assignement operator called" << std::endl;
	if (this != &other)
	{
		_hitPoints = other.FragTrap::_hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap( void ) {
	return;
}
