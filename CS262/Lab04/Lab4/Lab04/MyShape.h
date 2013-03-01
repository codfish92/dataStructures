#pragma once
#include "Point.h"
#include "Color.h"
#include "StdAfx.h"
#include <cmath>


namespace macs262_labs{
class MyShape{
public:
	//constructors
	MyShape(void);
	MyShape(Point p1, Point p2, Color rgb=Color(0,0,0));
	~MyShape(void);

	//setters
	void setPoint1(Point x);
	void setPoint2(Point x);
	void setColor(Color x);

	
	//others
	virtual void draw(System::Drawing::Graphics^g) = 0; // a pure virtual function of MyShape, because it is a pure virtual function, it will only use the derived classes version of the function and never the base classes
	virtual MyShape* makeClone(void) const = 0; // a pure virtual function of MyShape, because it is a pure virtual function, it will only use the derived classes version of the function and never the base classes

protected:
	Point point1;
	Point point2;
	Color color;
};
}// for namespace

