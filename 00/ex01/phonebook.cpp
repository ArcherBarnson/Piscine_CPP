/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:09:30 by bgrulois          #+#    #+#             */
/*   Updated: 2023/07/26 15:27:37 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) : _oldest_contact(0) {
	return;
}

void	PhoneBook::exec_cmd(int cmd)
{
	if (cmd == 1)
		_do_add();
	if (cmd == 2)
		_do_search();
}

void	PhoneBook::_do_add()
{
	int	i = 0;

	while (i < 8 && this->_contact_list[i].get_contact_info(0) != "")
		i++;
	if (i == 8)
	{
		std::cout << PH_FULL << std::endl;
		i = this->_oldest_contact;
		std::cout << "Oldest contact is  "
			<< this->_contact_list[_oldest_contact].get_contact_info(0) << std::endl;
		if (i < 7)
			this->_oldest_contact = i + 1;
		else if (i == 7)
			this->_oldest_contact = 0;
	}
	std::cout << PH_ADD << std::endl;
	std::cout << "i = " << i << std::endl << std::endl;
	this->_contact_list[i].fill_contact_infos();
	if (std::cin.eof())
		return ;
	while (this->_contact_list[i].get_contact_info(0).length() == 0
		|| this->_contact_list[i].get_contact_info(1).length() == 0
		|| this->_contact_list[i].get_contact_info(2).length() == 0
		|| this->_contact_list[i].get_contact_info(3).length() == 0
		|| this->_contact_list[i].get_contact_info(4).length() == 0) {
		std::cout << "ERROR:There is one or more empty fields." << std::endl;
		this->_contact_list[i].fill_contact_infos();
	}
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
	int		len = str.length();
	int		trunc_size = len - 10;
	std::string	tr = str;

	if (trunc_size > 0)
	{
		tr = str;
		tr.erase(len - trunc_size);
		tr[(len - 1) - (len - 10)] = '.';
	}
	else
		tr = std::string(10 - str.length(), ' ') + str;
	std::cout << std::setfill(' ') << std::setw(10) << tr << "|";
}

void	PhoneBook::_do_search()
{
	int		i = 0;
	int		index_access;
	std::string	index;

	while (i < 8)
	{
		std::cout << " ---------------------------------------" << std::endl;
		std::cout << " | ";
		std::cout << (char)((i + 1) + '0');
		std::cout << " | ";
		_display_format_info(this->_contact_list[i].get_contact_info(0));
		_display_format_info(this->_contact_list[i].get_contact_info(1));
		_display_format_info(this->_contact_list[i].get_contact_info(2));
		std::cout << std::endl;
		i++;
	}
	std::cout << " ---------------------------------------" << std::endl;
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
