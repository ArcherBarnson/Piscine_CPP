#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string const & name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default constuctor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &src) : _name(src._name) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & other) {
	std::cout << "ClapTrap assignement operator called" << std::endl;
	if (this != &other)
	{
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;	
	}
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap destructor called" << std::endl;
	return ;
}

void	ClapTrap::attack(std::string const & target)
{
	if (_energyPoints <= 0)
		std::cout << "ClapTrap " << _name << " cannot attack without energy points !" << std::endl;
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " cannot attack : they are dead !" << std::endl;
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target;
		std::cout << " causing " << _attackDamage << " points of damage !" << std::endl;
		ClapTrap(target).takeDamage(_attackDamage);
		_energyPoints--;
	}
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage points !" <<std::endl;
	std::cout << "Claptrap " << _name << " has " << _hitPoints << " hp left" << std::endl;
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " has been killed !" << std::endl;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints <= 0)
		std::cout << "ClapTrap " << _name << " cannot repair themselves without energy points !" << std::endl;
	if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " cannot repair themselves : they are dead !" << std::endl;
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " repaired themselves for " << amount << " hit points" << std::endl;
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " has " << _hitPoints << " hp left" << std::endl;
	}
	return ;

}
