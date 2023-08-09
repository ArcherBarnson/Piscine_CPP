#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {
	return ;
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	return ;
}

Point::Point(Point const &src) {
	*this = src;
	return ;
}

Point & Point::operator=(Point const & other) {
	if (this != &other)
	{
		//_x = other.getX();
		//_y = other.getY();
		_x = Fixed(other._x);
		_y = Fixed(other._y);
	}
	return *this;
}

Point::~Point( void ) {
	return ;
}

Fixed const Point::getX(void) const {
	return (_x);
}

Fixed const Point::getY(void) const {
	return (_y);
}
