/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:33:50 by bgrulois          #+#    #+#             */
/*   Updated: 2023/07/26 14:46:26 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int	i,j;
	std::string std_msg = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (ac == 1)
		std::cout << std_msg;
	else
	{
		for (i = 1; av[i]; i++)
		{
			std::string str(av[i]);
			for (j = 0; str[j]; j++)
				str[j] = toupper(str[j]);
			std::cout << str;
		}
	}
	std::cout << std::endl;
	return (0);
}
