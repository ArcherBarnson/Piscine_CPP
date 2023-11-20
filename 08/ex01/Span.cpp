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

void Span::addNumberArray(std::vector<int> array)
{
	std::vector<int>::iterator i = array.begin();
	if (array.size() + _vN.size() > _size)
		return ;		//throw excp
	for (; i != array.end(); i++)
		_vN.push_back(*i);
	return ;
}

int	Span::shortestSpan()
{
	std::vector<int>::iterator begin = _vN.begin();
	std::vector<int>::iterator end = _vN.end();
	int shortestSpan = 0;
	int currentSpan = 0;
	if (_size <= 1)
		return (currentSpan);
	std::sort(begin, end);
	int i = 0;
	for (; begin != end; end--)
	{
		currentSpan = abs(_vN[i], _vN[i + 1]);
		if (shortestSpan > currentSpan || shortestSpan == 0)
			shortestSpan = currentSpan;
		i++;
	}
	return (shortestSpan);
}

int	Span::longestSpan()
{
	if (_size <= 1)
		return (0);
	int longestSpan = (*std::max_element(_vN.begin(), _vN.end()) - *std::min_element(_vN.begin(), _vN.end()));
	return (longestSpan);
}