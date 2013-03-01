#include <iostream>
#include "StdAfx.h"
#include "MyRect.h"
#include "Point.h"
#include "Color.h"
#include <cmath>

using System::Drawing::Color;
using System::Drawing::Point;
using System::Drawing::Graphics;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace std;


namespace macs262_labs
{
MyRect::MyRect(void)
{
	filled = true;
}

MyRect::MyRect(Point p1, Point p2, Color rgb, bool x){
	point1 = p1;
	point2 = p2;
	color = rgb;
	filled = x;
}

MyRect::MyRect(const MyRect* source){
	cout << "inside copy constructer" << endl;
	point1 = source->point1;
	point2 = source->point2;
	color = source->color;
	filled = source->filled; 
}


void MyRect::setFilled(bool x) {
	filled = x; // set filled to x
}

MyShape* MyRect::makeClone() const{
	return new MyRect(this);
}




//draw function
void MyRect::draw(System::Drawing::Graphics^ g){
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
	// convert color variable from our Color class to .Net color
        // YOUR NAME FOR color MAY BE DIFFERENT
        System::Drawing::Color drawColor = color.getNetColor();

        // YOUR NAME FOR drawFilled MAY BE DIFFERENT
        if (filled)  // create solid brush for drawing
        {
            Brush^ hbr = gcnew SolidBrush(drawColor);
            g->FillRectangle(hbr, x, y, width, height);
        }
        else  // draw just outline using pen
        {
            Pen^ pen = gcnew Pen(drawColor);
            g->DrawRectangle(pen, x, y, width, height);
           }
}
}