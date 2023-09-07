/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:04:09 by bgrulois          #+#    #+#             */
/*   Updated: 2023/09/07 13:36:17 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : type("base") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const & src) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
	return ;
}

Animal & Animal::operator=(Animal const & other) {
	std::cout << "Animal assignement operator called" << std::endl;
	if (this != &other)
		type = other.type;
	return *this;
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor called" << std::endl;
}

void		Animal::makeSound() const
{
	if (this->getType().compare("Dog") == 0)
		std::cout << "waf waf" << std::endl;
	else if (this->getType().compare("Cat") == 0)
		std::cout << "meowww" << std::endl;
	else
		std::cout << "you are calling the base class" << std::endl;
	return ;
}

std::string const & Animal::getType() const
{
	return type;
}
