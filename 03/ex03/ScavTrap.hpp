#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap(std::string const & name);
		ScavTrap(ScavTrap const & src);
		ScavTrap &operator=(ScavTrap const & other);
		~ScavTrap(void);
		void	guardGate();
	private:
		std::string const & _name;
};

#endif
