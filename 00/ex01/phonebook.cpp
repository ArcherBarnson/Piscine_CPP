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

void	PhoneBook::init_flags()
{
	int	i = -1;

	while (++i < 8)
		this->contact_list[i].is_init = 0;
}

void	PhoneBook::do_add()
{
	int	i = 0;

	while (this->contact_list[i].is_init == 1 && i < 8)
		i++;
	if (i == 8)
	{
		std::cout << PH_FULL << std::endl;
		i = 0;
	}
	std::cout << PH_ADD << std::endl;
	std::cout << "First Name: ";
	std::getline(std::cin, this->contact_list[i].first_name);
	if (std::cin.eof())
		return ;
	this->contact_list[i].trunc_first_name = this->contact_list[i].format_str(this->contact_list[i].first_name);
	std::cout << "Last Name: ";
	std::getline(std::cin, this->contact_list[i].last_name);
	if (std::cin.eof())
		return ;
	this->contact_list[i].trunc_last_name = this->contact_list[i].format_str(this->contact_list[i].last_name);
	std::cout << "Nickname: ";
	std::getline(std::cin, this->contact_list[i].nickname);
	if (std::cin.eof())
		return ;
	this->contact_list[i].trunc_nickname = this->contact_list[i].format_str(this->contact_list[i].nickname);
	std::cout << "Phone Number: ";
	std::getline(std::cin, this->contact_list[i].phone_number);
	if (std::cin.eof())
		return ;
	this->contact_list[i].trunc_phone_number = this->contact_list[i].format_str(this->contact_list[i].phone_number);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, this->contact_list[i].darkest_secret);
	if (std::cin.eof())
		return ;
	this->contact_list[i].trunc_darkest_secret = this->contact_list[i].format_str(this->contact_list[i].darkest_secret);
	this->contact_list[i].is_init = 1;
	std::cout << PH_CREATED << std::endl;
}

void	PhoneBook::do_search()
{
	int		i = 0;
	int		index_access;
	std::string	index;
	char		display_index;

	while (this->contact_list[i].is_init == 1 && i < 8)
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
