#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed {
	public:
		Fixed( void );
		Fixed(const int n);
		Fixed(const float f);
		Fixed(Fixed const &copy);
		Fixed& operator=(const Fixed & other);
		~Fixed( void );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

	
	private:
		int			_fixed;
		static int const 	_raw;
};

#endif
