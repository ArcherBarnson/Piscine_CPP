#include "Fixed.hpp"

Fixed::Fixed( void ) {
	return ;
}

Fixed::Fixed(Fixed const & copy) {
	std::cout << "Copy contructor called" << std::endl;
	return ;
}

Fixed::Fixed& operator=(Fixed const & =) {
	std::cout << "Assignation operator called" << std::endl;
	return *this;
}

Fixed::~Fixed( void ) {
	return;
}
