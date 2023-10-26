#include "ScalarConverter.hpp"

char ScalarConverter::_c = 0;
int ScalarConverter::_i = 0;
float ScalarConverter::_f = 0;
double ScalarConverter::_d = 0;
char* ScalarConverter::_endbuf = NULL;


//constructors ???

ScalarConverter::ScalarConverter(void) {
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const & copy) {
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

ScalarConverter::~ScalarConverter(void) {
	return ;
}

void	ScalarConverter::convert(std::string input)
{
	int type = detectType(input);
	if (errno == ERANGE)
		//displayType(-1);
	else if (type == 0)
		//displayType(0);
	else
		switch(type)
		{
			case 1:
			{
				_d = strtod(input.c_str(), &ScalarConverter::_endbuf);
				_f = static_cast<float>(_d);
				_c = static_cast<char>(_d);
				_i = static_cast<int>(_d);
			}
			case 2:
			{
				_f = strtof(input.c_str(), &ScalarConverter::_endbuf);
				_c = static_cast<char>(_f);
				_i = static_cast<int>(_f);
				_d = static_cast<double>(_f);
			}
			/*case 3:
			{
				_i = strtoll(input.c_str(), &ScalarConverter::_endbuf, 10);
				_f = static_cast<float>(_i);
				_c = static_cast<char>(_i);
				_d = static_cast<double>(_i);
			}*/
		}
	return ;
}

int	ScalarConverter::detectType(std::string input)
{
	double n;

	n = strtod(input.c_str(), &ScalarConverter::_endbuf);
	if (_endbuf && std::strlen(_endbuf) > 1) //nan
		return 0;
	if (_endbuf && std::strlen(_endbuf) == 1 && _endbuf[1] != 'f') //not a float, handles same for double and int
		return 1;
	else
		return 2;
	return 3;				//0 -> nan, 1 -> double or int, 2 -> float, 4 -> ???
}

void ScalarConverter::display(int mode)
{
	switch(mode)
	{
		case -1:
			//out of range
		case 0:
			//nan
		case 1:
			//diaplay formated types
	}
}