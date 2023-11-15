#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <iterator>

class Span {
	public:
		Span( void );
		Span(unsigned int N);
		Span(Span const & copy);
		Span &operator=(Span const & other);
		~Span( void );
		int abs(int a, int b);
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
	private:
		std::vector<int> _vN;
		unsigned int _size;
};

#endif