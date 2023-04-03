/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:56:35 by bgrulois          #+#    #+#             */
/*   Updated: 2023/04/03 14:47:10 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

class	Contact
{
	void		format_str(std::string str, std::string tr);
	void		display_contact_info();
	int		is_init;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	std::string	trunc_first_name;
	std::string	trunc_last_name;
	std::string	trunc_nickname;
	std::string	trunc_phone_number;
	std::string	trunc_darkest_secret;
};

void	Contact::format_str(std::string str, std::string tr)
{
	int	i = str.length();
	int	trunc_size = str.length() - 10;

	tr.assign(str);
	if (tr.length() > 10)
	{
		while (trunc_size != 0)
		{
			tr.erase(tr[i]);
			trunc_size--;
		}
	}
	tr[i] = '.';
}

void	Contact::display_contact_info()
{
	std::cout << "First name : " << this->first_name << std::endl;
	std::cout << "Last name : " << this->last_name << std::endl;
	std::cout << "Nickname : " << this->nickname << std::endl;
	std::cout << "Le 06: " << this->phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->darkest_secret << std::endl;
}

#endif
