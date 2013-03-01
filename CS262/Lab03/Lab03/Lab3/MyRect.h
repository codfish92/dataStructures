/************************************************************/
// Drew Koelling
// 2/9/12
// B
//
// This is an introduction to working with windows forms, container classes, and review of classes, arrays, overloaded operators. 
/************************************************************/


#include "Point.h"
#include "Color.h"
#pragma once
namespace macs262_labs
{
	class MyRect{
	public:
	
	// constructors
		MyRect(void);
		MyRect(const MyRect& source);
		MyRect(Point p1, Point p2, Color rgb=Color(0,0,0), bool x=true); // parameterized consturctor with default values given so MyRect(pointA, pointB) is valid because if color and filled are not given, they default to those values. color requires a color constructor because it is an ADT

	// seters
		void setFilled(bool x);
		void setPoint1(Point x);
		void setPoint2(Point x);
		void setColor(Color x);
	


	//draw
		void draw(System::Drawing::Graphics^ g);
	
	private:
		bool filled;
		Point point1;
		Point point2;
		Color color;
	
	};

}

