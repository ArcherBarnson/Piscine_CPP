/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:20:45 by bgrulois          #+#    #+#             */
/*   Updated: 2023/08/08 18:22:31 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Point a(7, 0);
	Point b(10, 10);
	Point c(0, 20);
	Point point(5, 5);
	Fixed ax = a.getX();
        std::cout << "AX :: " << ax << std::endl;

	if (bsp(a, b, c, point))
		std::cout << "Point is inside of the triangle" << std::endl;
	std::cout << "Point is NOT inside of the triangle" << std::endl;
	return 0;
}
