/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:11:07 by bgrulois          #+#    #+#             */
/*   Updated: 2023/07/26 17:58:20 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
	public:
		Zombie( void );
		Zombie( std::string name );
		~Zombie( void );

		void 	announce(void);

	private:
		std::string _name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
