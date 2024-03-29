/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:18:00 by bgrulois          #+#    #+#             */
/*   Updated: 2023/08/08 18:18:02 by bgrulois         ###   ########.fr       */
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

std::ostream &operator<<(std::ostream &outfile, Fixed const & fixed);

#endif
