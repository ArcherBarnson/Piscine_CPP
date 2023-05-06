#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( std::string name ) : _name(name) {
	return ;
}

HumanB::~HumanB( void ) {
	return ;
}

void	HumanB::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon->getType();
	std::cout << std::endl;
	return ;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
