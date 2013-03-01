/************************************************************/
// Drew Koelling
// 3/21/2012
// b
//
// to use stacks to perform an algorithm
/************************************************************/
#include <cstdlib>
#include <iostream>
#include "queen.h"
#include <stack>
#include <vector>
using namespace std;
int main(){
	// prompt statment
	int n;
	cout << "Please enter N for the size of the NxN(3-8), ie an input of 5 will make a 5x5 board" << endl;
	cin >> n;
	cin.ignore();
	cout << endl;
	while(n < 3 || n > 8){
		cout << "Please enter a number between 3 and 8" << endl;
		cin >> n;
		cin.ignore();
		cout << endl;
	}

	stack<queen> s;// the actual stack to hold the queens
	vector<queen> board; // used to refrence previous values
	bool solution = false;
	bool hasFailed = false;
	/*
	queen test(1,4);
	queen testa(2,1);
	queen testb(4,2);
	queen testc (6,3);
	queen testd (4,2);
	queen teste(1,4);

	int x =1;
	int y=4;
	int a=4;
	int b=2;
	double z;
	z = (x-a)/(y-b);
	cout << z << endl;

	cout << test.hasConflict(testa) << " " << test.hasConflict(testb) << " " << test.hasConflict(testc) << " " << test.hasConflict(testd) << " " << test.hasConflict(teste) << " " << endl; */
	


	s.push(queen(1,1));
	board.push_back(queen(1,1));
	int count = 0;


    while(solution == false && s.size() != 0){
		vector<queen>::iterator it; // declared iterator
		
		if(count > n + 10){ // to stop infinite loops
			break;
		}
		

		if(hasFailed == false && s.size() < n){
			if(s.size() == 1){
				count++;
			}
			s.push(queen(1, s.size() + 1));
			board.push_back(queen(1 , s.size()));

		}

		//this block of code is to pop a queen off the stack and change its value before putting it back on
		if(hasFailed==true){ 

			if(s.top().row < n){ // checks to make sure the queen can move down
				s.top().row += 1;
				board[s.size() -1].row += 1;
			}
			else{ // pops off the top element 
				s.pop();
				board.pop_back();
				if(s.top().row < n){
					s.top().row += 1;
					board[s.size() - 1].row +=1;

				}
				else if(s.size()- 1 != 0){
					s.pop();
					board.pop_back();
					if(s.top().row < n && s.size() != 0){
						s.top().row += 1;
						board[s.size() - 1].row +=1;

					}
					else if (s.size()-1 != 0){
						s.pop();
						board.pop_back();
						if(s.top().row < n){
							s.top().row += 1;
							board[s.size() - 1].row +=1;

						}
						else if (s.size()-1 != 0){
							s.pop();
							board.pop_back();
							if(s.top().row < n){
								s.top().row += 1;
								board[s.size() - 1].row +=1;

							}
							else if (s.size()-1 != 0){
								s.pop();
								board.pop_back();
								if(s.top().row < n){
									s.top().row += 1;
									board[s.size() - 1].row +=1;

								}
								else if (s.size()-1 != 0){
									s.pop();
									board.pop_back();
									if(s.top().row < n){
										s.top().row += 1;
										board[s.size() - 1].row +=1;

									}
									else if (s.size()-1 != 0){
										s.pop();
										board.pop_back();
							

									}
								}
							}
						}
					}
				}
			}
		}

		//

		

		// this block of code checks to see the top element has any conflicts with the queens already on the board
		hasFailed = false;
		if(s.size() != 0){
			for(it = board.begin(); it < board.end(); it++){
				if(s.top().hasConflict(*it) ){ // checks to see if the there is a conflict and make sure we arn't refering to the first queen
					hasFailed = true;
					continue;
				
				}
			
				if(hasFailed == false && s.size() == n && (it->row == board[n-1].row && it->column == board[n-1].column)){
					solution = true;
				}
			}
			//	
		
		}
		
	}
	



	if(solution == true){
		cout << "the queens position is " << endl;
		for(int i = 0; i < n; i++){
			cout << "queen " << i + 1 << " is at the position " << board[i].row << "," << board[i].column << endl;
		}
	}
	else{
		cout << "no possible solution with that n size board" << endl;
	}

	
	
	




		
	





	system("Pause");
	return 0;
}