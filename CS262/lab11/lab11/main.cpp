#include <cstdlib>
#include <iostream>

using namespace std;
void insertSort(int x[], int size);
void selectionSort(int x[], int size);
void swap(int &x, int &y);
//traces at bottom of code

int main(){
	int box[10] = {3, 25, 4, 1, 15, 8, 9, 7, 20, 16};
	for(int i = 0; i < 10; ++i){
		cout << box[i] << " ";
	}
	cout << endl;
	insertSort(box, 10);
	cout << endl;

	for(int i = 0; i < 10; ++i){
		cout << box[i] << " ";
	}

	system("Pause");
	return 0;
}


void swap(int& x, int &y){ // for readablity, simply swaps the number each int represents
	int temp = x;
	x = y;
	y = temp;
}



void selectionSort(int x[], int size){
	for(int i = (size - 1); i > 0; --i){// iterates backwards through array
		int largestIndex = i; // the index that points to the largest value per iteration
		int largestNum = x[i]; // sets the larges num equal to the first index of array
		for(int j=1; j != i; ++j){// only needs to start at one because we already set the largest num to 0
			
			if(x[j] > largestNum){
				largestNum = x[j]; // reassign the largest num
				largestIndex = j; // reassign the largest index
			}// end if

		} // ends the for that iteraters through to i
		
		swap(x[i], x[largestIndex]);

	}// ends the for that iterates backwards through the array
	if (x[0] > x[1]){
		swap(x[0], x[1]);
	}
}

void insertSort(int x[], int size){
	int insertValue; // holds the copy of the value to be inserted
	int insertIndex; // the index that the insert will take place at
	for(int i = 1; i < size; ++i){
		insertIndex = i; // copys the value to be inserted
		while(insertIndex > 0 && x[insertIndex-1] > x[insertIndex]){ // the insertIndex cannot be 0 or less, and the previous value is greater than the insert value. essentially a bubble sort that works backwards
			swap(x[insertIndex], x[insertIndex-1]);
			--insertIndex; // decrement the index until it either reaches the end, or finds the place where the insertvalue is supposed to go

		}
	}

}

