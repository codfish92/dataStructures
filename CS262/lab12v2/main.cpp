/************************************************************/
// Drew Koelling
// 5/1/2012
// B
//
//   Apply your programming skills to better understand and analyze the most important issues concerning the endangered species
//	 Use various template classes from the C++ Standard Template Library.

/************************************************************/


#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <iomanip>
#include <vector>
#include <map>
#include "eainfo.h"
#include <string>
#include <algorithm>



using namespace std;
using namespace macs262_labs;

typedef map<string, vector<string>> innerMap;
typedef map<string, innerMap> outterMap;

const string FILE_NAME = "eainfo.txt";
void eaSpecRegion(outterMap x, string place);
void eaSpecSpecies(outterMap x, string animal);
void eaSpecDangerNumber(outterMap x);
void eaDelete(outterMap &x, string place, string animal);
void eaSpecLessThan10K(outterMap x, string type);
bool lessThan10K(string x);
void eaAliveCount(outterMap x);
void eaThreat(outterMap x);
int main(){

	
	
	
	outterMap area;// global outer map
	innerMap inMapNA;// the individual maps for each region
	innerMap inMapSA;
	innerMap inMapAS;
	innerMap inMapAF;
	innerMap inMapAU;
	innerMap inMapAA;
	innerMap inMapEU;
	
	string input; // the input holder
	



	ifstream myFile(FILE_NAME.c_str());// the following block loads in the file and puts the contents into the map
	while(!myFile){ // checks to make sure the file loads
		cerr << "File not found.";
		exit(1);
	}
	
	while(myFile.good()){
		getline(myFile, input);
		//cout << "got the file";
		string region; // holds the name of the continetnt
		string name; // holds the animal name
		vector<string> stuffNA; // stuff = attributes
		vector<string> stuffSA;
		vector<string> stuffEU;
		vector<string> stuffAS;
		vector<string> stuffAU;
		vector<string> stuffAF;
		vector<string> stuffAA;
		
		
		int pipeCount = 0; // tracks where in the string the next pipe is
		int lastPipe = 0; // tracks where the last pipe in the string was
		int regionCounter = 0;
		char sep = '|'; // the pipe that seperates each value 
		//this block of code puts everything into the vector and assigns each region and animal name. this iterats through each getline
		do{
			
			lastPipe = pipeCount;// moves the last pipe to the where the pipe currently is
			pipeCount = input.find_first_of(sep, lastPipe + 1); // find the next pipe
			
			if(lastPipe > 0){
				lastPipe++; // for substr call, makes it more readable
			}
			if(regionCounter == 0){ // if this is the first substring, then it must be the region
				region = input.substr(lastPipe, (pipeCount - lastPipe));
				++regionCounter;
			}
			else if(regionCounter == 1){ // if this is the second substring, this it must be the animal name
				name = input.substr(lastPipe, (pipeCount - lastPipe));
				++regionCounter;
			}
			else if(pipeCount < input.size()){ // the rest of the attributes

				if(region == "north america"){
					stuffNA.push_back(input.substr(lastPipe, (pipeCount - lastPipe)));
				}
				else if(region == "south america"){
					stuffSA.push_back(input.substr(lastPipe, (pipeCount - lastPipe)));
				}
				else if(region == "europe"){
					stuffEU.push_back(input.substr(lastPipe, (pipeCount - lastPipe)));
				}
				else if(region == "africa"){
					stuffAF.push_back(input.substr(lastPipe, (pipeCount - lastPipe)));
				}
				else if(region == "asia"){
					stuffAS.push_back(input.substr(lastPipe, (pipeCount - lastPipe)));
				}
				else if(region == "artic and antartic"){
					stuffAA.push_back(input.substr(lastPipe, (pipeCount - lastPipe)));
				}
				else if(region == "australia"){
					stuffAU.push_back(input.substr(lastPipe, (pipeCount - lastPipe)));
				}
			}
			
		}while(pipeCount < input.size());
		// puts each vector into the inner maps
		if(region == "north america"){
			inMapNA[name] = stuffNA;
		
		}
		else if(region == "south america"){
			inMapSA[name] = stuffSA;
			
		}
		else if(region == "europe"){
			inMapEU[name] = stuffEU;
			
		}
		else if(region == "africa"){
			inMapAF[name] = stuffAF;
			
		}
		else if(region == "asia"){
			inMapAS[name] = stuffAS;
			
		}
		else if(region == "artic and antartic"){
			inMapAA[name] = stuffAA;
			
		}
		else if(region == "australia"){
			inMapAU[name] = stuffAU;
		}
		
		
		

	}
	// assigns the outermap values
	area["north america"] = inMapNA;
	area["south america"] = inMapSA;
	area["europe"] = inMapEU;
	area["asia"] = inMapAS;
	area["africa"] = inMapAF;
	area["artic and antartic"] = inMapAA;
	area["australia"] = inMapAU;
	// for input loop
	int inputB = 10;
	while(inputB != 0){
		cout << "Please enter a number to select an option: " << endl << "1. Print endangered animals across a specific region: " << endl << "2. Print the endangered animals according to type(mammal, bird, ect): " << endl << "3. Print the region with the most endangred animals: " << endl << "4. Delete the details of an endangred animal: " << endl << "5. Prints a region wise list of how many animals are below 10000 alive count: " << endl << "6. Prints the list of animals ordered from lowest alive count to most" << endl << "7. Prints the threats that face animals currently and the animals facing those threats: " << endl << "Or enter 0 to quit" << endl;
		cin >> inputB;
		cin.ignore();
		cout << endl;
	
		if(inputB == 1){
			string inputPlace;
			cout << "You have choosen to print endangered animals across a specific region" << endl << "Please enter the region you would like to print across: " ;
			getline(cin, inputPlace);
		
			cout << endl;
			eaSpecRegion(area, inputPlace);
			cout << "Enter any key to return to menu, you must put in something though";
			cin >> inputPlace;
			cin.ignore();
			cout << endl;
		}
		else if(inputB == 2){
			cout << "You have choosen to print animals according to type" << endl << "Please enter the type you would like to search for: " ;
			string inputType;
			cin >> inputType;
			cin.ignore();
			cout << endl;
			eaSpecSpecies(area, inputType);
			cout << "Enter any key to return to menu, you must put in something though";
			cin >> inputType;
			cin.ignore();
			cout << endl;
		}
		else if(inputB == 3){
			string dummy;
			eaSpecDangerNumber(area);
			cout << "Enter any key to return to menu, you must put in something though";
			cin >> dummy;
			cin.ignore();
			cout << endl;
		}
		else if(inputB == 4){
			string inputAnimal;
			string inputPlace;
			cout << "You have choosen to delete the details of an animal" << endl << "Please enter the name of the animal you would like to delete from a specific region: ";
			getline(cin, inputAnimal);
			cout << endl << "Please enter the region you would like to have the details erased from: " ;
			getline(cin, inputPlace);
			
			cout << endl;
			eaDelete(area, inputPlace, inputAnimal);
			cout << "Enter any key to return to menu, you must put in something though";
			cin >> inputAnimal;
			cin.ignore();
			cout << endl;
		}
		else if(inputB == 5){
			string inputType;
			cout << "You have choosen to print the amount of a specific type of animal that is less than 10K in its alive cound across all regions" << endl << "Please enter the type of animal: ";
			cin >> inputType;
			cin.ignore();
			cout << endl;
			eaSpecLessThan10K(area, inputType);
			cout << "Enter any key to return to menu, you must put in something though";
			cin >> inputType;
			cin.ignore();
			cout << endl;
		}
		else if(inputB == 6){
			string dummy;
			eaAliveCount(area);
			cout << "Enter any key to return to menu, you must put in something though";
			cin >> dummy;
			cin.ignore();
			cout << endl;
		}
		else if(inputB == 7){
			string dummy;
			eaThreat(area);
			cout << "Enter any key to return to menu, you must put in something though";
			cin >> dummy;
			cin.ignore();
			cout << endl;
		}
	}


	system("Pause");
	return 0;
}



