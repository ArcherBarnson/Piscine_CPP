#include "Zombie.hpp"

Zombie::Zombie( void ) {
	return ;
}

Zombie::Zombie( std::string name ) : name(name){
	std::cout << name << " was spawned" << std::endl;
	return ;
}

Zombie::~Zombie( void ) {
	std::cout << this->name << " was killed." << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->name;
	std::cout <<  ": BraiiiiiiinnnzzzZ..." << std::endl;
}
