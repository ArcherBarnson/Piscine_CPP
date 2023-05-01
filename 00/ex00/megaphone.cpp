/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:33:50 by bgrulois          #+#    #+#             */
/*   Updated: 2023/04/03 10:44:19 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	is_empty_str(char *str)
{
	int	i = -1;

	while (str[++i])
	{
		if (str[i] != ' ')
			return (0);
	}
	return (1);
}

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
			for (j = 0; av[i][j]; j++)
				std::cout << (char)toupper(av[i][j]);
		}
	}
	std::cout << std::endl;
	return (0);
}
