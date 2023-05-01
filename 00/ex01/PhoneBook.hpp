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
#define	SUB_QUIT	"(Eof detected) Exiting contextual menu..."

class	PhoneBook
{
private:
	void		prompt_contact_info(std::string display, std::string &info);
	void		display_format_info(std::string str);
	void		do_add();
	void		do_search();
public:
	void		exec_cmd(int cmd);
	Contact		contact_list[8];
};

#endif
