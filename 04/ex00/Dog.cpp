/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:04:09 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/12 13:43:07 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog( void ) {
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(Dog const & src) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
	return ;
}

Dog & Dog::operator=(Dog const & other) {
	std::cout << "Dog assignement operator called" << std::endl;
	type = other.type;
	return *this;
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "waf waf" << std::endl;
	return ;
}
