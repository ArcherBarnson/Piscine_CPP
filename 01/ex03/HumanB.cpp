#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( std::string name ) : name(name) {
	return ;
}

HumanB::~HumanB( void ) {
	delete this->weapon;
	return ;
}

void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon->getType();
	std::cout << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon weapon)
{
	(this->weapon) = new Weapon(weapon.getType());
}
