#include "LinkedList.h"
#include <iostream>
using namespace std;

/************************************************************/
// Drew Koelling
// 2/28/2012
// b
//
// to learn how to take a linked list class and make it a templete class so it can use multiple data types without having every possiblity declared. 
/************************************************************/


namespace macs262_labs
{
	template <typename Item>
	LinkedList<Item>::LinkedList(){
		head = NULL; // no nodes in list to point to, prevents head from pointing to garbage
		size = 0; // no nodes in list
	}
	template <typename Item>
	void LinkedList<Item>::insertAtHead(const Item& entry){
		head = new node(entry, head); //will make head point to a new node, since all inserts happen at the head, no prev pointer needs to be passed in the node constructor because it will always be NULL, which it defaults to.
		size++; // now one more node in list
	}
	template <typename Item>
	bool LinkedList<Item>::removeFromList(const Item& entry){ // pretend the list is composed of [5, 10, 15, 20] 
		NodePtr remove; // makes a new node pointer for temporary storage
		for(remove = head; remove != NULL; remove = remove->next){ // will assign remove to the head [5], and then will iterate through so long as remove does not point to null [a value outside list]. will assign remove to the next value in the list after iteration[if started at 5, will go to 10 after iteration]

			if(remove->data == entry){  // if the data that remove points to is the data we want to remove

				if(remove->next == NULL){ // if remove is at the end of the list and finds entry [20]
					remove->prev->next = NULL; // will make the node at [15] point to null to show it is at the end of the list
					delete remove; 
					size--;
				}

				else if(remove->prev == NULL){ // if remove is at the beginning of the list [5]
					remove->next->prev = NULL; // tells 10 that it there is now nothing before it
					head = remove->next; // makes the head member variable the new start of the list
					delete remove;
					size--;
				}
				else{ // for examples sake, assume it is removing 10
					remove->prev->next = remove->next; // will make 5 say its next value is 15
					remove->next->prev = remove->prev; // will make 15 say its pervious value is 5
					delete remove;
					size--;
					
				}

				return true;// should exit function
			}

		}
		return false; // entry was not in the list

	}

	template <typename Item>
	void LinkedList<Item>::clearList(){ 
		NodePtr remove; // holder variable, allows you to move head and still remain on the same node
		for(int i = 0; i < size - 1; i++){ // deletes all nodes save for the very last one, could also say for(int i = 1; i < size; i++)
			remove = head; // remove is set to the first node
			head = remove->next; // head is now the second node in the list, will become the first node when remove is deleted
			delete remove; // deletes the node that remove points to, head is now the first node in the list, though it's prev pointer is incorrect, but because we are deleting everything in the list, it is not necessary to change
		} // should exit with only one node remaining
		remove = head; //sets remove to the last remaining node
		delete remove; // deletes content
		head = NULL; // makes head point to NULL instead of garbage
		size = 0; // now the list is composed of 0 nodes
	
	}

	template <typename Item>
	void LinkedList<Item>::printList(){ // this function is not for any functionallity purpouse other than printing to the console what is in the list, used only for debuging. 
		NodePtr current;
		cout << "The list contains [";
		for(current = head; current != NULL;current = current->next){
			cout << current->data << ", ";
		}
		cout << "]" << endl;

	}



} // end namespace