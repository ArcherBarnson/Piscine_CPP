/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:02:08 by bgrulois          #+#    #+#             */
/*   Updated: 2023/11/15 11:02:10 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "templates.hpp"
# include <iostream>

int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
//return 0;
/*a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2     --- expected result*/
std::string sA = "hello";
std::string sB = "world";
std::cout << sA << sB << std::endl;
::swap(sA, sB);
std::cout << sA << sB << std::endl;
//::swap(sA, a);        --- doesnt compile -> conflicting types
return 0;
}
