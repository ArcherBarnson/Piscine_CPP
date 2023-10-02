/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:53:03 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/02 15:07:16 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	ct0("ct0");
	ClapTrap	ct1("ct1");

	std::cout << "DBG : 8 successive attacks by ct1" << std::endl << std::endl;
	ct1.attack("bystander");
	ct1.attack("bystander2");
	ct1.attack("bystander3");
	ct1.attack("bandit");
	ct1.attack("acceptable loss");
	ct1.attack("human");
	ct1.attack("non-human");
	ct1.attack("the pROgRaM");
	std::cout << std::endl << "DBG : ct1 takes 9hp of damage" << std::endl << std::endl;
	ct1.takeDamage(9);
	std::cout << std::endl << "DBG : ct1 repairs itself twice" << std::endl << std::endl;
	ct1.beRepaired(8);
	ct1.beRepaired(1); 
	std::cout << std::endl << "DBG : ct1 falis to attack, fails to repair" << std::endl << std::endl;
	ct1.attack("the air");
	ct1.beRepaired(1);

	std::cout << std::endl << "DBG : ct0 repairs itself for 20 hp" << std::endl << std::endl;
	ct0.beRepaired(20);
	std::cout << std::endl << "DBG : ct0 gets nuked for -1000hp" << std::endl << std::endl;
	ct0.takeDamage(1000);
	std::cout << std::endl << "DBG : ct0 cannot attack or be repaired, they have been destroyed" << std::endl << std::endl;
	ct0.attack("itself :O");
	ct0.beRepaired(1);

	std::cout << "DONE" << std::endl;
}
