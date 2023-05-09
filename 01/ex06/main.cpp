#include "Harl.hpp"

int	main(int ac, char **av)
{
	std::string	level = "";
	Harl		Harl;

	if (ac < 1 || ac > 2)
	{
		std::cout << "Error: Bad arg number (./harl <level>)" << std::endl;
		return (1);
	}
	if (ac != 1)
	{
		level.append(av[1]);
		Harl.complain(level);
	}
	Harl.complain("");
	return (0);
}