void eaSpecRegion(outterMap x, string place){
	map<string, vector<string>>::iterator itIn; // iterator for interior map, the one that holds all the data as its value and the name of the animal as its key
	map<string, map<string, vector<string>>>::iterator itOut; // iterator for exterior map, the one that holds the name of the animal as its value and the region as its key
	vector<string>::iterator itData; // for the vector
	itOut = x.begin();

	while(itOut->first != place && itOut != x.end()){ // will iterate the iterator to the correct region in question
		++itOut;
	}
	cout << "Format is as such: Region, Animal, Type, Number remaining, Habitat, Threat, Lifespan " << endl;
	for(itIn = itOut->second.begin(); itIn != itOut->second.end(); ++itIn){ // the block of code that prints out everything in the specific region
		cout << itOut->first << ": " << itIn->first << " ";
		for(itData = itIn->second.begin(); itData != itIn->second.end(); ++itData){
			cout << *itData << "    ";
		}
		cout << endl;
	}
	cout << endl;


}

void eaSpecSpecies(outterMap x, string species){
	map<string, vector<string>>::iterator itIn; // iterator for interior map, the one that holds all the data as its value and the name of the animal as its key
	map<string, map<string, vector<string>>>::iterator itOut; // iterator for exterior map, the one that holds the map of the animal as its value and the region as its key
	vector<string>::iterator itData; // for the vector
	vector<string> output; // holds the output
	for(itOut = x.begin(); itOut != x.end(); ++itOut){
		for(itIn = itOut->second.begin(); itIn != itOut->second.end(); ++itIn){
			itData = itIn->second.begin();
			if(*itData == species){
					output.push_back(itIn->first);
			}
		}
	}
	sort(output.begin(), output.end());
	unique(output.begin(), output.end());
	for(itData = output.begin(); itData != output.end(); ++itData){
		cout << *itData << endl;
	}
	cout << endl;

}

