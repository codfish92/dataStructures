#pragma once
#include "Point.h"
#include "Color.h"
#include "MyShape.h"

namespace macs262_labs{
class MyLine : public MyShape
{
public:
	MyLine(void): MyShape(point1,point2,color) {}; // this tells it to use the MyLine construter after the base class has used its paramtrized constroctor
	MyLine(const MyLine* source); 
	~MyLine(void);

	void draw(System::Drawing::Graphics^g) ; // a pure virtual function of MyShape, because it is a pure virtual function, it will only use the derived classes version of the function and never the base classes
	MyShape* makeClone(void) const ; // a pure virtual function of MyShape, because it is a pure virtual function, it will only use the derived classes version of the function and never the base classes

	

};
}// for namespace

