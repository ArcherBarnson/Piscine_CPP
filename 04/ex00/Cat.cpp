/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:04:09 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/12 13:42:50 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat( void ) {
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(Cat const & src) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
	return ;
}

Cat & Cat::operator=(Cat const & other) {
	std::cout << "Cat assignement operator called" << std::endl;
	type = other.type;
	return *this;
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "miaou miaou" << std::endl;
	return ;
}
