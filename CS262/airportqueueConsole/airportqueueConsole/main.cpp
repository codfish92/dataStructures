#include <cstdlib>
#include <iostream>
#include <time.h>
#include <queue>
#include "plane.h"
#include <vector>
using namespace std;



// function prototypes
void inputPrompt(int &a, int &b, int &c, int &d, int &e, int &f); // will handle the input prompt
void outputResults(double a, int b, int c, int d, int e, int f, double g, double h);// outputs the following a. steps in simulation b. number of departures c. number of arrivals d. number of crahes e. number of planes waiting to takeoff f. number of planes waiting to land g. average wait to takeoff h. average wait to land

bool planeArriving(int a);// will handle the probablity if a plane is arriving, returns true if yes, false if no
bool planeDeparting(int a);// same thing as above, but with departures.

void planeLanding(queue<plane> &x, vector<plane> &y, int a, int &b, int c, int &d); // will handle the plane landing. int a is how long it takes to land, int b is the steps, c is the max airtime until plane crashes, d is the number of crashes
void planeTakingoff(queue<plane> &x, vector<plane> &y, queue<plane> &z, int a, int &b, int c, int &d); // as above, but with takingoff, two queue's 



// main


int main(){
	srand(time(NULL)); // seeds random with time
	//input variables
	int timeLand(-6); // values are intilized to reduce compiler warnings. 
	int timeTakeoff(-5);
	int timeCrash(-4);
	int avgArrive(-3);
	int avgDepart(-2);
	int steps(-1);

	//output varaibles
	int arrivals(0);
	int departures(0);
	int crashes(0);
	int waitLand(0);
	int waitTakeoff(0);
	double avgTakeoffOutput(0); // added output to not confuse with the other avg variables
	double avgLandOutput(0);


	// queues
	queue<plane> waitingToLand;
	queue<plane> waitingToTakeoff;

	//vectors
	vector<plane> landing; // used to modifiy the airtime paramater of each plane
	vector<plane>::iterator it;



	inputPrompt(timeLand, timeTakeoff, timeCrash, avgArrive, avgDepart, steps); // will change each varaible to inputed values
	
	int timeLeft = 0;
	
	double maxSteps = steps; // used later in calculating averages
	// runs the simulation

	while(steps > 0){ // master while loop

		// this block of code will handle if a plane is takingoff
		if(waitingToLand.size() == 0 && waitingToTakeoff.size() > 0){ // will only run if there are no planes waiting to the land, and there are planes waiting to take off
			timeLeft = timeTakeoff; // the number of steps it takes to takeoff a plane
			waitingToTakeoff.pop(); // will remove a plane from the queue

			while(timeLeft > 0 && steps > 0){

				bool isArriving = planeArriving(avgArrive);
				bool isDeparting = planeDeparting(avgDepart);

				if(isArriving == true){
					waitingToLand.push(plane()); // add to queue
					landing.push_back(plane()); // adds to vector so it may be used to check for crashes
				} // if(isArriving == true)


				if(isDeparting == true){
					waitingToTakeoff.push(plane()); // add to queue
				} // ends if(isDeparting == true)


				if(waitingToLand.size() > 0){
					if(landing.front().airtime >= timeCrash){ // will crash a plane if it stays in the air too long
						crashes++;
						waitingToLand.pop();
						landing.pop_back();
					} // ends if if(waitingToLand.front().airtime >= timeCrash)

				} // ends if(waitingToLand.size() > 0)

				steps--;
				timeLeft--;
				if(landing.size() != 0){
					for(it=landing.begin(); it < landing.end(); it++){
						it->airtime++;
					} // ends for loop
				} // ends if(landing.size() != 0)
	


			}// ends while(timeLeft > 0 && steps > 0)

			
			departures++; // increment departures

		}// ends if(waitingToLand.size() == 0 && waitingToTakeoff.size() > 0)







		// block of code for landing planes
		else if(waitingToLand.size() > 0){
			timeLeft = timeLand;// sets timeLeft to the number of steps it takes to land a plane

			waitingToLand.pop(); // this is done before the while loop because im assuming if a plane starts landing, it cannot crash
			landing.pop_back();
			
			while(timeLeft > 0 && steps > 0){

				bool isArriving = planeArriving(avgArrive); // will decide if there needs to be another plane added to the queue of waiting planes for landing
				bool isDeparting = planeDeparting(avgDepart);// will decide if there needs to be another plane added to the queue of waiting planes for takeingoff

				if(isArriving == true){
					waitingToLand.push(plane()); // add to queue
					landing.push_back(plane()); // adds to vector so it may be used to check for crashes
				}//ends if(isArriving == true)

				if(isDeparting == true){
					waitingToTakeoff.push(plane()); // add to queue
				}//ends if(isDeparitng == true)


				if(waitingToLand.size() > 0){// to makes sure there is a plane to modifiy
					if(landing.front().airtime >= timeCrash){ // will crash a plane if it stays in the air too long
						crashes++;
						waitingToLand.pop();
						landing.pop_back();
					}// ends if (waitingToLand.front().airtime >= timeCrash)
				}// ends if(waitingToLand.size() > 0)

				if(landing.size() != 0){
					for(it=landing.begin(); it < landing.end(); it++){
						it->airtime++;
					} // ends for loop
				} // ends if(landing.size() != 0)

				steps--;
				timeLeft--;


			}// ends while

			arrivals++; // increment arrivals

		}// ends else if(waitingToLand.size() > 0)













		// will handle if there are no planes in either queue
		else{
			bool isArriving = planeArriving(avgArrive); // will decide if there needs to be another plane added to the queue of waiting planes for landing
			bool isDeparting = planeDeparting(avgDepart);// will decide if there needs to be another plane added to the queue of waiting planes for takeingoff



			if(isArriving == true){
				waitingToLand.push(plane()); // add to queue
				landing.push_back(plane()); // adds to vector so it may be used to check for crashes
			}//ends if(isArriving == true)

			if(isDeparting == true){
				waitingToTakeoff.push(plane()); // add to queue
			}//ends if(isDeparitng == true)

			if(waitingToLand.size() > 0){
				if(landing.front().airtime >= timeCrash){ // will crash a plane if it stays in the air too long
					crashes++;
					waitingToLand.pop();
					landing.pop_back();
				}// ends if (waitingToLand.front().airtime >= timeCrash)
			}// ends if(waitingToLand.size() > 0)


			steps--; // decrement steps
			if(landing.size() != 0){
				for(it=landing.begin(); it < landing.end(); it++){ // should a plane be added to the landing queue, it will increment its airtime
					it->airtime++;
				}//ends for loop

			}// ends if(landing.size() != 0)

		}// ends the else

	}// ends master while

	
	avgTakeoffOutput = departures/maxSteps;
	avgLandOutput = arrivals/maxSteps;
	outputResults(maxSteps, departures, arrivals, crashes, waitingToTakeoff.size(), waitingToLand.size(), avgTakeoffOutput, avgLandOutput);
	

	system("Pause");
	return 0;
}













