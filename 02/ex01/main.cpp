#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	std::cout << "DEFAULT :: ";
	Fixed a;
	std::cout << "INT :: ";
	Fixed const b( 10 );
	std::cout << "FLOAT :: ";
	Fixed const c( 42.42f );
	std::cout << "COPY :: ";
	Fixed const d( b );
	std::cout << "ASSIGN :: ";
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}
