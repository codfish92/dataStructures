// A simple driver program to help us understand copy constructors
// and overloaded operators

/*1. The default constructor takes no pararmeters and "returns" or creates an object. The values for these objects depend on what the are set at in the default constructor. 
A regular constuctor is much like the default constructor, however it accepts parameters, which can be used to set the values in a class to specfic non default values.
a copy constructor is a constructor that takes in the same type of object and returns a copy of the object, but is a different instance of it. Passing things by value uses the copy constructor. 

2. An inline function is a function that has its definition on its declartion. It saves exectution time by having the compiler just copy that code where ever the function is called. it is commonly used on simple or functions with only one line. 

3. The copy constructor is called twice, once at DATE dupParty(party), and again at printDate(today). The former explicitly calls it, while the latter is a function that has a date object passed by value, which uses the copy constructor. 

4. The first use of == uses the equallity in a way that we defined in the implemation file, which compares two date types. the second use is comparing integers, which because we redefined == to compare date objects, not ints, it does not say "using the == function", and rather defaults to the standard == operator for two ints
because x and y are not equal, it does not pass the conditional statment x == y. 

*/

#include "Date.h"
#include <iostream>

using namespace std;

void printDate(Date date);

int main()
{
	Date today = Date(9,1,2007);
	Date party(9, 10, 2007);
	Date dupParty(party);
	if (today == party)  // == is used here
		cout << "We'll party today\n";
	else
		cout << "No party today, maybe this weekend\n";
	int x=8, y=9;
	if (x == y) // == is also used here
		cout << "Testing == on integers, is it our function?\n";
	printDate(today);
	if (party != dupParty)
		cout << "The party dates are different\n";
	else
		cout << "The party dates are the same\n";
	if (today < party)
		cout << "You have a party coming up!\n";
	if (party < today)
		cout << "You missed the party, too bad!\n";
	system("pause");
}

void printDate(Date date)
{
	cout << "Printing the date, as requested: ";
	cout << date.getMonth() << "/" << date.getDay() << "/" << date.getYear() << endl;
}

