/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:58:40 by bgrulois          #+#    #+#             */
/*   Updated: 2023/07/26 16:58:42 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : name(name){
	std::cout << name << " was spawned" << std::endl;
	return ;
}

Zombie::~Zombie( void ) {
	std::cout << this->name << " was killed." << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->name;
	std::cout <<  ": BraiiiiiiinnnzzzZ..." << std::endl;
}
