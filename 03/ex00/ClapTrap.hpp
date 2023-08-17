#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	public:
		ClapTrap(std::string const & name);
		ClapTrap(ClapTrap const &src);
		ClapTrap &operator=(ClapTrap const & other);
		~ClapTrap(void);
		void	attack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:
		std::string const & _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
};

#endif