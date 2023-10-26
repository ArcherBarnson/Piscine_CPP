#include "ScalarConverter.hpp"

char ScalarConverter::_c = 0;
int ScalarConverter::_i = 0;
float ScalarConverter::_f = 0;
double ScalarConverter::_d = 0;
char* ScalarConverter::_endbuf = NULL;

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
	
}