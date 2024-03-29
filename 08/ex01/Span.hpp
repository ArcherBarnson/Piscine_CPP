#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <iterator>
# include <algorithm>

class Span {
	public:
		Span( void );
		Span(unsigned int N);
		Span(Span const & copy);
		Span &operator=(Span const & other);
		~Span( void );
		int abs(int a, int b);
		void addNumber(int n);
		void addNumberArray(std::vector<int> array);
		int shortestSpan();
		int longestSpan();
	private:
		std::vector<int> _vN;
		unsigned int _size;
};

#endif