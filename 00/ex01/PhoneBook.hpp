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

#define	ADD 		"ADD"
#define	SEARCH 		"SEARCH"
#define	EXIT 		"EXIT"
#define	PH_FULL		"The phonebook is full ! First entry (oldest) will be overwritten..."
#define	PH_ADD		"[ADD] --- |Please fill out those informations| --- [ADD]"
#define	PH_CREATED	"[ADD] ---    |Contact successfully created|    --- [ADD]"
#define S_ID		"[SEARCH]- |Please enter the ID of the contact| -[SEARCH]"
#define	S_BAD_ID	"[SEARCH]- |Invalid ID. IDs range from 1 to 8 | -[SEARCH]"

class	PhoneBook
{
public:

PhoneBook( void );

	void		exec_cmd(int cmd);

~PhoneBook( void );

private:
	void		_prompt_contact_info(std::string display, std::string &info);
	void		_display_format_info(std::string str);
	void		_do_add();
	void		_do_search();
	Contact		_contact_list[8];
};

#endif
