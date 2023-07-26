/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:04:49 by bgrulois          #+#    #+#             */
/*   Updated: 2023/07/26 17:06:59 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	std::cout << "Calling randomChump(stack alloc)" << std::endl;
	randomChump("z1");

	std::cout << "Calling newZombie(heap alloc)" << std::endl;
	Zombie	*z2 = newZombie("z2");

	std::cout << "Deleting z2 (free heap allocated zombie class z2)" << std::endl;
	delete z2;
	return (0);
}
