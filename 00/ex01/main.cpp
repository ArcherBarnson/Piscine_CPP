#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "PhoneBookCtl.hpp"

int	main(void)
{
	std::string	cmd;
	PhoneBook	phonebook;
	PhoneBookCtl	ctl;


	ctl.info_msg(0);
	phonebook.init_flags();
	while (cmd.compare(EXIT) != 0 && !std::cin.eof())
	{
		ctl.info_msg(1);
		std::getline(std::cin, cmd);
		ctl.exec_cmd(ctl.check_cmd(cmd), phonebook);
	}
	ctl.info_msg(3);
	return (0);
}
