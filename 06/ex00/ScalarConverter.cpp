/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:59:38 by bgrulois          #+#    #+#             */
/*   Updated: 2023/11/20 14:05:29 by bgrulois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char _c = 0;
long int _i = 0;
float _f = 0;
double _d = 0;
char* _endbuf = NULL;

ScalarConverter::ScalarConverter(void) {
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const & copy) {
	*this = copy;
	return ;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter(void) {
	return ;
}

void	ScalarConverter::convert(std::string input)
{
	int type = detectType(input);
	switch(type)
	{
		case 0:
		{
			_c = -1;
			_d = DBL_MAX + 1;
			_i = 2147483648;
			_f = _d;
			break ;				//pire technique de gestion de cas particulier du mois mdr (ca marche bien)
		}
		case 1:
		{
			_f = strtof(input.c_str(), &_endbuf);
			_c = static_cast<char>(_f);
			_i = static_cast<long>(_f);
			_d = static_cast<double>(_f);
			break ;
		}
		case 2:
		{
			_d = strtod(input.c_str(), &_endbuf);
			_f = static_cast<float>(_d);
			_c = static_cast<char>(_d);
			_i = static_cast<long>(_d);
			break ;
		}
			
	}
	displayEval();
	return ;
}

int	detectType(std::string input)
{
	double n;

	n = strtod(input.c_str(), &_endbuf);
	if ((input == _endbuf) || (_endbuf && std::strlen(_endbuf) > 1)
		|| (_endbuf && std::strlen(_endbuf) == 1 && _endbuf[0] != 'f')) //nan
		return 0;
	if (_endbuf && std::strlen(_endbuf) == 1 && _endbuf[0] == 'f') //not a float, handles same for double and int
		return 1;
	else
		return 2;
	(void)n;
	return 3;				//0 -> nan, 2 -> double or int, 1 -> float, 4 -> ???
}

void displayEval(void)
{
	std::cout << "char : ";
	if (_d < 32 || _d > 126)
		std::cout << "non printable" << std::endl;
	else if (_d < 0 || _d > 255)
		std::cout << "impossible" << std::endl;
	else
		std::cout << _c << std::endl;
	std::cout << "int : ";
	if (_i > INT_MAX || _i < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << _i << std::endl;
	if (_c == -1)
	{
		std::cout << "float : nan" << "f" << std::endl;
		std::cout << "double : nan" << std::endl;
	}
	else
	{
		std::cout << "float : " << std::fixed << std::setprecision(1) << _f << "f" << std::endl;
		std::cout << "double : " << std::fixed << std::setprecision(1) << _d << std::endl;
	}
	return ;
}