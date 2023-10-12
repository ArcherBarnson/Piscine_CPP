/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:04:09 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/12 14:56:44 by bgrulois         ###   ########.fr       */
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
	for (i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[i];
	}
	std::cout << "Brain assignement operator called" << std::endl;
	return *this;
}

Brain::~Brain( void ) {
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i > 99)
		return ;
	ideas[i] = idea;
	return ;
}

std::string Brain::getIdea(int i)
{
	if (i < 0 || i > 99)
		return "Brainfuzz: Out of range";
	return ideas[i];
}
