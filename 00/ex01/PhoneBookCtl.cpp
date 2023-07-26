/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookCtl.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:03:13 by bgrulois          #+#    #+#             */
/*   Updated: 2023/07/26 15:52:14 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookCtl.hpp"

PhoneBookCtl::PhoneBookCtl( void ) {
	return ;
}

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
		std::cout << GOODBYE << std::endl;
}

PhoneBookCtl::~PhoneBookCtl( void ) {
	return ;
}
