#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "./PmergeMe n0 n1 n2 n3 ..." << std::endl;
		return (1);
	}
	std::list<int> unsorted;
	std::list<int> sorted;
	for (int i = 1; av[i]; i++)
	{
		if ((atoi(av[i]) == 0 && av[i][0] != '0') || atoi(av[i]) < 0 || ac < 3)
		{
			std::cout << "Error: only one nubmer given or bad arguments (program only takes positive integers)" << std::endl;
			return (2);
		}
		else
		{
			unsorted.push_back(atoi(av[i]));
		}
	}
	PmergeMe algo(unsorted);
	sorted = algo.sort();
	return (0);
}
