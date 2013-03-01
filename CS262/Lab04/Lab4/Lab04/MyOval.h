#pragma once
#include "MyShape.h"
namespace macs262_labs{
class MyOval : public MyShape
{
public:
	MyOval(void) : MyShape(point1, point2, color) {}; // tells MyOval objects to use the base class' paramtrized constructor instead of its default constructor. 
	MyOval(const MyOval* source);
	MyOval(Point p1, Point p2, Color rgb=Color(0,0,0), bool x=true);
	~MyOval(void);

	void setFilled(bool x);

	void draw(System::Drawing::Graphics^g) ; // a pure virtual function of MyShape, because it is a pure virtual function, it will only use the derived classes version of the function and never the base classes
	MyShape* makeClone(void) const; // a pure virtual function of MyShape, because it is a pure virtual function, it will only use the derived classes version of the function and never the base classes, this also means that the base class is an abstract class, and no base class can be initilized. 

private:
	bool filled;
};
}// for namespace

