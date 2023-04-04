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

std::string	Contact::format_str(std::string str)
{
	int	i = str.length() - 1;
	int	trunc_size = str.length() - 10;
	std::string	tr;

	if (trunc_size > 0)
	{
		tr = str;
		tr.erase(i - trunc_size + 1, i);
		tr[i - trunc_size] = '.';
	}
	else
	{
		str.resize(10, ' ');
		tr = str;
	}
	return (tr);
}

void	Contact::display_contact_info()
{
	std::cout << "First name : " << this->first_name << std::endl;
	std::cout << "Last name : " << this->last_name << std::endl;
	std::cout << "Nickname : " << this->nickname << std::endl;
	std::cout << "Le 06: " << this->phone_number << std::endl;
	std::cout << "Darkest Secret: " << this->darkest_secret << std::endl;
}
