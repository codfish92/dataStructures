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
char swapCharacters(char s[], int x, int y);


int main(){
	char stuff[] = "abcdefghijklmnopqrstuvwxyz";
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

char swapCharacters(char s[], int x, int y){
	

}