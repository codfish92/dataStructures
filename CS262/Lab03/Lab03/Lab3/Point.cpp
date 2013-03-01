#include "Point.h"

namespace macs262_labs
{

	void Point::shift(int deltaX, int deltaY)
	{
		x += deltaX; 
		y += deltaY; 
	}

	bool Point::operator !=(const Point& p2) const
	{
		return (x != p2.x || y != p2.y); 
	}

	bool Point::operator ==(const Point& p2) const
	{
		return (x == p2.x && y == p2.y);
	}

}
