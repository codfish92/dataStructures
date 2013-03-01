#include "StdAfx.h"
#include "DrawList.h"
#include <assert.h>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
namespace macs262_labs{
DrawList::DrawList(void)
{
	capacity = DEAFAULT_CAPACITY;
	used = 0;
	current_index = 0;
	data = new value_type*[capacity]; // makes an array of pointers to MyRect objects 

}

void DrawList::insert(const value_type &x){ //  may need to move const
	if(capacity - used == 0){ // should always happen unless the default capacity has not been meet
		 reserved(2*used + 1);
		
		
		 data[used] = new value_type(x); // because data[used] is a pointer to a pointer, the new value_type's do not need to be pointers because new returns pointers. 

		used++; // increases the used
	}// ends if
	else{
		
		data[used] = new value_type(x) ;
		used++;
	}
}

void DrawList::remove_last(){
	assert(used != 0); // as long as something is being used
	
	
		delete data[used-1];
		used--;
}

std::size_t DrawList::size(){
	return used;
}

void DrawList::begin(){
	current_index = 0; // starts at the beggining of list
}
bool DrawList::end(){
	if (current_index >= used){ 
		return true;
	}
	else{
		return false;
	}
}

void DrawList::operator ++(){ // the member function overloaded operator
	current_index++;
}

DrawList::value_type* DrawList::operator *(){// the memver function overloaded operator
	assert(!end());
	return data[current_index];
}
void DrawList::reserved(std::size_t x){
	value_type **temp;// creates a new array of pointers to pointers
	temp = new value_type*[x]; // because we arn't refering to an index, we must make new value_type pointers, rather than just value_types
	
	for(std::size_t i = 0; i < (2*used+1); i++){
		temp[i] = NULL; // initilizes all temp pointers to point to NULL
	} // ends for
	
	std::copy(data,data + used, temp); // will copy all of the pointers to pointers in data to temp, 
	delete [] data; // deletes data, removes that allocated memory
	data = temp; // makes data point to the same thing as temp does, essentially makes data be the new larger array
	capacity = 2*used+1; // increases the capacity variable

}


DrawList::~DrawList(void)
{
	for(std::size_t i = 0; i < capacity; i++){
		delete [] data [i]; // deletes the value_type objects
		
	}
	delete [] data; // deletes the pointers themselves
} //the destructor which is necessary to remove all the allocated memory. only needed if you dynamically allocate memory. 
}// for namespace