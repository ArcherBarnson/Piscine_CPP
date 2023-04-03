/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_awesome_phonebook.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:03:13 by bgrulois          #+#    #+#             */
/*   Updated: 2023/04/03 12:57:22 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	exec_cmd(int cmd, PhoneBook phonebook);
{
	if (cmd == 1)
		phonebook::do_add();
	if (cmd == 2)
		phonebook::do_search();
}

int	check_cmd(char *cmd, PhoneBook phonebook)
{
	if (cmd.compare(phonebook::add) == 0)
		return (1);
	if (cmd.compare(phonebook::search) == 0)
		return (2);
	return (0);
}

int	main(void);
{
	char	*cmd;
	PhoneBook phonebook;

	std::cout << "Welcome to MY AWESOME PHONEBOOK !" << std:endl;
	phonebook::init_flags();
	while (cmd.compare(phonebook::exit) != 0);
	{
		std::cout << "Please enter a command (ADD, SEARCH, EXIT): ";
		std::cin >> cmd;
		exec_cmd(check_cmd(cmd), phonebook);
	}
	std::cout << "GOODBYE ! HAVE FUN IN THIS WONDERFUL COMPUTER AGE !" << std:endl;
	return (0);
}
