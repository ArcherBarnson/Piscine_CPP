/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_phonebook.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:03:13 by bgrulois          #+#    #+#             */
/*   Updated: 2023/04/04 10:51:45 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookCtl.hpp"

int	PhoneBookCtl::check_cmd(std::string cmd)
{
	if (cmd.compare(ADD) == 0)
		return (1);
	if (cmd.compare(SEARCH) == 0)
		return (2);
	return (0);
}

void	PhoneBookCtl::info_msg(int msg)
{
	if (msg == 0)
		std::cout << WELCOME << std::endl;
	if (msg == 1)
		std::cout << CMD_MSG << std::endl;
	if (msg == 2)
	{
		std::cout << EXITING << std::endl;
		std::cout << GOODBYE << std::endl;
	}
	if (msg == 3)
		std::cout << GOODBYE << std::endl;
}
