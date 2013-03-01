// FILE: point.h
// CLASS PROVIDED: Point 
#pragma once

namespace macs262_labs
{
	class Point
	{
	public:
		// CONSTRUCTORS
		// Postcondition: Point has been initialized to (0, 0)
		Point() : x(0), y(0) {}

		// Postcondition: Point has been initialized to (x, y)
		Point(float X, float Y) : x(X), y(Y) {}

		// ACCESSORS
		float getX() const { return x; }
		float getY() const { return y; }

		// MODIFIERS
		// Postcondition: Point has been moved by deltaX along the 
		// x axis and deltaY along the y axis
		void shift(int deltaX, int deltaY);

		// Postcondition: Returns true if x and y values are the same,
		// false otherwise
		bool operator !=(const Point& p2) const;
		bool operator ==(const Point& p2) const;

	private: 
		// x and y are represented in our Point class as float to
		// faciliate calculations.
		float x, y;
	};

} // end namespace
