#include "Point.hpp"
#include <iostream>

Fixed getArea(Point const a, Point const b, Point const c)
{
	Fixed ax = a.getX();
	Fixed bx = b.getX();
	Fixed cx = c.getX();
	Fixed ay = a.getY();
	Fixed by = b.getY();
	Fixed cy = c.getY();
	//float fax = ax.toFloat();
	//std::cout << "fax" << fax <<  std::endl;
	//std::cout << bx << std::endl;
	//std::cout << cx << std::endl;
	Fixed area = ((ax *(by - cy) +
			bx *(cy - ay) +
			cx *(ay - by)) / Fixed(2.0f));
	if (area < Fixed(0.0f))
		area = area - (Fixed(2.0f) * area);
	std::cout << area << std::endl;
	return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	//Fixed ax = a.getX();
	//std::cout << "AX :: " << ax << std::endl;
	Fixed abc = getArea(a, b, c);
	Fixed pbc = getArea(point, b, c);
	Fixed pac = getArea(point, a, c);
	Fixed pab = getArea(point, a, b);
	return (abc == pbc + pac + pab);
}
