/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:04:09 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/12 13:44:07 by bgrulois         ###   ########.fr       */
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
	type = other.type;
	return *this;
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor called" << std::endl;
}

std::string const & Animal::getType() const
{
	return type;
}

void	Animal::makeSound() const
{
	std::cout << "Animal base class makeSound member called." << std::endl;
	return ;
}
