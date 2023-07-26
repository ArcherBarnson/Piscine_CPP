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

	if (ac > 2)
	{
		std::cout << "Error: Bad arg number (./harl <level>)" << std::endl;
		return (1);
	}
	if (ac == 1)
		Harl.complain("");
	if (ac == 2)
	{
		level.append(av[1]);
		Harl.complain(level);
	}
	Harl.complain("");
	return (0);
}
