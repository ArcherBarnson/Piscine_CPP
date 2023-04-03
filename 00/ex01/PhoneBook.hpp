/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:46:02 by bgrulois          #+#    #+#             */
/*   Updated: 2023/04/03 12:57:17 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

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
}

PhoneBook::init_flags()
{
	int	i = -1;

	while (++i < 8)
		this::contact_list[i]::is_init = 0;
}

PhoneBook::do_add(void)
{
	int	i = 0;

	while (this::contact_list[i]::is_init == 1 && i < 8)
		i++;
	if (i = 8)
	{
		std::cout << "The phonebook is full ! First entry (oldest) will be overwritten..." << std:endl;
		i = 0;
	}
	std::cout << "[ADD] --- Please fill out those informations --- [ADD]" << std::endl;
	std::cout << "First Name: ";
	std::cin >> this::contact_list[i]::first_name;
	std::cout << "Last Name: ";
	std::cin >> this::contact_list[i]::last_name;
	std::cout << "Nickname: ";
	std::cin >> this::contact_list[i]::nickname;
	std::cout << "Phone Number: ";
	std::cin >> this::contact_list[i]::phone_number;
	std::cout << "Darkest Secret: ";
	std::cin >> this::contact_list[i]::darkest_secret;
	this::contact_list[i]::is_init = 1;
}

PhoneBook::do_search(void)
{
	int	i = 0;

	while (this::contact_list[i]::is_init == 1 && i < 8)
	{
		if (std::strlen(this::contact_list[i]::first_name))
		std::cout << this::contact_list[i]::first_name <<;
	}
}