void eaSpecDangerNumber(outterMap x){
	map<string, map<string, vector<string>>>::iterator itOut; // iterator for exterior map, the one that holds the name of the animal as its value and the region as its key
	int max = 0;
	int maxIndex = 0;//starts at negative one due to 0 indexing
	int count = 0;
	for(itOut = x.begin(); itOut != x.end(); ++itOut){
		if(itOut->second.size() > max){
			max = itOut->second.size();
			maxIndex = count;
		}
		++count;
	}
	count = 0;
	for(itOut = x.begin(); count < maxIndex; ++count){
		++itOut;
	}
	cout << "The Region with the most amount of endangered species is: " << itOut->first;
	cout << endl;
}
void eaDelete(outterMap &x, string place, string animal){
	map<string, vector<string>>::iterator itIn; // iterator for interior map, the one that holds all the data as its value and the name of the animal as its key
	map<string, map<string, vector<string>>>::iterator itOut; // iterator for exterior map, the one that holds the map of the animal as its value and the region as its key
	vector<string>::iterator itData; // for the vector
	itOut = x.find(place);
	itIn = itOut->second.find(animal);

	itIn->second.erase(itIn->second.begin(), (itIn->second.begin() + itIn->second.size()  ));
	itOut->second.erase(itIn);
	cout << endl;	
}

