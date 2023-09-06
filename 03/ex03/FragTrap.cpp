/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:56:45 by bgrulois          #+#    #+#             */
/*   Updated: 2023/09/06 10:57:18 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const & name) : ClapTrap(name) ,_name(name) {
	std::cout << "FragTrap default constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	return ;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src._name), _name(src._name) {
	std::cout << "FragTrap copy contructor called" << std::endl;
	*this = src;
	return ;
}

FragTrap & FragTrap::operator=(FragTrap const & other) {
	std::cout << "FragTrap assignement operator called" << std::endl;
	if (this != &other)
	{
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;	
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called" << std::endl;
	return ;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << _name << " : hey guyyyyys, gimme a HIIIIGH FIVE" << std::endl;
	return ;
}