/* traces for insertionSort//
the array box[3, 25, 4, 1, 15, 8, 9, 7, 20, 17]
insertSort(box, 10)
sets the insert value to 25
the pervious value is not greater than 25  [3 25 4 1 15 8 9 7 20 17]
sets the insert value to 4 
the pervious value is greater than 4, swaps 4 and 25 [3 4 25 1 15 8 9 7 20 17]
the pervious value is not greater than 4
sets the insert value to 1
the pervious value is greater than 1, swaps 1 and 25 [3 4 1 25 15 8 9 7 20 17]
the pervious value is greater than 1, swaps 1 and 4 [3 1 4 25 15 8 9 7 20 17]
the pervious value is greater than 1, swaps 1 and 3 [1 3 4 25 15 8 9 7 20 17]
index has reached the end
sets the insert value to 15
the pervious value is greater than 15, swaps 15 and 25 [1 3 4 15 25 8 9 7 20 17]
the pervious value is not greater than 15
sets the insert value to 8
the pervious value is greater than 8, swaps 8 and 25 [1 3 4 15 8 25 9 7 20 17]
the pervious value is greater than 8, swaps 8 and 15 [1 3 4 8 15 25 9 7 20 17]
the pervious value is not greater than 8 
sets the insert value to 9
the pervious value is greater than 9, swaps 9 and 25 [1 3 4 8 15 9 25 7 20 17]
the pervious value is greater than 9, swaps 9 and 15 [1 3 4 8 9 15 25 7 20 17]
the pervious value is not greater than 9
sets the insert value to 7
the pervious value is greater than 7, swaps 7 and 25 [1 3 4 8 9 15 7 25 20 17]
the pervious value is greater than 7, swaps 7 and 15 [1 3 4 8 9 7 15 25 20 17]
the pervious value is greater than 7, swaps 7 and 9 [1 3 4 8 7 9 15 25 20 17]
the pervious value is greater than 7, swaps 7 and 8 [1 3 4 7 8 9 15 25 20 17]
the pervious value is not greater than 7
sets the insert value to 20
the pervious value is greater than 20, swaps 20 and 25 [1 3 4 7 8 9 15 20 25 17]
the pervious value is not greater than 20
sets the insert value to 17
the pervious value is greater than 17, swaps 17 and 25 [1 3 4 7 8 9 15 20 17 25]
the pervious value is greater than 17, swaps 17 and 20 [1 3 4 7 8 9 15 17 20 25]
the pervious value is not greater than 17
reached end of array
box is now [1, 3, 4, 7, 8, 9, 15, 17, 20, 25]

the array box[1 5 8 10 13 20 24 32 45 52]
insertSort(box, 10)
set the insertvalue to 5
the pervious value is not greater than 5 [1 5 8 10 13 20 24 32 45 52]
set the insert value to 8
the pervious value is not greater than 8 [1 5 8 10 13 20 24 32 45 52]
set the insert value to 10
the pervious value is not greater than 10 [1 5 8 10 13 20 24 32 45 52]
set the insert value to 13
the pervious value is not greater than 13 [1 5 8 10 13 20 24 32 45 52]
set the insert value to 20
the pervious value is not greater than 20 [1 5 8 10 13 20 24 32 45 52]
set the insert value to 24
the pervious value is not greater than 24 [1 5 8 10 13 20 24 32 45 52]
set the insert value to 32
the pervious value is not greater than 32 [1 5 8 10 13 20 24 32 45 52]
set the insert value to 45 
the pervious value is not greater than 45 [1 5 8 10 13 20 24 32 45 52]
set the insert value to 52
the pervious value is not greater than 52 [1 5 8 10 13 20 24 32 45 52]
reached end of array
box is now[1 5 8 10 13 20 24 32 45 52]

in the average case it has a O(n^2) because it will have to access n elements and may have to swap n-1 elements which is n*n-1 which is approximatly n^2
in the best case it has a O(n) because it must access n elements in the array to see everything is already sorted

//selection sort//
the array box[3 25 4 1 15 8 9 7 20 17]
selectionSort(box 10)
sets the largest index to 9, and the largest value to 17
starts looking at index 1 and moving toward i until it reaches i, keeping track of the largest num.
finds the largest value at index 1 value 25
swaps 17 and 25 [3 17 4 1 15 8 9 7 20 25]
sets the largest index to 8, value 20
starts looking at index 1 and moving toward i until it reaches i, keeping track of the largest num.
finds there is no larger value than 20 [3 17 4 1 15 8 9 7 20 25]
sets the largest index to 7, value 7
starts looking at index 1 and moving toward i until it reaches i, keeping track of the largest num.
finds that 17 is largest at index 1
swaps 7 and 17 [3 7 4 1 15 8 9 17 20 25]
sets the largest index to 6, value 9
starts looking at index 1 and moving toward i until it reaches i, keeping track of the largest num.
finds 15 is largest num at index 4
swaps 9 and 15 [3 7 4 1 9 8 15 17 20 25]
sets the largest index to 5 value 8
starts looking at index 1 and moving toward i until it reaches i, keeping track of the largest num.
finds 9 is the largest num at index 4
swaps 8 and 9  [3 7 4 1 8 9 15 17 20 25]
sets the largest index to 4, value 8
starts looking at index 1 and moving toward i until it reaches i, keeping track of the largest num.
finds no value larger than 8 [3 7 4 1 8 9 15 17 20 25]
sets the largest index to 3, value 1
starts looking at index 1 and moving toward i until it reaches i, keeping track of the largest num.
finds 7 is the larges num at index 1
swaps 7 and 1 [3 1 4 7 8 9 15 17 20 25]
sets largest index to 2, value 4
starts looking at index 1 and moving toward i until it reaches i, keeping track of the largest num.
finds no value larger than 4  [3 1 4 7 8 9 15 17 20 25]
sets largest index to 1, value 1
starts looking at index 1 and moving toward i until it reaches i, keeping track of the largest num.
finds 3 is the largest num at index 0
swaps 1 and 3 [1 3 4 7 8 9 15 17 20 25]
box is now [1 3 4 7 8 9 15 17 20 25]

given the array box[1 5 8 10 13 20 24 32 45 52]
selectSort(box, 10)
sets the largest index to 9, value 52
starts looking at index 1 and moving toward i until it reaches i, keeping track of the largest num.
finds no number larger than 52 [1 5 8 10 13 20 24 32 45 52]
sets the largest index to 8, value 45
starts looking at index 1 and moving toward i until it reaches i, keeping track of the largest num.
finds no number larger than 45 [1 5 8 10 13 20 24 32 45 52]
sets the largest index to 7, value 32
starts looking at index 1 and moving toward i until it reaches i, keeping track of the largest num.
finds no number larger than 32 [1 5 8 10 13 20 24 32 45 52]
sets the largest index to 6, value 24
starts looking at index 1 and moving toward i until it reaches i, keeping track of the largest num.
finds no number larger than 24 [1 5 8 10 13 20 24 32 45 52]
sets the largest index to 5, value 20
starts looking at index 1 and moving toward i until it reaches i, keeping track of the largest num.
finds no number larger than 20 [1 5 8 10 13 20 24 32 45 52]
sets the largest index to 4, value 13
starts looking at index 1 and moving toward i until it reaches i, keeping track of the largest num.
finds no number larger than 13 [1 5 8 10 13 20 24 32 45 52]
sets the largest index to 3, value 10
starts looking at index 1 and moving toward i until it reaches i, keeping track of the largest num.
finds no number larger than 10 [1 5 8 10 13 20 24 32 45 52]
sets the largest index to 2, value 8
starts looking at index 1 and moving toward i until it reaches i, keeping track of the largest num.
finds no number larger than 8 [1 5 8 10 13 20 24 32 45 52]
sets the largest index to 1, value 5
starts looking at index 1 and moving toward i until it reaches i, keeping track of the largest num.
finds no number larger than 5 [1 5 8 10 13 20 24 32 45 52]

both the average case and the best case have a complexity of O(n^2). this is because it must access n-1 times, and check n-1 elements whether or not the array is sorted or not

*/