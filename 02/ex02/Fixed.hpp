/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:47:22 by bgrulois          #+#    #+#             */
/*   Updated: 2023/08/08 18:01:48 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed {
	public:
		Fixed( void );
		Fixed(const int n);
		Fixed(const float f);
		Fixed(Fixed const &copy);
		Fixed& 	operator=(const Fixed & other);
		bool 	operator==(const Fixed & other);
		bool	operator!=(const Fixed & other);
		bool	operator>=(const Fixed & other);
		bool	operator<=(const Fixed & other);
		bool	operator>(const Fixed & other);
		bool	operator<(const Fixed & other);
		Fixed	operator+(const Fixed & other);
		Fixed	operator-(const Fixed & other);
		Fixed	operator*(const Fixed & other);
		Fixed	operator/(const Fixed & other);
		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);
		~Fixed( void );
		static Fixed min(Fixed & f1, Fixed & f2);
		static Fixed min(const Fixed & f1, const Fixed & f2);
		static Fixed max(Fixed & f1, Fixed & f2);
		static Fixed max(const Fixed & f1, const Fixed & f2);
		int 	getRawBits( void ) const;
		void 	setRawBits( int const raw );
		float 	toFloat( void ) const;
		int 	toInt( void ) const;

	
	private:
		int			_fixed;
		static int const 	_raw;
};

std::ostream 	&operator<<(std::ostream &outfile, Fixed const & fixed);

#endif
