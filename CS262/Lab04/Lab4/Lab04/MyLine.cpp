#include "StdAfx.h"
#include "MyLine.h"
namespace macs262_labs{

/*
MyLine::MyLine(void){ // no need to use default constrouctor since the base class' intilizes everything we need

}
*/

MyLine::MyLine(const MyLine* source){ // returns a Myline object from a pointer, used in the makeClone function
	point1 = source->point1;
	point2 = source->point2;
	color = source->color;
}


MyShape* MyLine::makeClone() const{ // the virtual function being defined in the derived class
	return new MyLine(this);
}

void MyLine::draw(System::Drawing::Graphics^g){ // the virtual function being defined in the derived class
	System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(color.getNetColor());
    g->DrawLine(pen, point1.getX(), point1.getY(), point2.getX(), point2.getY()); 
};


MyLine::~MyLine(void)
{

}
}//for namespace
