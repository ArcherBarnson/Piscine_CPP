/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 14:26:54 by bgrulois          #+#    #+#             */
/*   Updated: 2023/09/13 18:10:32 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const & name) : ClapTrap(name) ,_name(name) {
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src._name), _name(src._name) {
	std::cout << "ScavTrap copy contructor called" << std::endl;
	*this = src;
	return ;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & other) {
	std::cout << "ScavTrap assignement operator called" << std::endl;
	if (this != &other)
	{
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;	
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}

void	ScavTrap::attack(std::string &target)
{
	if (_energyPoints <= 0)
		std::cout << "ClapTrap " << _name << " cannot attack without energy points !" << std::endl;
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " cannot attack : they are dead !" << std::endl;
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target;
		std::cout << " causing " << _attackDamage << " points of damage !" << std::endl;
		ClapTrap(target).takeDamage(_attackDamage);
		_energyPoints--;
		std::cout << _name << " has " << _energyPoints << "ep left" << std::endl;
	}
	return ;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in GATEKEEPER mode" << std::endl;
	return ;
}
