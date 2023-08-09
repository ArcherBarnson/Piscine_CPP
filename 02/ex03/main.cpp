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

int main( void ) {
	Point const a(0, 0);
	Point const b(10, 10);
	Point const c(0, 20);
	Point const point(5, 5);

	if (bsp(a, b, c, point))
		std::cout << "Point is inside of the triangle" << std::endl;
	std::cout << "Point is NOT inside of the triangle" << std::endl;
	return 0;
}
