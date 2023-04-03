/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:13:12 by bgrulois          #+#    #+#             */
/*   Updated: 2023/04/03 17:26:48 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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
