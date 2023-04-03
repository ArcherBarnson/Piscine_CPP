/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:09:30 by bgrulois          #+#    #+#             */
/*   Updated: 2023/04/03 17:26:46 by bgrulois         ###   ########.fr       */
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
		std::cout << "The phonebook is full ! First entry (oldest) will be overwritten..." << std::endl;
		i = 0;
	}
	std::cout << "[ADD] --- Please fill out those informations --- [ADD]" << std::endl;
	std::cout << "First Name: ";
	std::cin >> this->contact_list[i].first_name;
	this->contact_list[i].format_str(this->contact_list[i].first_name, this->contact_list[i].trunc_first_name);
	//std::cout << "first name set as : " << this->contact_list[i].first_name << std::endl;
	std::cout << "Last Name: ";
	std::cin >> this->contact_list[i].last_name;
	this->contact_list[i].format_str(this->contact_list[i].last_name, this->contact_list[i].trunc_last_name);
	std::cout << "Nickname: ";
	std::cin >> this->contact_list[i].nickname;
	this->contact_list[i].format_str(this->contact_list[i].nickname, this->contact_list[i].trunc_nickname);
	std::cout << "Phone Number: ";
	std::cin >> this->contact_list[i].phone_number;
	this->contact_list[i].format_str(this->contact_list[i].phone_number, this->contact_list[i].trunc_phone_number);
	std::cout << "Darkest Secret: ";
	std::cin >> this->contact_list[i].darkest_secret;
	this->contact_list[i].format_str(this->contact_list[i].darkest_secret, this->contact_list[i].trunc_darkest_secret);
	this->contact_list[i].is_init = 1;
	std::cout << "[ADD] --- Contact successfully created --- [ADD]" << std::endl;
}

void	PhoneBook::do_search()
{
	int		i = 0;
	int		index_access;
	std::string	index;
	char		display_index;

	while (this->contact_list[i].is_init == 1 && i < 8)
	{
		display_index = i + '0';
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
	std::cout << "Please enter the ID of the contact you want to display : ";
	std::cin >> index;
	std::cout << std::endl;	
	if (index[0] < '1' || index[0] > '8' || index[1] != '\0')
	{
		std::cout << "This ID is INVALID, IDs range from 1 to 8" << std::endl;
		return ;
	}
	index_access = index[0] - '0';
	this->contact_list[index_access].display_contact_info();
}
