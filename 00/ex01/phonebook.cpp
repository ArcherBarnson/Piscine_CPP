/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:09:30 by bgrulois          #+#    #+#             */
/*   Updated: 2023/04/04 12:23:25 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::exec_cmd(int cmd)
{
	if (cmd == 1)
		do_add();
	if (cmd == 2)
		do_search();
}

void	PhoneBook::prompt_contact_info(std::string display, std::string &info)
{
	std::cout << display;
	std::getline(std::cin, info);
	if (std::cin.eof())
		return ;
	//wip -- this->contact_list[i].trunc_first_name = this->contact_list[i].format_str(this->contact_list[i].first_name);
}

void	PhoneBook::do_add()
{
	int	i = 0;

	while (this->contact_list[i].first_name != "" && i < 8)
		i++;
	if (i == 8)
	{
		std::cout << PH_FULL << std::endl;
		i = 0;
	}
	std::cout << PH_ADD << std::endl;
	this->prompt_contact_info("First Name : ", this->contact_list[i].first_name);
	this->prompt_contact_info("Last Name : ", this->contact_list[i].last_name);
	this->prompt_contact_info("Nickname : ", this->contact_list[i].nickname);
	this->prompt_contact_info("Phone Number : ", this->contact_list[i].phone_number);
	this->prompt_contact_info("Darrkest Secret : ", this->contact_list[i].darkest_secret);
	std::cout << PH_CREATED << std::endl;
}

void	PhoneBook::do_search()
{
	int		i = 0;
	int		index_access;
	std::string	index;
	char		display_index;

	while (this->contact_list[i].first_name != "" && i < 8)
	{
		display_index = (i + 1) + '0';
		if (this->contact_list[i].first_name.compare(this->contact_list[i].trunc_first_name) == 0)
			std::cout << this->contact_list[i].first_name;
		else
			std::cout << this->contact_list[i].trunc_first_name;
		std::cout << " | ";
		if (this->contact_list[i].last_name.compare(this->contact_list[i].trunc_last_name) == 0)
			std::cout << this->contact_list[i].last_name;
		else
			std::cout << this->contact_list[i].trunc_last_name;
		std::cout << " | ";
		if (this->contact_list[i].nickname.compare(this->contact_list[i].trunc_nickname) == 0)
			std::cout << this->contact_list[i].nickname;
		else
			std::cout << this->contact_list[i].trunc_nickname;
		std::cout << " | ";
		std::cout << display_index << std::endl;
		i++;
	}
	std::cout << S_ID << std::endl;
	std::cin >> index;
	if (std::cin.eof())
		return ;
	std::cout << std::endl;	
	if (index[0] < '1' || index[0] > '8' || index[1] != '\0')
	{
		std::cout << S_BAD_ID << std::endl;
		return ;
	}
	index_access = index[0] - '0';
	this->contact_list[index_access - 1].display_contact_info();
}
