/************************************************************/
// Drew Koelling
// 4/17/2012
// B
//
// To understand Binary Search Trees; Reviews file handling, dynamic arrays (optional); Learn how to use the STL sort function
/************************************************************/




/*
lesson three trace:
tree orginaly
			7
	2				10
1		5				12
	  3               11


Each indent indicates a depth of recursion
A:  
bst_remove(root, 10)
//7 node is touched
root_ptr != NULL
root_ptr->data() == 7
target > root_ptr->data()
	bst_remove(root_ptr->right(), 10)
	//10 node is touched
	root_ptr != NULL
	root_ptr->data() == 10
	target == root_ptr->data()
	root_ptr->left() == NULL
	oldroot_ptr = root_ptr
	root_ptr = root_ptr->right()
	delete oldroot_ptr 
	return true
tree is now
			7
	2				12
1		5		11
	  3

B:
bst_remove(root, 7)
// 7 node is touched
root_ptr != NULL
root_ptr->data() == target
root_ptr->left != NULL
	bst_remove_max(root_ptr->left(), 7)
	//2 node is touched
	root_ptr->right() != NULL
		bst_remove_max(root_ptr->right(), 7)
		//5 node is touched
		root_ptr->right() == NULL
		binary tree node old = root
		root = root->left()
		delete old
tree is now
			5
	2				10
1		3				12
					  11


C:
bst_remove(root, 3)
// 7 node is touched
root_ptr != NULL
target < root_ptr->data()
	bst_remove(root_ptr->left(), 3)
	// 2 node is touched
	root_ptr != NULL
	target > root_ptr->data()
		bst_remove(root_ptr->right(), 3)
		// 5 node is touched
		root_ptr != NULL
		target < root_ptr->data()
			bst_remove(root_ptr->left(), 3)
			//3 node is touched
			root_ptr != NULL
			target == root_ptr->data()
			root_ptr->left == NULL
			oldroot_ptr = root_ptr
			root_ptr = root_ptr->right() // this is NULL in this case
			delete oldroot_ptr
tree is now
			7
	2				10
1		5				12
					  11


*/
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "bst.cpp"
#include "bst.h"
#include "LoginData.h"
#include <vector>
#include <algorithm>
using namespace std;
using namespace macs262_labs;
void print_one(const LoginData& x);
void loadInLogins(LoginData z[], int& box);
void inputLoop(binary_tree_node<LoginData> *& root_ptr);

int main(){
	int count = 0;
	LoginData users[48];
	loadInLogins(users, count);
	sort(users, users+count);

	binary_tree_node<LoginData>* root = NULL;
	create_balanced(root, users, 0, count);
	//inorder(print_one, root);
	//print(root, 0);
	inputLoop(root);
	system("Pause");
	return 0;
}

void print_one(const LoginData& x){
	cout << x << endl;
}

void loadInLogins(LoginData z[], int& box){
	string x;
	string y;
	
	
	string FILE_NAME = "data.txt";
	ifstream file(FILE_NAME.c_str());
	while(!file){
		cout << "error opening file" << endl;
		exit(1);
	}
	while(file >> x >> y){
		z[box] = LoginData(x,y);
		box++;
	}
}

void inputLoop(binary_tree_node<LoginData> *& root_ptr){
	string inputUser;
	string inputPass;
	while(true){
		cout << "Please enter a username and password. You may exit by typing in 'none' without the quotes as a username\nUsername: ";
		cin >> inputUser;
		cin.ignore();
		if(inputUser == "none"){ // don't know why but while loop does not break at correct point if this line of code is not present, so instead used a while true 
			return;
		}
		cout << endl << "Password: ";
		cin >> inputPass;
		cin.ignore();
		bool validUser = search(root_ptr, LoginData(inputUser, inputPass));
		if(validUser == true){
			cout << endl << "Welcome user " << inputUser << "!" << endl;
		}
		else{
			cout << endl << "Invalid username or password." << endl;
		}
	}
}