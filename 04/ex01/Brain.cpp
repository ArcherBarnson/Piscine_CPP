/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:04:09 by bgrulois          #+#    #+#             */
/*   Updated: 2023/09/07 14:51:10 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const & src) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
	return ;
}

Brain & Brain::operator=(Brain const & other) {
	(void)other;
	std::cout << "Brain assignement operator called" << std::endl;
	return *this;
}

Brain::~Brain( void ) {
	std::cout << "Brain destructor called" << std::endl;
}
