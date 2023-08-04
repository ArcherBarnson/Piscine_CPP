#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed {
	public:
		Fixed( void );
		Fixed(Fixed const &copy);
		Fixed& operator=(const Fixed & other);
		~Fixed( void );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	
	private:
		int			_fixed;
		static int const 	_raw = 8;
};

#endif
