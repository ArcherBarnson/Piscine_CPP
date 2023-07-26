#include "Harl.hpp"

int	main(int ac, char **av)
{
	std::string	level = "";
	Harl		Harl;

	if (ac > 2)
	{
		std::cout << "Error: Bad arg number (./harl <level>)" << std::endl;
		return (1);
	}
	if (ac == 1)
		Harl.complain("");
	if (ac == 2)
	{
		level.append(av[1]);
		Harl.complain(level);
	}
	/*Harl.complain("help");
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
	Harl.complain("error");*/
	return (0);
}
