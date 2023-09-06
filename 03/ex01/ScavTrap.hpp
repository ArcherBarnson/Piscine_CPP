/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:54:22 by bgrulois          #+#    #+#             */
/*   Updated: 2023/09/06 10:54:58 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(std::string const & name);
		ScavTrap(ScavTrap const & src);
		ScavTrap &operator=(ScavTrap const & other);
		~ScavTrap(void);
		void	guardGate();
	private:
		std::string const & _name;
};

#endif
