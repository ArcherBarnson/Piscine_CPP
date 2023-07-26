/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:09:30 by bgrulois          #+#    #+#             */
/*   Updated: 2023/07/26 14:58:42 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {
	return;
}

void	PhoneBook::exec_cmd(int cmd)
{
	if (cmd == 1)
		_do_add();
	if (cmd == 2)
		_do_search();
}

void	PhoneBook::_prompt_contact_info(std::string display, std::string &info)
{
	std::cout << display;
	std::getline(std::cin, info);
	if (std::cin.eof())
		return ;
}

void	PhoneBook::_do_add()
{
	int	i = 0;

	while (this->_contact_list[i].first_name != "" && i < 8)
		i++;
	if (i == 8)
	{
		std::cout << PH_FULL << std::endl;
		i = 0;
	}
	std::cout << PH_ADD << std::endl;
	this->_prompt_contact_info("First Name : ", this->_contact_list[i].first_name);
	this->_prompt_contact_info("Last Name : ", this->_contact_list[i].last_name);
	this->_prompt_contact_info("Nickname : ", this->_contact_list[i].nickname);
	this->_prompt_contact_info("Phone Number : ", this->_contact_list[i].phone_number);
	this->_prompt_contact_info("Darkest Secret : ", this->_contact_list[i].darkest_secret);
	std::cout << PH_CREATED << std::endl;
}

/*void	PhoneBook::_display_format_info(std::string str)
{
	int	len = str.length();
	int	trunc_size = len - 10;
	std::string	tr;

	if (trunc_size > 0)
	{
		tr = str;
		tr.erase(len - trunc_size);
		tr[(len - 1) - (len - 10)] = '.';
	}
	else
		tr = std::string(10 - str.length(), ' ') + str;
	std::cout << tr << " | ";
}*/

void	PhoneBook::_display_format_info(std::string str)
{
	//int	len = str.length();
	//int	trunc_size = len - 10;

	std::cout << std::setfill(' ') << std::setw(10) << str << std::endl;
}

void	PhoneBook::_do_search()
{
	int		i = 0;
	int		index_access;
	std::string	index;

	while (i < 8)
	{
		std::cout << " --------------------------------------------" << std::endl;
		std::cout << " | ";
		std::cout << (char)((i + 1) + '0');
		std::cout << " | ";
		_display_format_info(this->_contact_list[i].first_name);
		_display_format_info(this->_contact_list[i].last_name);
		_display_format_info(this->_contact_list[i].nickname);
		std::cout << std::endl;
		i++;
	}
	std::cout << " --------------------------------------------" << std::endl;
	std::cout << S_ID << std::endl;
	std::getline(std::cin, index);
	if (std::cin.eof())
		return ;
	if (index[0] < '1' || index[0] > '8' || index[1] != '\0')
	{
		std::cout << S_BAD_ID << std::endl;
		return ;
	}
	index_access = index[0] - '0';
	this->_contact_list[index_access - 1].display_contact_info();
}

PhoneBook::~PhoneBook( void ) {
	return ;
}
