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
	data = new value_type*[capacity];

}

void DrawList::insert(value_type* x){ //  may need to move const
	if(capacity - used == 0){ // should always happen unless the default capacity has not been meet
		 reserved(2*used + 1);
		
		 //data[used] = new value_type(x);
		 data[used] = x->makeClone();  // this passes value_type object to use its makeClone function, which should return a MyShape pointer. because it is virtual, only the derived classes version of makeClone will be used
		used++; // increases the used
	}// ends if
	else{
		
		//data[used] = new value_type(x) ;
		data[used] = x->makeClone(); 
		used++;
	}
}

void DrawList::remove_last(){
	assert(used != 0);
	
		delete data[used-1];
		used--;
}

std::size_t DrawList::size(){
	return used + 1;
}

void DrawList::begin(){
	current_index = 0;
}
bool DrawList::end(){
	if (current_index >= used){
		return true;
	}
	else{
		return false;
	}
}

void DrawList::operator ++(){
	current_index++;
}

DrawList::value_type* DrawList::operator *(){
	assert(!end());
	return data[current_index];
}
void DrawList::reserved(std::size_t x){
	value_type **temp;
	temp = new value_type*[x];
	
	for(std::size_t i = 0; i < (2*used+1); i++){
		temp[i] = NULL;
	} // ends for
	
	std::copy(data,data + used, temp);
	delete data;
	data = temp;
	capacity = 2*used+1;

}


DrawList::~DrawList(void)
{
	for(std::size_t i = 0; i < capacity; i++){
		delete [] data [i]; // deletes everything in the columns
		
	}
	delete [] data;// deletes everything else, no need to reassign data because DrawList is being removed, data will no longer exist is thus not a dangiling pointer.

} //because we are using dynamic memory, we must make our own assignment, copy constructor, and destructor
}// for namespace