#pragma once
#include <cstdlib>

namespace macs262_labs
{
	class LinkedList
	{
	public:
		// use a typedef to easily change type of object
		typedef double value_type;

	private:
		/***** Node class ****/

		class node
		{
		public:
			// CONSTRUCTOR
			node(const value_type& init_data=value_type( ), 
				node *next_link=NULL, node *prev_link = NULL)
			{ data = init_data; next = next_link; prev = prev_link; }

			// variables, also public since this is a private class
			value_type data;
			node *next;
			node *prev;
		};

	public:

		typedef node *NodePtr;  // declared as a convenience

		LinkedList(void);
		// Postcondition: Entry has been inserted into a new node at
		// the head of the list
		void insertAtHead(const value_type& entry);

		// Postcondition: If entry is in the list, the first occurence is
		// removed and removeFromList returns true.  If entry is not in
		// the list, removeFromList returns false.
		bool removeFromList(const value_type& entry);

	    // Postcondition: all nodes are removed from the list and returned
		// to the heap.  Head is reset to NULL. 
		void clearList();

		void printList(); // this is a custom made function to check my work

	private:

		NodePtr head;
		int size;

	};

} // end namespace