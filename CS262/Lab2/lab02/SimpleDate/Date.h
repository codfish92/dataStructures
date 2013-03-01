#pragma once


class Date
{
public:
	Date(void);
	Date(int m, int d, int y) : month(m), day(d), year(y) {}
	Date(const Date&);
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getYear() const { return year; }
	bool operator <(const Date& compare); // acts like a member function, so it must be declared in the scope of the class, also assumes that the a class is on the left hand side of the operator. 
	friend bool operator!=(const Date& date1, const Date& date2); // does not require getters due to the friend, and is considerd a global function so it does not require the scope of the class

private:
	int month, day, year;
};

bool operator ==(const Date& date1, const Date& date2); // global function, does not need to be declared in the scope of the class, but still must use getters
//all overloaded operators are stated in the implementation file