// function implementations


void inputPrompt(int &a, int &b, int &c, int &d, int &e, int &f){ // is the function for input prompt. will take in the 6 variables by refrence so they can be changed, but the function itself returns nothing
	cout << "Welcome to the airport queue simiulation" << endl;
	cout << "Please enter the values for the corresponding entries" << endl;

	cout << "Time it takes for a plane to land: " ; 
	cin >> a; // will be timeLand in main
	cin.ignore();

	cout << endl << "Time it takes for a plane to takeoff: " ;
	cin >> b;  // will be timeTakeoff in main
	cin.ignore();

	cout << endl << "Time a plane can stay in the air without crashing(note that this simulation assumes that planes come in starting at 0 in airtime): " ;
	cin >> c; // will be timeCrash in main
	cin.ignore();

	cout << endl << "Average time between arrivals : ";
	cin >> d; // will be avgArrive in main
	cin.ignore();

	cout << endl << "Average time between depeartures : ";
	cin >> e; // will be avgDepart in main
	cin.ignore();

	cout << endl << "Number of steps you would like the simulation to handle: " ;
	cin >> f;  // will be steps in main
	cin.ignore();

	cout << endl;

}


void outputResults(double a, int b, int c, int d, int e, int f, double g, double h){
	cout << "In a simulation of " << a << " steps, there were: " << endl;
	cout << b << " Departures" << endl;
	cout << c << " Arrivals" << endl;
	cout << d << " planes crashed due to running out of fuel in midair waiting for runway to be cleared" << endl;
	cout << e << " planes still waiting to takeoff" << endl;
	cout << f << " planes still waiting to land" << endl;
	cout << g << " was the average wait to takeoff" << endl;
	cout << h << " was the average wait to land" << endl;
	cout << endl;



}

bool planeArriving(int a){
	int x = rand();
	if(x % a == 0){ // say a was 6, so every 3steps we want a plane to arrive, a# % 3 will return 0, 1, or 2. in the long run, it should be 0 a third of the time
		return true;
	}
	else{
		return false;
	}
}

bool planeDeparting(int a){
	int x = rand();
	if(x % a == 0){
		return true;
	}
	else{
		return false;
	}
}






