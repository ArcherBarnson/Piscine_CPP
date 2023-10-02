/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:33:21 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/02 13:22:20 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap(std::string const & name);
		ScavTrap(ScavTrap const & src);
		ScavTrap &operator=(ScavTrap const & other);
		~ScavTrap(void);
		void	guardGate();
		void	attack(std::string &target);
	private:
		std::string _name;
};

#endif
