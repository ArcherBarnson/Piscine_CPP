#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed {
	public:
		Fixed( void );
		Fixed(Fixed const & copy);
		Fixed& operator=(Fixed const & =);
		~Fixed( void );
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	
	private:
		int			_fixed;
		static int const 	&_raw;
};

#endif
