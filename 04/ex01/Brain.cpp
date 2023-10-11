/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:04:09 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/11 16:39:27 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {
	int i;
	for (i = 0; i < 99; i++)
	{
		ideas[i] = "idea :|";
	}
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const & src) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
	return ;
}

Brain & Brain::operator=(Brain const & other) {
	int i;
	for (i = 0; i < 99; i++)
	{
		ideas[i] = other.ideas[i];
	}
	std::cout << "Brain assignement operator called" << std::endl;
	return *this;
}

Brain::~Brain( void ) {
	std::cout << "Brain destructor called" << std::endl;
}
