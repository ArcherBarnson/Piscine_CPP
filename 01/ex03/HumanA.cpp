#include "Weapon.hpp"
#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA( std::string name, Weapon& weapon )
	: _name(name), _weapon(weapon) {
	return ;
}

HumanA::~HumanA( void ) {
	return ;
}

void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.getType();
	std::cout << std::endl;
	return ;
}

void	HumanA::setWeapon(Weapon& weapon)
{
	_weapon = weapon;
}
