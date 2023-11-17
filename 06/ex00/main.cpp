/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:59:21 by bgrulois          #+#    #+#             */
/*   Updated: 2023/11/15 10:59:24 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **argv)
{
	if (ac == 1)
	{
		std::cout << "Error : no argument given" << std::endl;
		std::cout << "(usage example : ./scalar_converter <n>)" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
