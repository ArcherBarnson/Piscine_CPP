#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {
	return ;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	return ;
}

Point::Point(Point const &src) : _x(src._x), _y(src._y){
	//*this = src;
	return ;
}

Point & Point::operator=(Point const & other) {
	(void)other;
	/*if (this != &other)
	{
		_x = other.getX();
		_y = other.getY();
	}*/
	return *this;
}

Point::~Point( void ) {
	return ;
}

Fixed const Point::getX(void) const {
	Fixed const fx = _x;
	return (fx);
}

Fixed const Point::getY(void) const {
	Fixed const fy = _y;
	return (fy);
}
