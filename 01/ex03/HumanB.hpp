#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB {
	public:
		HumanB( std::string name );
		~HumanB( void );

		void	attack();
		void	setWeapon(Weapon& weapon);

	private:

		std::string	_name;
		Weapon		*_weapon;
};

#endif