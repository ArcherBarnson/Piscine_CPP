/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:46:02 by bgrulois          #+#    #+#             */
/*   Updated: 2023/04/03 14:47:08 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

class	PhoneBook
{
	std::string	add = "ADD";
	std::string	search = "SEARCH";
	std::string	exit = "EXIT";
	void		init_flags();
	void		do_add();
	void		do_search();
	Contact		contact_list[8];
	int		n_contacts;
};

void	PhoneBook::init_flags()
{
	int	i = -1;

	while (++i < 8)
		this->contact_list[i]->is_init = 0;
}

void	PhoneBook::do_add()
{
	int	i = 0;

	while (this->contact_list[i]->is_init == 1 && i < 8)
		i++;
	if (i = 8)
	{
		std::cout << "The phonebook is full ! First entry (oldest) will be overwritten..." << std::endl;
		i = 0;
	}
	std::cout << "[ADD] --- Please fill out those informations --- [ADD]" << std::endl;
	std::cout << "First Name: ";
	std::cin >> this->contact_list[i]->first_name;
	this->contact_list[i]->format_str(this->contact_list[i]->first_name, this->contact_list[i]->trunc_first_name);
	std::cout << "Last Name: ";
	std::cin >> this->contact_list[i]->last_name;
	this->contact_list[i]->format_str(this->contact_list[i]->last_name, this->contact_list[i]->trunc_last_name);
	std::cout << "Nickname: ";
	std::cin >> this->contact_list[i]->nickname;
	this->contact_list[i]->format_str(this->contact_list[i]->nickname, this->contact_list[i]->trunc_nickname);
	std::cout << "Phone Number: ";
	std::cin >> this->contact_list[i]->phone_number;
	this->contact_list[i]->format_str(this->contact_list[i]->phone_number, this->contact_list[i]->trunc_phone_number);
	std::cout << "Darkest Secret: ";
	std::cin >> this->contact_list[i]->darkest_secret;
	this->contact_list[i]->format_str(this->contact_list[i]->darkest_secret, this->contact_list[i]->trunc_darkest_secret);
	this->contact_list[i].is_init = 1;
	std::cout << "[ADD] --- Contact successfully created --- [ADD]" << std::endl;
}

void	PhoneBook::do_search()
{
	int		i = 0;
	std::string	index = "";

	while (this->contact_list[i].is_init == 1 && i < 8)
	{
		if (this->contact_list[i]->first_name.compare(this->contact_list[i]->trunc_first_name) == 0)
			std::cout << this->contact_list[i]->first_name;
		else
			std::cout << this->contact_list[i]->trunc_first_name;
		std::cout << " | ";
		if (this->contact_list[i]->last_name.compare(this->contact_list[i]->trunc_last_name) == 0)
			std::cout << this->contact_list[i]->last_name;
		else
			std::cout << this->contact_list[i]->trunc_last_name;
		std::cout << " | ";
		if (this->contact_list[i]->nickname.compare(this->contact_list[i]->trunc_nickname) == 0)
			std::cout << this->contact_list[i]->nickname;
		else
			std::cout << this->contact_list[i]->trunc_nickname;
		std::cout << " | ";
		std::cout << i - '0'; << std::endl;
		i++;
	}
	std::cout << "Please enter the ID of the contact you want to display : ";
	std::cin >> index;
	std::cout << endl;	
	if (index[0] < '1' || index[0] > '8' || index[1] != '\0')
	{
		std::cout << "This ID is INVALID, IDs range from 1 to 8" << std::endl;
		return ;
	}
	this->contact_list[(index[0] + '0')]->display_contact_info();
}

#endif
