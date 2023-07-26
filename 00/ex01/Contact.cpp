/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:13:12 by bgrulois          #+#    #+#             */
/*   Updated: 2023/04/04 12:23:23 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void ) {
	return ;
}

void	Contact::set_contact_info(int mode, std::string &str)
{
	if (mode == 0)
		this->_first_name = str;
	if (mode == 1)
		this->_last_name = str;
	if (mode == 2)
		this->_nickname = str;
	if (mode == 3)
		this->_phone_number = str;
	if (mode == 4)
		this->_darkest_secret = str;
}

void	Contact::fill_contact_infos()
{
	std::string info;

	std::cout << "First Name : ";
	std::getline(std::cin, info);
	if (std::cin.eof())
		return ;
	this->set_contact_info(0, info);
	std::cout << "Last Name : ";
	std::getline(std::cin, info);
	if (std::cin.eof())
		return ;
	this->set_contact_info(1, info);
	std::cout << "Nickname : ";
	std::getline(std::cin, info);
	if (std::cin.eof())
		return ;
	this->set_contact_info(2, info);
	std::cout << "Phone Number: ";
	std::getline(std::cin, info);
	if (std::cin.eof())
		return ;
	this->set_contact_info(3, info);
	std::cout << "Darkest Secret : ";
	std::getline(std::cin, info);
	if (std::cin.eof())
		return ;
	this->set_contact_info(4, info);
}

std::string	Contact::get_contact_info(int mode)
{
	if (mode == 0)
		return (this->_first_name);
	if (mode == 1)
		return (this->_last_name);
	if (mode == 2)
		return (this->_nickname);
	if (mode == 3)
		return (this->_phone_number);
	if (mode == 4)
		return (this->_darkest_secret);
	return (NULL);
}

void	Contact::display_contact_info()
{
	std::cout << "First name	:  " << this->get_contact_info(0) << std::endl;
	std::cout << "Last name	:  " << this->get_contact_info(1) << std::endl;
	std::cout << "Nickname	:  " << this->get_contact_info(2) << std::endl;
	std::cout << "Phone number	:  " << this->get_contact_info(3) << std::endl;
	std::cout << "Darkest secret	:  " << this->get_contact_info(4) << std::endl;
}

Contact::~Contact( void ) {
	return ;
}
