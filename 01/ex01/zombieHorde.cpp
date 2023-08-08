/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:11:22 by bgrulois          #+#    #+#             */
/*   Updated: 2023/07/31 11:39:27 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int	i = 0;
	Zombie	*horde = new Zombie[N];
	while (i < N)
	{
		horde[i] = Zombie(name);
		//horde[i].setName(name);
		horde[i].announce();
		i++;
	}
	return (horde);
}
