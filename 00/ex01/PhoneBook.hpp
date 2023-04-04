/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:46:02 by bgrulois          #+#    #+#             */
/*   Updated: 2023/04/04 11:15:44 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

#define	ADD "ADD"
#define	SEARCH "SEARCH"
#define	EXIT "EXIT"

class	PhoneBook
{
public:
	void		init_flags();
	void		do_add();
	void		do_search();
	Contact		contact_list[8];
	int		n_contacts;
};

#endif
