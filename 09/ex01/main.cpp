#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "./RPN <expression>" << std::endl;
		return (1);
	}
	int res = 0;
	std::string expr = av[1];
	
	RPN calculator(expr);
	res = calculator.RPNCalculator();
	if (calculator.getErrState() != 0)
	{
		std::cout << "Error" << std::endl;
		return (2);
	}
	std::cout << res << std::endl;
	return (0);
}
