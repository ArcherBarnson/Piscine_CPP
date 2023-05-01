#ifndef MY_AWESOME_PHONEBOOK_HPP
# define MY_AWESOME_PHONEBOOK_HPP

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
	int	check_cmd(std::string cmd);
	void	info_msg(int msg);
};

#endif
