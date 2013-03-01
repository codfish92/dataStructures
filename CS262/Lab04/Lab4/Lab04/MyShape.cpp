#include "StdAfx.h"
#include "MyShape.h"
namespace macs262_labs{

MyShape::MyShape(void){
	point1 = Point(10, 10);
	point2 = Point(100, 100);
	color = Color(0, 0, 0);
}



MyShape::MyShape(Point p1, Point p2, Color rgb){
	point1 = p1;
	point2 = p2;
	color = rgb;
}

void MyShape::setPoint1(Point x){
	point1 = x; // makes point1 using point x as value
}

void MyShape::setPoint2(Point x){
	point2 = x; // makes point1 using point x as value
}

void MyShape::setColor(Color x){
	color = x;
}



MyShape::~MyShape(void){

}

}// for name space