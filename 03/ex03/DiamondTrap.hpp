/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:23:39 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/02 14:59:37 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	public:
		DiamondTrap(std::string const & name);
		DiamondTrap(DiamondTrap const & src);
		DiamondTrap &operator=(DiamondTrap const & other);
		~DiamondTrap( void );
		void	whoAmI();
		using	ScavTrap::attack;
	protected:
		std::string _name;
};

#endif
