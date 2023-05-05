#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA( std::string name, Weapon weapon )
	: name(name), weapon(weapon) {
	return ;
}

HumanA::~HumanA( void ) {
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType();
	std::cout << std::endl;
	return ;
}

void	HumanA::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}
