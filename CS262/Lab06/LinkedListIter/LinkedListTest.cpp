// FILE: LinkedListTest.cpp
// An interactive test program for the new linkedList class
#include <cctype>       // Provides toupper
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "LinkedList.cpp"  // Provides linked list, need .cpp for template

using namespace std;
using namespace macs262_labs;

// PROTOTYPES for functions used by this test program:
void print_menu( );
// Postcondition: A menu of choices for this program has been written to cout.

char get_user_command( );
// Postcondition: The user has been prompted to enter a one character command.
// The next character has been read (skipping blanks and newline characters), 
// and this character has been returned.


double get_number( );
// Postcondition: The user has been prompted to enter a real number. The
// number has been read, echoed to the screen, and returned by the function.

void show_list(const LinkedList<double>& list);
// Postcondition: The contents of the list have been displayed
// to the terminal

int main( )
{
	LinkedList<double> test; // A linked list that we’ll perform tests on
	LinkedList<double>::node_iterator iter;

	char choice;   // A command character entered by the user
	double value; // used when removing a number from the list

	cout << "I have initialized an empty list of real numbers." << endl;

	do
	{
		print_menu( );
		choice = toupper(get_user_command( ));
		switch (choice)
		{
		case 'I': test.insertAtHead(get_number( ));
			break;
		case 'R': value = get_number();
			if (test.removeFromList(value))
				cout << "The item has been removed." << endl;
			else
				cout << "The item was not in the list." << endl;
			break;     
		case 'C': test.clearList();
			break;
		case '!': iter = test.begin( );
			break;
		case '+': ++iter;
			break;
		case '-': --iter;
			break;
		case 'N': if (iter.hasNext())
					  cout << "There is a next item" << endl;
				  else 
					  cout << "There is no next item" << endl;
			break;
		case 'P': if (iter.hasPrev())
					  cout << "There is a prev item" << endl;
				  else 
					  cout << "There is no prev item" << endl;
			break;
		case 'E': if (iter == test.end())
					  cout << "At the end" << endl;
				  else
					  cout << "Not at the end" << endl;
			break;
		case '*': if (iter == test.end())
					  cout << "No record to display!" << endl;
				  else
					  cout << *iter; 
			break;
		case 'S': show_list(test);
				break;
		case 'Q': cout << "Ridicule is the best test of truth." << endl;
			break;
		default:  cout << choice << " is invalid." << endl;
		}
	}
	while ((choice != 'Q'));

	return EXIT_SUCCESS;
}

void print_menu( )
// Library facilities used: iostream.h
{
	cout << endl; // Print blank line before the menu
	cout << "The following choices are available: " << endl;
	cout << " I   Insert a new number at the head of the list function" << endl;
	cout << " R   Remove a number from the list" << endl;
	cout << " C   Clear the list" << endl;
	cout << " !   Start at the beginning of the list" << endl;
	cout << " +   Advance to the next item" << endl;
	cout << " -   Move to the previous item" << endl;
	cout << " N   Test whether there is a next item" << endl;
	cout << " P   Test whether there is a previous item" << endl;
	cout << " *   View the current item" << endl;
	cout << " E   Test whether iterator is at the end" << endl;
	cout << " S   Show all values in the this" << endl;
	cout << " Q   Quit this test program" << endl;
}

char get_user_command( )
// Library facilities used: iostream
{
	char command;

	cout << "Enter choice: ";
	cin >> command; // Input of characters skips blanks and newline character

	return command;
}

double get_number( )
// Library facilities used: iostream
{
	double result;

	cout << "Please enter a real number for the sequence: ";
	cin  >> result;
	cout << result << " has been read." << endl;
	return result;
}

void show_list(const LinkedList<double>& list)
{
	cout << "List contents:\n";
	LinkedList<double>::const_node_iterator list_iter;
	for (list_iter = list.begin(); list_iter != list.end(); ++list_iter)
		cout << *list_iter << endl;
}

