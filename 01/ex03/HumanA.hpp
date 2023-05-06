#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA {
	public:
		HumanA( std::string name, Weapon &weapon );
		~HumanA( void );

		void	attack();
		void	setWeapon(Weapon& weapon);

	private:

		std::string	_name;
		Weapon		&_weapon;
};

#endif
