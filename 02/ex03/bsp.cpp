#include "Point.hpp"
#include <iostream>

Fixed getArea(Point const a, Point const b, Point const c)
{
	const Fixed ax = a.getX();
	const Fixed bx = b.getX();
	const Fixed cx = c.getX();
	float fax = ax.toFloat();
	std::cout << "fax" << fax <<  std::endl;
	std::cout << bx << std::endl;
	std::cout << cx << std::endl;
	//const Fixed area = (a.getX() * (b.getY() - c.getY()) +
	//		b.getX() * (c.getY() - a.getY()) +
	//		c.getX() *(a.getY() - b.getY())) / Fixed(2.0f);
	//if (area < 0)
	//	area = area - (Fixed(2.0f) * area);
	return (ax);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed ax = a.getX();
	std::cout << "AX :: " << ax << std::endl;
	Fixed abc = getArea(a, b, c);
	Fixed pbc = getArea(point, b, c);
	Fixed pac = getArea(point, a, c);
	Fixed pab = getArea(point, a, b);
	return (abc == pbc + pac + pab);
}
