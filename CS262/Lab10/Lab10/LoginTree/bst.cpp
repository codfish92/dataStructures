// FILE: bst.template
// IMPLEMENTS: The binary_tree node class (see bintree.h for documentation). 
#include <cassert>    // Provides assert
#include <cstdlib>   // Provides NULL, std::size_t
#include <iomanip>    // Provides std::setw
#include <iostream>   // Provides std::cout
#include "bst.h"

namespace macs262_labs
{
	template <class Process, class BTNode>
	void inorder(Process f, BTNode* node_ptr)
		// Library facilities used: cstdlib
	{
		if (node_ptr != NULL)
		{
			inorder(f, node_ptr->left( ));
			f( node_ptr->data( ) );
			inorder(f, node_ptr->right( ));
		}
	}

	template <class Process, class BTNode>
	void postorder(Process f, BTNode* node_ptr)
		// Library facilities used: cstdlib
	{
		if (node_ptr != NULL)
		{
			postorder(f, node_ptr->left( ));
			postorder(f, node_ptr->right( ));
			f(node_ptr->data( ));
		}
	}

	template <class Process, class BTNode>
	void preorder(Process f, BTNode* node_ptr)
		// Library facilities used: cstdlib
	{
		if (node_ptr != NULL)
		{
			f( node_ptr->data( ) );
			preorder(f, node_ptr->left( ));
			preorder(f, node_ptr->right( ));
		}
	}

	template <class Item, class SizeType>
	void print(const binary_tree_node<Item>* node_ptr, SizeType depth)
		// Library facilities used: iomanip, iostream, stdlib
	{
		if (node_ptr != NULL)
		{
			print(node_ptr->right( ), depth+1);
			std::cout << std::setw(4*depth) << ""; // Indent 4*depth spaces.
			std::cout << node_ptr->data( ) << std::endl;
			print(node_ptr->left( ),  depth+1);
		}
	}    

	template <class Item>
	void tree_clear(binary_tree_node<Item>*& root_ptr)
		// Library facilities used: cstdlib
	{
		if (root_ptr != NULL)
		{
			tree_clear( root_ptr->left( ) );
			tree_clear( root_ptr->right( ) );
			delete root_ptr;
			root_ptr = NULL;
		}
	}

	template <class Item>
	binary_tree_node<Item>* tree_copy(const binary_tree_node<Item>* root_ptr)
		// Library facilities used: cstdlib
	{
		binary_tree_node<Item> *l_ptr;
		binary_tree_node<Item> *r_ptr;

		if (root_ptr == NULL)
			return NULL;
		else
		{
			l_ptr = tree_copy( root_ptr->left( ) );
			r_ptr = tree_copy( root_ptr->right( ) );
			return
				new binary_tree_node<Item>( root_ptr->data( ), l_ptr, r_ptr);
		}
	}

	template <class Item>
	size_t tree_size(const binary_tree_node<Item>* node_ptr)
		// Library facilities used: cstdlib
	{
		if (node_ptr == NULL)
			return 0;
		else 
			return 
			1 + tree_size(node_ptr->left( )) + tree_size(node_ptr->right( ));
	}    

	template <class Item>
	bool bst_remove(binary_tree_node<Item>*& root_ptr, const Item& target)
		// Precondition: root_ptr is a root pointer of a binary search tree 
		// or may be NULL for an empty tree).
		// Postcondition: If target was in the tree, then one copy of target
		// has been removed, and root_ptr now points to the root of the new 
		// (smaller) binary search tree. In this case the function returns true.
		// If target was not in the tree, then the tree is unchanged (and the
		// function returns false).
	{
		binary_tree_node<Item> *oldroot_ptr;

		if (root_ptr == NULL)
		{   // Empty tree
			return false;
		}

		if (target < root_ptr->data( ))
		{   // Continue looking in the left subtree
			// Note: Any change made to root_ptr->left by this recursive
			// call will change the actual left pointer (because the return
			// value from the left() member function is a reference to the
			// actual left pointer.
			return bst_remove(root_ptr->left( ), target);
		}

		if (target > root_ptr->data( ))
		{   // Continue looking in the right subtree.  See Note: above.
			return bst_remove(root_ptr->right( ), target);
		}

		// Added code in to trap for not found condition
		// if (target == root_ptr->data())
		// {

		if (root_ptr->left( ) == NULL)
		{   // Target was found and there is no left subtree, so we can
			// remove this node, making the right child be the new root.
			oldroot_ptr = root_ptr;
			root_ptr = root_ptr->right( );
			delete oldroot_ptr;
			return true;
		}

		// If code reaches this point, then we must remove the target from
		// the current node. We'll actually replace this target with the
		// maximum item in our left subtree.
		bst_remove_max(root_ptr->left( ), root_ptr->data( ));
		return true;
		// }
		//else  // target is not in the list	
		//	return false;
	}

	// Precondition: root != NULL
	template <class Item>
	void bst_remove_max(binary_tree_node<Item>*& root, Item& removed)
	{
		if (root->right() == NULL)
		{
			removed = root->data();
			binary_tree_node<Item>* old=root;
			root = root->left();
			delete old;
		}
		else
		{
			bst_remove_max(root->right(), removed);
		}
	}

	

	template <class Item>
	bool search(binary_tree_node<Item>* root, const Item& entry)
	{
		if (root != NULL)
		{
			if (root->data() == entry) 
				return(true);
			return (search(root->left( ), entry) || 
				search(root->right(), entry));
		}
		return false;
	}

	template <class Item>
      void insert(binary_tree_node<Item>*& root_ptr, Item& entry){
		  // will handle an insert command on an empty tree
		 if (root_ptr == NULL){
			  root_ptr = new binary_tree_node<Item>(entry, NULL, NULL);
		 }

		 else if(entry < root_ptr->data()){
			 insert(root_ptr->left(), entry);
		 }
		 else{
			 insert(root_ptr->right(), entry);
		}
	  }

	template <class Item, class SizeType> // values is the array
    void create_balanced(binary_tree_node<Item>*& root_ptr, Item* values,
        SizeType first, SizeType size){
			if(size == 0){
				root_ptr = NULL;
				return;
			}
			else{
				int middle = first + size/2;
				insert(root_ptr, values[middle]);
				create_balanced(root_ptr->left(), values, first, size/2);
				create_balanced(root_ptr->right(), values, middle+1, (size-1)/2);
			}

	}


}
