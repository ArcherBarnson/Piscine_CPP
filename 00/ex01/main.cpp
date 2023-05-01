#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "PhoneBookCtl.hpp"

int	main(void)
{
	std::string	cmd;
	PhoneBook	phonebook;
	PhoneBookCtl	ctl;


	ctl.info_msg(0);
	while (cmd.compare(EXIT) != 0 && !std::cin.eof())
	{
		ctl.info_msg(1);
		std::getline(std::cin, cmd);
		phonebook.exec_cmd(ctl.check_cmd(cmd));
	}
	ctl.info_msg(3);
	return (0);
}
