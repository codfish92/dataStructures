#include "StdAfx.h"
#include "MyOval.h"

namespace macs262_labs{
/*
MyOval::MyOval(void)
{
	filled = true;
}
*/

MyOval::MyOval(Point p1, Point p2, Color rgb, bool x){ // will fill most variables from the base class's constructor. 
	point1 = p1;
	point2 = p2;
	color = rgb;
	filled = x;
}

MyOval::MyOval(const MyOval* source){
	point1 = source->point1;
	point2 = source->point2;
	color = source->color;
	filled = source->filled;
}

MyShape* MyOval::makeClone() const{ // the virtual function being defined in the base class
	return new MyOval(this);
}

void MyOval::setFilled(bool x){
	filled = x;
}

void MyOval::draw(System::Drawing::Graphics^g){ // the virtual function being defined in the base class 
	float width; // variable declartion
	float height;
	float x;
	float y;
	width = fabs(point1.getX() - point2.getX());
	height = fabs(point1.getY() - point2.getY());
	if(point1.getX() <= point2.getX()){
		x = point1.getX();
	}
	else{
		x = point2.getX();
	}
	if(point1.getY() <= point2.getY()){
		y = point1.getY();
	}
	else{
		y  = point2.getY();
	}
	if (filled==true)
        {
            System::Drawing::Brush^ hbr = gcnew System::Drawing::SolidBrush(color.getNetColor());
            g->FillEllipse(hbr, x, y, width, height);
        }
        else   // draw just outline using pen
        {
            System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(color.getNetColor());
            g->DrawEllipse(pen, x, y, width, height);
        }
}


MyOval::~MyOval(void)
{
}

}// for namespace