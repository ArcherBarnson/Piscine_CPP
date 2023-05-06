#include "Replace.hpp"

int	main(int ac, std::string *av)
{
	if (ac != 4)
	{
		std::cerr << "Bad arg number (<filename>, <s1>, <s2>), exiting...";
		std::cerr << std::endl;
		return (1);
	}
	Replace	replace(av[1], av[2], av[3]);
	replace.bufToFile(replace.replace(), av[1]);
	return (0);
}
