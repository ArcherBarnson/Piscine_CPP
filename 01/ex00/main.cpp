#include "Zombie.hpp"

int	main(void)
{
	randomChump("z1");
	Zombie	*z2 = newZombie("z2");

	delete z2;
	return (0);
}
