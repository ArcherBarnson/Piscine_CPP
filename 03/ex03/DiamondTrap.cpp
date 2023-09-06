/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:23:36 by bgrulois          #+#    #+#             */
/*   Updated: 2023/09/06 12:42:13 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string const & name) : ClapTrap(name), _name(name) {
	std::cout << "DiamondTrap constructor called" << std::endl;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string const & src) : ClapTrap(src._name), _name(src.name) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

DiamondTrap & DiamondTrap::operator=(std::string const & other) {
	std::cout << "DiamondTrap assignement operator called" << std::endl;
	if (this != &other)
	{
		_hitPoints = other.FragTrap::_hitPoints;
		_energyPoints = other.ScavTrap::_energyPoints;
		_attackDamage = other.FragTrap::_attackDamage;
	}
	return *this;
}

DiamondTrap::~DiamondTrap( void ) {
	return;
}
