/////////////////////////////////////////////////////////////////
// showTree is simply used to create a BST, display it to the 
// screen as a tree, and do inorder, preorder and postorder 
// traversals.
//////////////////////////////////////////////////////////////////
#include <iostream>
#include "bst.cpp"
#include <fstream>
#include <cstdlib>

using namespace macs262_labs;
using namespace std;

void print_one(int n)
{
  cout << n << endl;
}

void draw_menu()
{
  cout << "1 - Inorder traversal\n";
  cout << "2 - Preorder traversal\n";
  cout << "3 - Postorder traversal\n";
  cout << "4 - Redraw tree\n";
  cout << "5 - Exit\n";
}

int main()
{
  binary_tree_node<int>* tree=NULL;
  ifstream fin;
  int value;

  do 
    {
      cout << "Enter another integer or 0 to print tree: ";
      cin >> value;
      if (value != 0)
      insert(tree, value);
    } while (value != 0);

  print(tree, 0);
  
  int choice;
  do 
    {
      draw_menu();
      cin >> choice;
      switch (choice)
	{
	case 1:
	  cout << "Inorder Traversal\n";
	  inorder(print_one, tree);
	  break;
	case 2:
	  cout << "Preorder Traversal\n";
	  preorder(print_one, tree);
	  break;
	case 3:
	  cout << "Postorder Traversal\n";
	  postorder(print_one, tree);
	  break;
	case 4:
	  cout << "The Tree\n";
	  print(tree, 0);
	  break;
	case 5:
	  break;
	default:
	  cout << "Invalid choice!\n";
	  break;
	}      
    } while (choice != 5);
  
}