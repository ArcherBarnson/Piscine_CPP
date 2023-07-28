#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl		Harl;

	if (ac != 2)
	{
		std::cout << "Error: Bad arg number (./harl <level>)" << std::endl;
		return (1);
	}
	else	
	{
		std::string	level(av[1]);
		Harl.complain(level);
	}
	/*----TESTS-------------
	Harl.complain("help");
	Harl.complain("debug");
	Harl.complain("info");
	Harl.complain("warning");
	Harl.complain("warning");
	Harl.complain("info");
	Harl.complain("info");
	Harl.complain("info");
	Harl.complain("deebug");
	Harl.complain("debugg");
	Harl.complain("debug");
	Harl.complain("warning");
	Harl.complain("error");
	Harl.complain("error");
	*/
	return (0);
}
