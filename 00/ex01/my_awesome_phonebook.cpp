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

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	exec_cmd(int cmd, PhoneBook &phonebook)
{
	if (cmd == 1)
		phonebook.do_add();
	if (cmd == 2)
		phonebook.do_search();
}

int	check_cmd(std::string cmd)
{
	if (cmd.compare(ADD) == 0)
		return (1);
	if (cmd.compare(SEARCH) == 0)
		return (2);
	return (0);
}

int	main(void)
{
	std::string cmd;
	PhoneBook phonebook;

	std::cout << "Welcome to MY AWESOME PHONEBOOK !" << std::endl;
	phonebook.init_flags();
	while (cmd.compare(EXIT) != 0)
	{
		std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
		std::cin >> cmd;
		//std::cout << "cmd is: " << cmd << std::endl;
		exec_cmd(check_cmd(cmd), phonebook);
	}
	std::cout << "GOODBYE ! HAVE FUN IN THIS WONDERFUL COMPUTER AGE !" << std::endl;
	return (0);
}
