#include <iostream>
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	st0("st0");
	ScavTrap	st1("st1");
	int i = 0;

	std::cout << "DBG : st1 attacks until it can't" << std::endl << std::endl;
	while (++i < 49)
		st1.attack("the void");
	std::cout << std::endl << "DBG : st1 takes 99hp of damage" << std::endl << std::endl;
	st1.takeDamage(99);
	std::cout << std::endl << "DBG : st1 repairs itself twice" << std::endl << std::endl;
	st1.beRepaired(22);
	st1.beRepaired(77);
	std::cout << std::endl << "DBG : st1 falis to attack, fails to repair" << std::endl << std::endl;
	st1.attack("the wall");
	st1.beRepaired(1111);
	std::cout << std::endl << "DBG : st0 repairs itself for 20 hp" << std::endl << std::endl;
	st0.beRepaired(20);
	std::cout << std::endl << "DBG : st0 enters guard mode" << std::endl << std::endl;
	st0.guardGate();
	std::cout << std::endl << "DBG : st0 gets nuked for -1000hp" << std::endl << std::endl;
	st0.takeDamage(1000);
	std::cout << std::endl << "DBG : st0 cannot attack or be repaired, they have been destroyed" << std::endl << std::endl;
	st0.attack("a concept");
	st0.beRepaired(555);
	std::cout << std::endl << "DBG : st1 enters guard mode" << std::endl << std::endl;
	st1.guardGate();
	
	std::cout << std::endl << "DONE" << std::endl;
	return (0);
}
