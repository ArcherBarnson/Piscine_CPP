#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
	public:
		HumanA( std::string name, Weapon weapon );
		~HumanA( void );

		void	attack();
		void	setWeapon(Weapon weapon);

	private:

		std::string	name;
		Weapon	weapon;
};

#endif
