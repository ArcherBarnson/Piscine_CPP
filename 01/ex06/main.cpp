/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:27:20 by bgrulois          #+#    #+#             */
/*   Updated: 2023/07/26 18:28:04 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	std::string	level = "";
	Harl		Harl;

	if (ac != 2)
	{
		std::cout << "Error: Bad arg number (./harl <level>)" << std::endl;
		return (1);
	}
	else
	{
		level.append(av[1]);
		Harl.complain(level);
	}
	/* TESTS
	std::cout << "debug :" << std::endl;
	Harl.complain("debug");
	std::cout << "DEBUG :" << std::endl;
	Harl.complain("DEBUG");
	std::cout << "info :" << std::endl;
	Harl.complain("info");
	std::cout << "INFO :" << std::endl;
	Harl.complain("INFO");
	std::cout << "warning :" << std::endl;
	Harl.complain("warning");
	std::cout << "WARNING :" << std::endl;
	Harl.complain("WARNING");
	std::cout << "error :" << std::endl;
	Harl.complain("error");
	std::cout << "ERROR :" << std::endl;
	Harl.complain("ERROR");
	std::cout << "bogus entry :" << std::endl;
	Harl.complain("asdf");
	*/
	return (0);
}
