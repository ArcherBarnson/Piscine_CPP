/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:10:52 by bgrulois          #+#    #+#             */
/*   Updated: 2023/07/26 17:58:53 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) {
	return ;
}

Zombie::Zombie( std::string name ) : _name(name){
	std::cout << _name << " was spawned" << std::endl;
	return ;
}

Zombie::~Zombie( void ) {
	std::cout << this->_name << " was killed." << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->_name;
	std::cout <<  ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
