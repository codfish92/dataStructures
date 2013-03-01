#include "Point.h"
#include "Color.h"
#include "MyShape.h"
#include "StdAfx.h"

#pragma once
namespace macs262_labs{

	class MyRect : public MyShape{
	public:
	
	// constructors
		MyRect(void);
		MyRect(const MyRect* source);
		MyRect(Point p1, Point p2, Color rgb=Color(0,0,0), bool x=true); // because MyRect still has all of its constructors from lab3, there is no need to tell it to use the MyShape constructors first

	// seters
		void setFilled(bool x);
		
	


	//draw
		 void draw(System::Drawing::Graphics^g); // a pure virtual function of MyShape, because it is a pure virtual function, it will only use the derived classes version of the function and never the base classes

	//clone
	     MyShape* makeClone() const; // a pure virtual function of MyShape, because it is a pure virtual function, it will only use the derived classes version of the function and never the base classes
	
	private:
		bool filled;
		
	
	};

}// for namespace

