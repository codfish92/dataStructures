// FILE: Color.h
// CLASS PROVIDED: Color
// AUTHOR: C Rader

#pragma once

namespace macs262_labs
{
	class Color
	{
	public:
		// CONSTRUCTORS
		// Default constructor initializes Color object to black
		Color() : red(0), green(0), blue(0) {} 

		// Initializes Color object based on integer parameters
		Color(int r, int g , int b) : red(r), green(g), blue(b) {}
		
		// MODIFIERS
		// Postcondition: Sets color based on r/g/b values of .Net Color parameter
		void setColor(System::Drawing::Color newColor)
			{ red = newColor.R; green = newColor.G; blue = newColor.B; }

		// ACCESSORS
		// Postcondition: The value returned is the Red component of the color
		int getRed() const { return red; }

		// Postcondition: The value returned is the Blue component of the color
		int getBlue() const { return blue; }

		// Postcondition: The value returned is the Green component of the color
		int getGreen() const { return green; }

		// Postcondition: The value returned is an equivalent .Net color object
		System::Drawing::Color getNetColor() const
			{ return System::Drawing::Color::FromArgb(red, green, blue); }

		// OPERATORS
		bool operator !=(const Color& c2) const
			{ return (red != c2.red || green != c2.green || blue != c2.blue); }

		bool operator ==(const Color& c2) const
			{ return (red == c2.red && green == c2.green && blue == c2.blue); }


	private:
		int red, green, blue; 
	};
} // end namespace