void eaSpecLessThan10K(outterMap x, string type){
	map<string, vector<string>>::iterator itIn; // iterator for interior map, the one that holds all the data as its value and the name of the animal as its key
	map<string, map<string, vector<string>>>::iterator itOut; // iterator for exterior map, the one that holds the map of the animal as its value and the region as its key
	vector<string>::iterator itData; // for the vector
	int counts[7] = {0, 0 ,0 ,0 ,0 ,0 ,0};
	for(itOut = x.begin(); itOut != x.end(); ++itOut){
		for(itIn = itOut->second.begin(); itIn != itOut->second.end(); ++itIn){
			if(lessThan10K(itIn->second.at(1)) && itIn->second.at(0) == type){
				if(itOut->first == "north america"){
					counts[0]++;
				}
				else if(itOut->first == "south america"){
					counts[1]++;
				}
				else if(itOut->first == "africa"){
					counts[2]++;
				}
				else if(itOut->first == "europe"){
					counts[3]++;
				}
				else if(itOut->first == "asia"){
					counts[4]++;
				}
				else if(itOut->first == "artic and antartic"){
					counts[5]++;
				}
				else if(itOut->first == "australia"){
					counts[6]++;
				}
			}
		}
	}
	cout << "The number of endangered animals in north america: " << counts[0] << endl;
	cout << "The number of endangered animals in south america: " << counts[1] << endl;
	cout << "The number of endangered animals in africa: " << counts[2] << endl;
	cout << "The number of endangered animals in europe: " << counts[3] << endl;
	cout << "The number of endangered animals in asia: " << counts[4] << endl;
	cout << "The number of endangered animals in artic and antartic: " << counts[5] << endl;
	cout << "The number of endangered animals in australia: " << counts[6] << endl;
	cout << endl;

}

bool lessThan10K(string x){
	int value;
	value = atoi(x.c_str());
	if(value < 10000){
		return true;
	}
	else{
		return false;
	}
}

void eaAliveCount(outterMap x){
	priority_queue<IntStrPair_T,vector<IntStrPair_T>,QueueComparator> aliveCountQueue; 
	map<string, vector<string>>::iterator itIn; // iterator for interior map, the one that holds all the data as its value and the name of the animal as its key
	map<string, map<string, vector<string>>>::iterator itOut; // iterator for exterior map, the one that holds the map of the animal as its value and the region as its key
	vector<string>::iterator itData; // for the vector
	for(itOut = x.begin(); itOut != x.end(); ++itOut){
		for(itIn = itOut->second.begin(); itIn != itOut->second.end(); ++itIn){
			aliveCountQueue.push(make_pair(atoi(itIn->second.at(1).c_str()), itIn->first));
		}
	}
	int count = aliveCountQueue.size();
	for(int i = 0; i < count; ++i){
		cout << aliveCountQueue.top().first << " " << aliveCountQueue.top().second << endl;
		aliveCountQueue.pop();
	}
	cout << endl;
}

void eaThreat(outterMap x){
	map<string, vector<string>>::iterator itIn; // iterator for interior map, the one that holds all the data as its value and the name of the animal as its key
	map<string, map<string, vector<string>>>::iterator itOut; // iterator for exterior map, the one that holds the map of the animal as its value and the region as its key
	vector<string>::iterator itData; // for the vector
	vector<string> outputThreat;
	vector<string> outputAnimal;
	for(itOut = x.begin(); itOut != x.end(); ++itOut){
		for(itIn = itOut->second.begin(); itIn != itOut->second.end(); ++itIn){
			outputThreat.push_back(itIn->second.at(3));
			outputAnimal.push_back(itIn->first);
		}
	}
	sort(outputThreat.begin(), outputThreat.end());
	sort(outputAnimal.begin(), outputAnimal.end());
	unique(outputThreat.begin(), outputThreat.end());
	unique(outputAnimal.begin(), outputAnimal.end());
	outputThreat.erase(outputThreat.begin()+23, outputThreat.end());//clears out all the duplicates from array
	cout << "These are the the threats facing animals today" <<  endl;
	for(itData = outputThreat.begin(); itData != outputThreat.end(); ++itData){
		cout << *itData << endl;
	}
	cout << endl;
	cout << "These are the animals that face these threats" << endl;
	for(itData = outputAnimal.begin(); itData != outputAnimal.end(); ++itData){
		cout << *itData << endl;
	}
	cout << endl;
}