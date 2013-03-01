/************************************************************/
// Drew Koelling
// 4/5/2012
// B
//
// To better understand recursion and see otherways to write loops. 
/************************************************************/


#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;
double sumover(int x);//working
int GCD(int x, int y);//working
void swapCharacters(char s[], int x, int y);


int main(){
	char input= 'h';
	
	while(input != 'q' && input != 'Q'){
		cout << "Please enter a command(a for GCD, b for sumover, c for reverse characters or q to quit" << endl;
		cin >> input;
		cin.ignore(2048,'\n');
		if (input == 'q' || input == 'Q')
			break;
		if(input == 'a' || input == 'A'){
			int x;
			int y;
			cout << "Please enter the numbers to enter the GCD function " << endl << "X: ";
			cin >> x;
			cout << endl << "Y: ";
			cin >> y; 
			cout << endl;
			cout << "The answer is " << GCD(x, y) << endl;
		}
		else if(input == 'b' || input == 'B'){
			int x;
			cout << "Please enter the number you would like to go into the sumover function " << endl;
			cin >> x;
			cout << endl << "The result is " << sumover(x) << endl;

		}
		else if(input == 'c' || input == 'C'){
			int x; 
			int y;
			char stuff[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
			cout << "Please enter the bounds for the swap characters " << endl << "Lower bound: ";
			cin >> x;
			cout << endl << "Upper bound: ";
			cin >> y;
			cout << endl << "The array was orginally " << endl;
			for (int i = 0; i < 25; i++){
				cout << stuff[i] << " ";
			}
			swapCharacters(stuff, x, y);
			cout << endl << "The array is now " << endl;
			for(int i = 0; i <25; i++){
				cout << stuff[i] << " ";
			}
			cout << endl;
		}
	}
	system("Pause");
	return 0;
}

double sumover(int x){ // returns the sums of the recipicals of the integers 1 to n
	if(x==0){
		return 0; 
	}
	else{
		return (1.0/x) + sumover(x-1);
	}
}

int GCD(int x, int y){
	if(x%y == 0){
		return y;
	}
	else{
		GCD(y, x%y);
	}
}

void swapCharacters(char s[], int x, int y){
	if(x >= y){
		return;
	}
	char a = s[y];
	s[y] = s[x];
	s[x] = a;
	swapCharacters(s, x+1, y-1);
}