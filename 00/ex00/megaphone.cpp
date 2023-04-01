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
	char	std_msg[21] = "LOUD NOISES WHATEVER";

	if (ac == 1)
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
			else
				std::cout << std_msg;
			if (av[i + 1])
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}
