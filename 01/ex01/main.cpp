#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde = zombieHorde(10, "z");

	delete [] horde;
	return (0);
}
