#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
	public:
		Weapon( std::string type );
		~Weapon( void );

		std::string const & getType(void);
		void	setType(std::string type);

	private:	
		std::string	_type;
};



#endif
