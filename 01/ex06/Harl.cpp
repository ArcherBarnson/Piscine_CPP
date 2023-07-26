/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:18:07 by bgrulois          #+#    #+#             */
/*   Updated: 2023/07/26 18:28:39 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl( void ) {
	return ;
}

Harl::~Harl( void ) {
	return ;
}

void	Harl::complain(std::string level)
{
	int	set_level = -1;
	void	(Harl::*fct_tab[4]) (void) =
		{&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	(level.compare("DEBUG") == 0 || level.compare("debug") == 0) ? set_level = 0:set_level;
	(level.compare("INFO") == 0 || level.compare("info") == 0) ? set_level = 1:set_level;
	(level.compare("WARNING") == 0 || level.compare("warning") == 0) ? set_level = 2:set_level;
	(level.compare("ERROR") == 0 || level.compare("error") == 0) ? set_level = 3:set_level;
	switch (set_level)
	{
		case (-1):
			std::cout << "***UNINTELLIGIBLE COMPUTER NOISES***" << std::endl;
			break;
		case (0):
			(this->*fct_tab[0])();
		case (1):
			(this->*fct_tab[1])();
		case (2):
			(this->*fct_tab[2])();
		case (3):
			(this->*fct_tab[3])();
			break;
	}
	return ;
}

void	Harl::_debug(void)
{
	std::cout << "MY_COMPLAIN_FUNCTION_IS_WORKING_CORRECTLY" << std::endl;
	return ;
}

void	Harl::_info(void)
{
	std::cout << "I am HARL, i wish i could say more." << std::endl;
	return ;
}

void	Harl::_warning(void)
{
	std::cout << "I am HARL, my programmer made me kind of boring don't you think ?";
	std::cout << std::endl;
	return ;
}

void	Harl::_error(void)
{
	std::cout << "I am HARL, and my programmer is lazy, look at me, i'm probably leaking memory... :(";
	std::cout << std::endl;
	return ;
}
