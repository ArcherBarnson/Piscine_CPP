/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:56:43 by bgrulois          #+#    #+#             */
/*   Updated: 2023/10/02 13:22:27 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap(std::string const & name);
		FragTrap(FragTrap const & src);
		FragTrap &operator=(FragTrap const & other);
		~FragTrap(void);
		void	highFivesGuys();
	private:
		std::string  _name;
};

#endif
