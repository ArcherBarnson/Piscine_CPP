/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBookCtl.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:52:49 by bgrulois          #+#    #+#             */
/*   Updated: 2023/07/26 15:53:12 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOKCTL_HPP
# define PHONEBOOKCTL_HPP

#include <iostream>
#include <string>

#include "Contact.hpp"
#include "PhoneBook.hpp"

#define WELCOME	"Welcome to MY AWESOME PHONEBOOK !"
#define CMD_MSG	"Please enter a command (ADD, SEARCH, EXIT): "
#define	EXITING	"(Eof recieved) Exiting..."
#define	GOODBYE	"GOODBYE ! HAVE FUN IN THIS WONDERFUL COMPUTER AGE !"

class PhoneBookCtl {
public :

PhoneBookCtl( void );

	int	check_cmd(std::string cmd);
	void	info_msg(int msg);

~PhoneBookCtl( void );
};

#endif
