#include "Span.hpp"

int main()
{
Span sp = Span(5);
sp.addNumber(1);
sp.addNumber(10);
sp.addNumber(21);
sp.addNumber(32);
sp.addNumber(142);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}