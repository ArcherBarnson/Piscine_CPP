/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:04:09 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/11 16:44:03 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog( void ) {
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
	_brain = new Brain();
}

Dog::Dog(Dog const & src) {
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = NULL;
	*this = src;
	return ;
}

Dog & Dog::operator=(Dog const & other) {
	std::cout << "Dog assignement operator called" << std::endl;
	type = other.type;
	_brain = new Brain(*other._brain);
	return *this;
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void	Dog::makeSound() const
{
	std::cout << "waf waf" << std::endl;
	return ;
}
