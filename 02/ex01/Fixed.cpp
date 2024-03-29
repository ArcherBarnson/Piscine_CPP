/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:17:54 by bgrulois          #+#    #+#             */
/*   Updated: 2023/08/08 18:17:55 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_raw = 8;

Fixed::Fixed( void ) : _fixed(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	_fixed = n << 8;
	return ;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	_fixed = roundf(f * (1 << _raw));
	return ;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy contructor called" << std::endl;
	*this = src;
	return ;
}

Fixed & Fixed::operator=( const Fixed & other) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
		_fixed = other.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &outfile, Fixed const & fixed) {
	outfile << fixed.toFloat();
	return (outfile);
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Fixed::getRawBits( void ) const {
	//std::cout << "getRawBits member function called" << std::endl;
	return _fixed;
}

void	Fixed::setRawBits(int const raw) {
	//std::cout << "setRawBits member function called" << std::endl;
	_fixed = raw;
}

int	Fixed::toInt( void ) const {	//fixed to int
	return (_fixed >> _raw);
}

float	Fixed::toFloat( void ) const {	//fixed to float
	return (float)_fixed / (float)(1 << _raw);
}
