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
MyRect::MyRect(void) // defualt constructor
{
	point1 = Point(10, 10);
	point2 = Point(100, 100);
	color = Color(0, 0, 0);
	filled = true;
}

MyRect::MyRect(Point p1, Point p2, Color rgb, bool x){ // paramatrized constructor
	point1 = p1;
	point2 = p2;
	color = rgb;
	filled = x;
}

MyRect::MyRect(const MyRect& source){ // copy constructor
	cout << "inside copy constructer" << endl; // debug
	point1 = source.point1;
	point2 = source.point2; 
	color = source.color;
	filled = source.filled; 
}


void MyRect::setFilled(bool x) {
	filled = x; // set filled to x
}


void MyRect::setPoint1(Point x){
	point1 = x; // makes point1 using point x as value
}


void MyRect::setPoint2(Point x){
	point2 = x;// similar to setPoint1, but to point 2
}



void MyRect::setColor(Color x){
	color = x; // sets color to x
}




//draw function

void MyRect::draw(System::Drawing::Graphics^ g){
	float width; // variable declartion
	float height;
	float x;
	float y;
	width = fabs(point1.getX() - point2.getX()); // the absoulute value of the differences in x position, gives width
	height = fabs(point1.getY() - point2.getY()); // the absolute value of the differnce in y postition of points, gives height
	if(point1.getX() <= point2.getX()){ // will set the left most point, remember that higher x value means more to the right
		x = point1.getX();
	}
	else{
		x = point2.getX();
	}
	if(point1.getY() <= point2.getY()){ // will set the top most point, remember that higher y value means more to the bottom.
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