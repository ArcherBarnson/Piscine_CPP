#include "Point.hpp"
#include <iostream>

Fixed getArea(Point const a, Point const b, Point const c)
{
	Fixed area = (a.getX() * (b.getY() - c.getY()) +
			b.getX() * (c.getY() - a.getY()) +
			c.getX() *(a.getY() - b.getY())) / Fixed(2.0);
	if (area < 0)
		area = -area;
	return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed abc = getArea(a, b, c);
	Fixed pbc = getArea(point, b, c);
	Fixed pac = getArea(point, a, c);
	Fixed pab = getArea(point, a, b);
	return (abc == pbc + pac + pab);
}
