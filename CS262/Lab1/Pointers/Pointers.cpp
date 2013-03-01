/************************************************************/
// Drew Koelling
// 1/20/12
// B
//
// learn about memory leaks, and work with pointers. 
/************************************************************/

#include <iostream>
#include <cstdlib>
#define NDEBUG
#include <cassert>
using namespace std;

int main()
{
	int value = 0; 
	cout << "Please enter a value between 1 and 9: ";
	cin >> value; 

	assert(value != 0);
	//1. The program hits an error that causes the program to break. It happens because the assert condition failed, in this case, value != 0 was false, because value was = to 0


	cout << "Decimal result of 1/" << value << " is " << 1/value << endl;
	//2. Because 1 and value are both integers, so this is a case of integer division. integers cannot contain a decimal point, and integer division returns an integer. if the number is not an integer, it gets reduced to the first whole number it has
	// for example 4/5 is 0.8, but because 0.8 is not a whole number, the integer division returns 0. if it was 8/5 which is 1.6, it would just return 1. making value a double will fix this. 
	// Note: if you make value 1, 1/1 returns 1, not 0. 

	//
	cout << endl; // seperates blocks of code
	//
	
	int *ptr;
	ptr = new int;
	*ptr = 5;
	cout << *ptr << endl;
	/*
	ptr = NULL;
	//3. This is a memory leak beacause we have allocated memory to store the value 5, but then have the pointer change where it is pointing, so the allocated memory is now useless. 

	
	assert(ptr != NULL);
	cout << *ptr << endl;
	//4. There is an error when the compiler trys to present the value in NULL, which is nothing.  
	*/
	
	delete ptr;
	cout << *ptr << endl;
	// 5. This is a case of a dangling pointer. The content that the pointer pointed to was deleted so it was filled with other junk. However we did not change what the pointer points to, so it just points to junk now
	// I would say that this is not as bad as a memory leak because you can reasign a dangling pointer with ease, but it is much harder to try to assign a pointer to an allocated memory address that has been leaked. 

	double **dptr;

	dptr = new double*[5];
	for (int i=0; i<5; ++i)
	   dptr[i] = new double[3];
	for (int i=0; i<5; ++i)
    for (int j=0; j<3; ++j)
        dptr[i][j] = 1.5;
	for(int i = 0; i < 5; i++){
		delete [] dptr [i];
	}
	delete [] dptr;

	


// 6. 5 rows


// 7. there are 3 columns

    // Pause and exit the program
    system("Pause");
    return 0;
} 