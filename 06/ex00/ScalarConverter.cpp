#include "ScalarConverter.hpp"

char ScalarConverter::_c = 0;
long int ScalarConverter::_i = 0;
float ScalarConverter::_f = 0;
double ScalarConverter::_d = 0;
char* ScalarConverter::_endbuf = NULL;


//constructors ???

ScalarConverter::ScalarConverter(void) {
	return ;
}

/*ScalarConverter::ScalarConverter(ScalarConverter const & copy) {
	_c = copy._c;
	_i = copy._i;
	_f = copy._f;
	_d = copy._d;
	_endbuf = copy._endbuf;
	return ;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & other) {
	_c = other._c;
	_i = other._i;
	_f = other._f;
	_d = other._d;
	//_endbuf = new char*(other._endbuf);
	return *this;
}
//// aucun sens
*/
ScalarConverter::~ScalarConverter(void) {
	return ;
}

void	ScalarConverter::convert(std::string input)
{
	int type = detectType(input);
	//std::cout << type << std::endl;
	if (errno == ERANGE)
		display(-1);
	else if (type == 0)
		display(0);
	else
	{	
		switch(type)
		{
			case 1:
			{
				_f = strtof(input.c_str(), &ScalarConverter::_endbuf);
				_c = static_cast<char>(_f);
				_i = static_cast<long>(_f);
				_d = static_cast<double>(_f);
				break ;
			}
			case 2:
			{
				_d = strtod(input.c_str(), &ScalarConverter::_endbuf);
				_f = static_cast<float>(_d);
				_c = static_cast<char>(_d);
				_i = static_cast<long>(_d);
				break ;
			}
			
		}
		displayEval();
	}
	return ;
}

int	ScalarConverter::detectType(std::string input)
{
	double n;

	n = strtod(input.c_str(), &ScalarConverter::_endbuf);
	//std::cout << _endbuf << std::endl;
	if ((_endbuf && std::strlen(_endbuf) > 1)
		|| (_endbuf && std::strlen(_endbuf) == 1 && _endbuf[0] != 'f')) //nan
	{
		std::cout << "n= " << n << std::endl;
		return 0;
	}
	if (_endbuf && std::strlen(_endbuf) == 1 && _endbuf[0] == 'f') //not a float, handles same for double and int
		return 1;
	else
		return 2;
	(void)n;
	return 3;				//0 -> nan, 2 -> double or int, 1 -> float, 4 -> ???
}

void ScalarConverter::displayEval(void)
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
	std::cout << "float : " << std::fixed << std::setprecision(1) << _f << "f" << std::endl;
	std::cout << "double : " << std::fixed << std::setprecision(1) << _d << std::endl;
	return ;
}

void ScalarConverter::display(int mode)
{
	switch(mode)
	{
		case -1:
		{
			std::cout << "char : impossible" << std::endl;
			std::cout << "int : impossible" << std::endl;
			std::cout << "float : nanf" << std::endl;
			std::cout << "double : nan" << std::endl;
			std::cout << "hint - input out of range" << std::endl;
			break;
		}
		case 0:
		{
			std::cout << "char : impossible" << std::endl;
			std::cout << "int : impossible" << std::endl;
			std::cout << "float : nanf" << std::endl;
			std::cout << "double : nan" << std::endl;
			break;
		}
		case 1:
		{
			displayEval();
		}
	}
}

/*std::ostream &operator<<(std::ostream &outfile, ScalarConverter const &s)
{

}*/
