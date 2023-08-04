#include "Fixed.hpp"

const int Fixed::_raw = 8;

Fixed::Fixed( void ) : _fixed(0) {
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	setRawBits(n);
	return ;
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	setRawBits(n);
	return ;
}

Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy contructor called" << std::endl;
	_fixed = src.getRawBits();
	return ;
}

Fixed & Fixed::operator=( const Fixed & other) {
	std::cout << "Assignation operator called" << std::endl;
	this->_fixed = other.getRawBits();
	return *this;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _fixed;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixed = raw;
}

int	toInt( void ) const {
	return n;
}

float	toFloat( void ) const {
	return f;
}
