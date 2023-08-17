#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class	Point {
	public:
		Point( void );
		Point(const float x, const float y);
		Point(Point const &src);
		Point	&operator=(Point const & other);
		~Point( void );
		Fixed const getX(void) const;
		Fixed const getY(void) const;

	private:
		Fixed const	_x;
		Fixed const	_y;

};

Fixed getArea(Point const a, Point const b, Point const c);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
