/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:52:13 by bgrulois          #+#    #+#             */
/*   Updated: 2023/09/06 10:52:33 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
