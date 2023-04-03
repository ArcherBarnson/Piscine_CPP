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

int	all_strings_empty(char **av)
{
	int	i = 0;

	while (av[++i])
	{
		if (is_empty_str(av[i]) == 0)
			return (0);
	}
	return (1);
}

void	toupper_str(char *str)
{
	int	i = -1;

	while (str[++i])
		str[i] = toupper(str[i]);
	return ;
}

int	main(int ac, char **av)
{
	int	i = 0;
	char	std_msg[39] = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	if (ac == 1 || all_strings_empty(av) == 1)
		std::cout << std_msg;
	else
	{
		while (av[++i])
		{
			if (is_empty_str(av[i]) == 0)
			{
				toupper_str(av[i]);
				std::cout << av[i];
			}
			if (av[i + 1] && !is_empty_str(av[i]))
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}
