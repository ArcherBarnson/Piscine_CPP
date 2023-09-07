/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:04:09 by bgrulois          #+#    #+#             */
/*   Updated: 2023/09/07 14:21:45 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("badbase") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
	return ;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & other) {
	std::cout << "WrongAnimal assignement operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void		WrongAnimal::makeSound() const
{
	if (this->getType().compare("badbase") == 0)
		std::cout << "this a base class but it's THE WRONG ONE" << std::endl;
	else if (this->getType().compare("WrongCat") == 0)
		std::cout << "***glitched out meow***" << std::endl;
	else
		std::cout << "Something went terribly wrong" << std::cout;
	return ;
}

std::string const & WrongAnimal::getType() const
{
	return type;
}
