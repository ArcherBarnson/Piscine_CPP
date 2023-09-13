/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:08:19 by bgrulois          #+#    #+#             */
/*   Updated: 2023/09/13 16:50:42 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
	public:
		ClapTrap(std::string const & name);
		ClapTrap(ClapTrap const &src);
		ClapTrap &operator=(ClapTrap const & other);
		~ClapTrap(void);
		void		attack(std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		std::string	getName() const;
		int		getHp();
		int		getEp();
		int		getAd();

	protected:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
};

#endif
