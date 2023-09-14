/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:23:36 by bgrulois          #+#    #+#             */
/*   Updated: 2023/09/13 16:11:52 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string const & name) : ClapTrap(name + ("_clap_name")), ScavTrap(name + ("_clap_name")), FragTrap(name + ("_clap_name")), _name(name) {
	std::cout << "DiamondTrap constructor called" << std::endl;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = 50;	//fuck this shit
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap const & src) : ClapTrap(src._name + "_clap_name"), ScavTrap(src._name), FragTrap(src._name), _name(src._name) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	return ;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & other) {
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
	std::cout << "DiamondTrap destructor called" << std::endl;
	return;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "child name : " << _name << std::endl;
	std::cout << "parent name : " << FragTrap::getName() << std::endl;
	//"proof";
	//std::cout << &_name << std::endl;
	//std::cout << &(ClapTrap::_name) << std::endl;
	//std::cout << ClapTrap::_name.length() << std::endl;
	//THEY ARE THE SAME, WHY ?
	return ;
}
