/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:46:02 by bgrulois          #+#    #+#             */
/*   Updated: 2023/04/03 15:49:19 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class	PhoneBook
{
public:
	std::string	add = "ADD";
	std::string	search = "SEARCH";
	std::string	exit = "EXIT";
	void		init_flags();
	void		do_add();
	void		do_search();
	Contact		contact_list[8];
	int		n_contacts;
};

#endif
