
#include "Date.h"
#include <iostream>

using namespace std;

Date::Date(void)
{
	month = 1;
	day = 1;
	year = 1980;
}

Date::Date(const Date& source) // all copy constructors must pass the source object by reference
{
	cout << "Inside copy constructor!\n"; // debug
	month = source.month; // copies all member varaibles
	day = source.day;
	year = source.year;

}


bool operator ==(const Date& date1, const Date& date2){ // an overloaded operator of == to make comparing date objects easier to read and understand, because it is simply a global operator, it must still use the public getters of the class to access private variables
	cout << "The == function has been called: "; // debug
	if ((date1.getDay() == date2.getDay()) && ( date1.getMonth() == date2.getMonth()) && (date1.getYear() == date2.getYear())){ // if every member variable is the same,
		return true; // return true
	}
	else{
		return false; // otherwise return false
	}
}


bool operator != (const Date& date1, const Date& date2){ // an overloaded operator to make a comparing date objects easier to read and understand, because it is a friend, it does not need to use getters
	cout << "The != function has been called: "; // debug
	if ((date1.day == date2.day) && ( date1.month == date2.month) && (date1.year == date2.year)){ // if every member varaible is the same...
		return false; // return false
	}
	else{
		return true; // otherwise, return false
	}
}

bool Date::operator < (const Date& compare){ // an overloaded operator to make comparing date objects easier to read and understand, because it is not a global operator ie not stated outside the class header or a friend of the class, we must declare it in the scope of the class becuase it acts like a member function
	cout << "The < function has been called: "; // debug
	int temp_y; // temp variable
	int temp_x; // temp variable
	if(this->year <= compare.year){ // if the year of the calling object is lessthan or equal to the comparing object
		temp_y = compare.year - this->year; // fills temp_y with the differnce between years. it is used later to see whether a comparsion of months is necessary
		if(((this->month <= compare.month) && (temp_y == 0)) || (temp_y > 0)){ // if (the calling objects month is less than the comparing object AND the difference in years is 0) OR (if the difference in years is > 0) ie no need to compare months if 5/4/12 < 3/4/15 because 2015 is much later than 2012
			temp_x = compare.month - this->month; // fill temp_x with the difference in years. it is used later to see whether a comparison of days is necessary
			if(((this->day < compare.day) && (temp_x == 0)) || (temp_x > 0)) { // if (the calling objects day is less than the comparing object AND the diffence in months is 0) OR (if the differnce in months is > 0) ie no need to compare days if 5/4/12 < 7/5/12 because july is much later than may
				return true; 
			}
		}
	}
	else{
		return false;
	}
}