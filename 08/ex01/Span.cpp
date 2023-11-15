#include "Span.hpp"

Span::Span(void){
	return ;
}

Span::Span(unsigned int N) {
	_size = N;
}

Span::Span(Span const & copy) {
	this->_vN = copy._vN;
	this->_size = copy._size;
	return ;
}

Span & Span::operator=(Span const & other) {
	this->_vN = other._vN;
	this->_size = other._size;
	return *this;
}

Span::~Span(void) {
	return ;
}

int	Span::abs(int a, int b)
{
	if (a - b < 0)
		return ((a - b) * -1);
	return (a - b);
}

void Span::addNumber(int n)
{
	if (_vN.size() == _size)
		return ;		//throw excp
	else
		_vN.push_back(n);
	return ;
}

int	Span::shortestSpan()
{
	std::vector<int>::iterator i = _vN.begin();
	std::vector<int>::iterator j = _vN.begin();
	j++;
	int shortestSpan = abs(*i, *j);
	if (_vN.size() <= 0)
		return (-1);	//throw excp
	i = _vN.begin();
	for (; i < _vN.end(); i++)
	{
		for (; j < _vN.end(); j++)
		{
			if (abs(*i, *j) < shortestSpan && *j != *i)
			{
				shortestSpan = abs(*i, *j);
			}
		}
		j = _vN.begin();
	}
	return (shortestSpan);
}

int	Span::longestSpan()
{
	int max = 0;
	int longestSpan;
	std::vector<int>::iterator i = _vN.begin();
	if (_vN.size() <= 0)
		return (-1);	//throw excp
	for (; i < _vN.end(); i++)
	{
		if (*i > max)
			max = *i;
	}
	i = _vN.begin();
	longestSpan = max - *i;
	for (; i < _vN.end(); i++)
	{
		if (max - *i > longestSpan)
			longestSpan = max - *i;
	}
	return (longestSpan);
}