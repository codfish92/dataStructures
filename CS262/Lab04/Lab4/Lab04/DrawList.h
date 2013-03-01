#pragma once
#include <cstdlib>
#include "MyRect.h"
namespace macs262_labs{
class DrawList
{
public:
	DrawList();
	~DrawList(void);
	typedef MyShape value_type;
	static const std::size_t DEAFAULT_CAPACITY = 3;
	void insert(value_type* x);
	void remove_last();
	std::size_t size();
	void begin();
	void operator ++();
	bool end();
	DrawList::value_type* operator *();
	void reserved(std::size_t x);

private:
	std::size_t used;
	std::size_t capacity;
	std::size_t current_index;
	//value_type list[CAPACITY];
	value_type **data;
};
}
