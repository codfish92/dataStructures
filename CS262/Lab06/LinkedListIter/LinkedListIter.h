// FORWARD ITERATORS to step through the nodes of a linked list
// A node_iterator of can change the underlying linked list through the
// * operator, so it may not be used with a const node. The
// node_const_iterator cannot change the underlying linked list
// through the * operator, so it may be used with a const node.
// WARNING:
// This classes use std::iterator as its base class;
// Older compilers that do not support the std::iterator class can
// delete everything after the word iterator in the second line:


/************************************************************/
// Drew Koelling
// 2/28/2012
// b
//
// to recieve a crash course on iterators through linked lists to use later in a game created that uses iterators
/************************************************************/

//namespace macs262_labs{

class node_iterator{
public:
	
	node_iterator(node* initial = NULL)
	{ current = initial; }

	
	Item& operator *( ) const
	{ return current->data; }

	// creates a node_iterator set to the begining of the list 
	
	node_iterator& operator ++( ) // Prefix ++
	{ 
		
		current = current->next;
		return *this;
	}



	
	node_iterator operator ++(int) // Postfix ++
	{
		node_iterator original(current);
		current = current->next;
		return original;      	  
	}

	
	node_iterator& operator --( ) // Prefix --
	{ 
		current = current->prev;
		return *this;
	}

	
	node_iterator operator --(int) // Postfix --
	{
		node_iterator original(current);
		current = current->prev;
		return original;      	  
	}

	
	bool hasNext() const
	{
		return current->next != NULL;
	}

	
	bool hasPrev() const

	{
		return current->prev != NULL;
	}

	
	bool operator ==(const node_iterator other) const
	{ return current == other.current; }

	
	bool operator !=(const node_iterator other) const
	{ return current != other.current; }

private:
	node* current;
};





class const_node_iterator{
public:
	
	const_node_iterator(const node* initial = NULL)
	{ current = initial; }

	// creates a const_node_iterator set  to the beginning of the list. 
	
	const Item& operator *( ) const
	{ return current->data; }

	
	const_node_iterator& operator ++( ) // Prefix ++
	{
		current = current->next;
		return *this;
	}

	
	const_node_iterator operator ++(int) // Postfix ++
	{
		const_node_iterator original(current);
		current = current->next;
		return original;
	}

	const_node_iterator& operator --( ) // Prefix ++
	{
		current = current->prev;
		return *this;
	}


	const_node_iterator operator --(int) // Postfix ++
	{
		const_node_iterator original(current);
		current = current->prev;
		return original;
	}


	bool operator ==(const const_node_iterator other) const
	{ return current == other.current; }

	bool operator !=(const const_node_iterator other) const
	{ return current != other.current; }
private:
	const node* current;
};

//} // for namespace
