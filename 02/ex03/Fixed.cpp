/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:47:19 by bgrulois          #+#    #+#             */
/*   Updated: 2023/08/08 18:17:34 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_raw = 8;

Fixed::Fixed( void ) : _fixed(0) {
	//std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int n) {
	//std::cout << "Int constructor called" << std::endl;
	_fixed = n << 8;
	return ;
}

Fixed::Fixed(const float f) {
	//std::cout << "Float constructor called" << std::endl;
	_fixed = roundf(f * (1 << _raw));
	return ;
}

Fixed::Fixed(Fixed const &src) {
	//std::cout << "Copy contructor called" << std::endl;
	*this = src;
	return ;
}

Fixed & Fixed::operator=( const Fixed & other) {
	//std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
		_fixed = other.getRawBits();
	return *this;
}

bool 	Fixed::operator==(const Fixed & other) {
	return (_fixed == other.getRawBits());
}

bool 	Fixed::operator!=(const Fixed & other) {
	return (_fixed != other.getRawBits());
}

bool 	Fixed::operator>=(const Fixed & other) {
	return (_fixed >= other.getRawBits());
}

bool 	Fixed::operator<=(const Fixed & other) {
	return (_fixed <= other.getRawBits());
}

bool 	Fixed::operator>(const Fixed & other) {
	return (_fixed > other.getRawBits());
}

bool 	Fixed::operator<(const Fixed & other) {
	return (_fixed < other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed & other) {
	Fixed res;
	res.setRawBits(_fixed + other.getRawBits());
	return res;
}

Fixed	Fixed::operator-(const Fixed & other) {
	Fixed res;
	res.setRawBits(_fixed - other.getRawBits());
	return res;
}

Fixed	Fixed::operator*(const Fixed & other) {
	Fixed res(toFloat() * other.toFloat());
	return res;
}

Fixed	Fixed::operator/(const Fixed & other) {
	Fixed res;
	res.setRawBits(_fixed / other.getRawBits());
	return res;
}

Fixed::~Fixed( void ) {
	//std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed	&Fixed::operator++(void) {
	++_fixed;
	return *this;
}

Fixed	&Fixed::operator--(void) {
	--_fixed;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed tmp;
	tmp._fixed = _fixed++;
	return tmp;
}

Fixed	Fixed::operator--(int) {
	Fixed tmp;
	tmp._fixed = _fixed--;
	return tmp;
}

Fixed	Fixed::min(Fixed & f1, Fixed & f2) {
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	else
		return (f2);
}

Fixed	Fixed::min(const Fixed & f1, const Fixed & f2) {
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	else
		return (f2);
}

Fixed	Fixed::max(Fixed & f1, Fixed & f2) {
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	else
		return (f2);
}

Fixed	Fixed::max(const Fixed & f1, const Fixed & f2) {
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	else
		return (f2);
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


std::ostream	&operator<<(std::ostream &outfile, Fixed const & fixed) {
	outfile << fixed.toFloat();
	return (outfile);
}

