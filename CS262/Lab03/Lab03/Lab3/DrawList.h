#pragma once
#include <cstdlib>
#include "MyRect.h"
namespace macs262_labs{
class DrawList
{
public:
	DrawList();
	~DrawList(void);
	typedef MyRect value_type; // allows MyRect objects to be referenced by value_type, ie MyRect bob is the same as saying value_type bob
	static const std::size_t DEAFAULT_CAPACITY = 3; // the initial capacity of the dynamic array
	void insert(const value_type &x); 
	void remove_last();
	std::size_t size(); // std::size_t is just a non negative integers
	void begin();
	void operator ++(); // a member function operator, so it will require a scope
	bool end();
	DrawList::value_type* operator *(); // a member function operator, so it will require a scope. 
	void reserved(std::size_t x);// allocates memeory for dynamic array

private:
	std::size_t used;
	std::size_t capacity;
	std::size_t current_index;
	//value_type list[CAPACITY];
	value_type **data; // a pointer to a pointer of an array
};
}
