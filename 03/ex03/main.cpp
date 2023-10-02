/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:58:08 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/02 15:28:31 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int	main(void)
{
	ScavTrap	st0("st0");
	ScavTrap	st1("st1");
	int i = 0;

	std::string wall = "the wall";
	std::string thevoid = "the void";
	std::string smthn = "something something";
	std::cout << "DBG : st1 attacks until it can't" << std::endl << std::endl;
	while (++i < 49)
		st1.attack(thevoid);
	std::cout << std::endl << "DBG : st1 takes 99hp of damage" << std::endl << std::endl;
	st1.takeDamage(99);
	std::cout << std::endl << "DBG : st1 repairs itself twice" << std::endl << std::endl;
	st1.beRepaired(22);
	st1.beRepaired(77);
	std::cout << std::endl << "DBG : st1 falis to attack, fails to repair" << std::endl << std::endl;
	st1.attack(wall);
	st1.beRepaired(1111);
	std::cout << std::endl << "DBG : st0 repairs itself for 20 hp" << std::endl << std::endl;
	st0.beRepaired(20);
	std::cout << std::endl << "DBG : st0 enters guard mode" << std::endl << std::endl;
	st0.guardGate();
	std::cout << std::endl << "DBG : st0 gets nuked for -1000hp" << std::endl << std::endl;
	st0.takeDamage(1000);
	std::cout << std::endl << "DBG : st0 cannot attack or be repaired, they have been destroyed" << std::endl << std::endl;
	st0.attack(smthn);
	st0.beRepaired(555);
	std::cout << std::endl << "DBG : st1 enters guard mode" << std::endl << std::endl;
	st1.guardGate();
	
	std::cout << std::endl << "TESTING FRAGTRAPS" << std::endl;
	FragTrap	ft0("ft0");
	FragTrap	ft1("ft1");

	std::cout << "DBG : ft0 attacks like crazy until it runs out of energy" << std::endl;
	i = 0;
	while (++i < 100)
		ft0.attack(thevoid);
	std::cout << "DBG : ft0 takes 500hp of damage, cannot repair because they are destroyed" << std::endl;
	ft0.takeDamage(500);
	ft0.beRepaired(200);
	
	std::cout << "DBG : ft1 repairs for 50 more hp (25 + 25) and asks for high fives" << std::endl;
	ft1.beRepaired(25);
	ft1.beRepaired(25);
	ft1.highFivesGuys();
	std::cout << "DBG : ft1 doesnt get a high five, instead gets 1000000hp of damage for asking" << std::endl;
	ft1.takeDamage(1000000);
	std::cout << std::endl << "DONE" << std::endl;
	std::cout << std::endl << "TESTING DIAMONDTRAPS" << std::endl;
	DiamondTrap d1("oi"); //default
	DiamondTrap d2(d1);   //copy
	std::cout << "DBG : WHO IS d1 ?" << std::endl;
	d1.whoAmI();
	d1.takeDamage(99);
	std::cout << "DBG : d1 attacks 50 times if inheritance was correctly done. att_count = 0" << std::endl;
	std::string dummy = "dummy target";
	i = 0;
	while (d1.getEp() != 0)
	{
		d1.attack(dummy);
		i++;
	}
	std::cout << "att_count = " << i << std::endl;
	std::cout << "DBG : WHO IS d2 ?" << std::endl;
	d2.whoAmI();
	return 0;
}
