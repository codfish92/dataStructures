/************************************************************/
// Drew Koelling
// 4/2/2012
// B
//
// To use the std datastructure queues to simulate an airport. also get some intro to making windows forms.
/************************************************************/


#pragma once
#include <cstdlib>
#include <time.h>
#include <queue>
#include <iostream>
#include <vector>
#include "plane.h"


using namespace std;
using namespace System;



namespace airportqueueForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// Summary for Form1
	/// </summary>

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

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TextBox^  stepsIn;
	private: System::Windows::Forms::TextBox^  avgDepartIn;
	private: System::Windows::Forms::TextBox^  avgArriveIn;
	private: System::Windows::Forms::TextBox^  timeCrashIn;
	private: System::Windows::Forms::TextBox^  timeTakeoffIn;
	private: System::Windows::Forms::TextBox^  timeLandIn;






	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::TextBox^  avgDeparturesOutputOut;

	private: System::Windows::Forms::TextBox^  avgArrivalsOutputOut;

	private: System::Windows::Forms::TextBox^  numWaitingToTakeoffOut;

	private: System::Windows::Forms::TextBox^  numWaitingToLandOut;

	private: System::Windows::Forms::TextBox^  crashesOut;

	private: System::Windows::Forms::TextBox^  departuresOut;

	private: System::Windows::Forms::TextBox^  arrivalsOut;

	private: System::Windows::Forms::Button^  runSim;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->stepsIn = (gcnew System::Windows::Forms::TextBox());
			this->avgDepartIn = (gcnew System::Windows::Forms::TextBox());
			this->avgArriveIn = (gcnew System::Windows::Forms::TextBox());
			this->timeCrashIn = (gcnew System::Windows::Forms::TextBox());
			this->timeTakeoffIn = (gcnew System::Windows::Forms::TextBox());
			this->timeLandIn = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->avgDeparturesOutputOut = (gcnew System::Windows::Forms::TextBox());
			this->avgArrivalsOutputOut = (gcnew System::Windows::Forms::TextBox());
			this->numWaitingToTakeoffOut = (gcnew System::Windows::Forms::TextBox());
			this->numWaitingToLandOut = (gcnew System::Windows::Forms::TextBox());
			this->crashesOut = (gcnew System::Windows::Forms::TextBox());
			this->departuresOut = (gcnew System::Windows::Forms::TextBox());
			this->arrivalsOut = (gcnew System::Windows::Forms::TextBox());
			this->runSim = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 2);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Time for a plane to Land:";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 38);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(138, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Time for a plane to Takeoff:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 85);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(218, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Time a plane can be airborne befor crashing:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 126);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(177, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Average number of steps per arrival:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 169);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(194, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Average number of steps per departure:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 209);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(189, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Number of steps the simulation will run:";
			this->label6->Click += gcnew System::EventHandler(this, &Form1::label6_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(9, 1);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(96, 13);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Number of Arrivals:";
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->stepsIn);
			this->panel1->Controls->Add(this->avgDepartIn);
			this->panel1->Controls->Add(this->avgArriveIn);
			this->panel1->Controls->Add(this->timeCrashIn);
			this->panel1->Controls->Add(this->timeTakeoffIn);
			this->panel1->Controls->Add(this->timeLandIn);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(6, 45);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(407, 254);
			this->panel1->TabIndex = 7;
			// 
			// stepsIn
			// 
			this->stepsIn->Location = System::Drawing::Point(284, 206);
			this->stepsIn->Name = L"stepsIn";
			this->stepsIn->Size = System::Drawing::Size(116, 20);
			this->stepsIn->TabIndex = 6;
			// 
			// avgDepartIn
			// 
			this->avgDepartIn->Location = System::Drawing::Point(284, 169);
			this->avgDepartIn->Name = L"avgDepartIn";
			this->avgDepartIn->Size = System::Drawing::Size(116, 20);
			this->avgDepartIn->TabIndex = 6;
			// 
			// avgArriveIn
			// 
			this->avgArriveIn->Location = System::Drawing::Point(284, 119);
			this->avgArriveIn->Name = L"avgArriveIn";
			this->avgArriveIn->Size = System::Drawing::Size(116, 20);
			this->avgArriveIn->TabIndex = 6;
			// 
			// timeCrashIn
			// 
			this->timeCrashIn->Location = System::Drawing::Point(284, 82);
			this->timeCrashIn->Name = L"timeCrashIn";
			this->timeCrashIn->Size = System::Drawing::Size(116, 20);
			this->timeCrashIn->TabIndex = 6;
			// 
			// timeTakeoffIn
			// 
			this->timeTakeoffIn->Location = System::Drawing::Point(284, 38);
			this->timeTakeoffIn->Name = L"timeTakeoffIn";
			this->timeTakeoffIn->Size = System::Drawing::Size(116, 20);
			this->timeTakeoffIn->TabIndex = 6;
			// 
			// timeLandIn
			// 
			this->timeLandIn->Location = System::Drawing::Point(284, 3);
			this->timeLandIn->Name = L"timeLandIn";
			this->timeLandIn->Size = System::Drawing::Size(116, 20);
			this->timeLandIn->TabIndex = 6;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(9, 36);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(114, 13);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Number of Departures:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(9, 73);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(100, 13);
			this->label9->TabIndex = 9;
			this->label9->Text = L"Number of Crashes:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(9, 112);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(117, 13);
			this->label10->TabIndex = 10;
			this->label10->Text = L"Planes waiting to Land:";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(9, 158);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(133, 13);
			this->label11->TabIndex = 11;
			this->label11->Text = L"Planes waiting to Takeoff: ";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(9, 198);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(209, 13);
			this->label12->TabIndex = 12;
			this->label12->Text = L"Average number of steps between Arrivals:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(9, 246);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(227, 13);
			this->label13->TabIndex = 13;
			this->label13->Text = L"Average number of steps between Departures:";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->avgDeparturesOutputOut);
			this->panel2->Controls->Add(this->avgArrivalsOutputOut);
			this->panel2->Controls->Add(this->numWaitingToTakeoffOut);
			this->panel2->Controls->Add(this->numWaitingToLandOut);
			this->panel2->Controls->Add(this->crashesOut);
			this->panel2->Controls->Add(this->departuresOut);
			this->panel2->Controls->Add(this->arrivalsOut);
			this->panel2->Controls->Add(this->label13);
			this->panel2->Controls->Add(this->label12);
			this->panel2->Controls->Add(this->label11);
			this->panel2->Controls->Add(this->label10);
			this->panel2->Controls->Add(this->label9);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Location = System::Drawing::Point(7, 319);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(406, 282);
			this->panel2->TabIndex = 14;
			// 
			// avgDeparturesOutputOut
			// 
			this->avgDeparturesOutputOut->Location = System::Drawing::Point(284, 239);
			this->avgDeparturesOutputOut->Name = L"avgDeparturesOutputOut";
			this->avgDeparturesOutputOut->Size = System::Drawing::Size(116, 20);
			this->avgDeparturesOutputOut->TabIndex = 6;
			// 
			// avgArrivalsOutputOut
			// 
			this->avgArrivalsOutputOut->Location = System::Drawing::Point(284, 198);
			this->avgArrivalsOutputOut->Name = L"avgArrivalsOutputOut";
			this->avgArrivalsOutputOut->Size = System::Drawing::Size(116, 20);
			this->avgArrivalsOutputOut->TabIndex = 6;
			// 
			// numWaitingToTakeoffOut
			// 
			this->numWaitingToTakeoffOut->Location = System::Drawing::Point(284, 151);
			this->numWaitingToTakeoffOut->Name = L"numWaitingToTakeoffOut";
			this->numWaitingToTakeoffOut->Size = System::Drawing::Size(116, 20);
			this->numWaitingToTakeoffOut->TabIndex = 6;
			// 
			// numWaitingToLandOut
			// 
			this->numWaitingToLandOut->Location = System::Drawing::Point(284, 105);
			this->numWaitingToLandOut->Name = L"numWaitingToLandOut";
			this->numWaitingToLandOut->Size = System::Drawing::Size(116, 20);
			this->numWaitingToLandOut->TabIndex = 6;
			// 
			// crashesOut
			// 
			this->crashesOut->Location = System::Drawing::Point(284, 66);
			this->crashesOut->Name = L"crashesOut";
			this->crashesOut->Size = System::Drawing::Size(116, 20);
			this->crashesOut->TabIndex = 6;
			// 
			// departuresOut
			// 
			this->departuresOut->Location = System::Drawing::Point(284, 36);
			this->departuresOut->Name = L"departuresOut";
			this->departuresOut->Size = System::Drawing::Size(116, 20);
			this->departuresOut->TabIndex = 6;
			// 
			// arrivalsOut
			// 
			this->arrivalsOut->Location = System::Drawing::Point(284, 3);
			this->arrivalsOut->Name = L"arrivalsOut";
			this->arrivalsOut->Size = System::Drawing::Size(116, 20);
			this->arrivalsOut->TabIndex = 6;
			// 
			// runSim
			// 
			this->runSim->Location = System::Drawing::Point(292, 623);
			this->runSim->Name = L"runSim";
			this->runSim->Size = System::Drawing::Size(121, 33);
			this->runSim->TabIndex = 15;
			this->runSim->Text = L"Run";
			this->runSim->UseVisualStyleBackColor = true;
			this->runSim->Click += gcnew System::EventHandler(this, &Form1::runButton_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(419, 24);
			this->menuStrip1->TabIndex = 16;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(92, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::fileExit_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(419, 668);
			this->Controls->Add(this->runSim);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

		 }
private: System::Void fileExit_Click(System::Object^  sender, System::EventArgs^  e) {
			 Application::Exit();
		 }

private: System::Void runSim_Click(System::Object^  sender, System::EventArgs^  e) {
		

	}
		 private: System::Void runButton_Click(System::Object^  sender, System::EventArgs^  e) {

					  

			srand(time(NULL)); // seeds random with time
			//input variables
			int timeLand = Convert::ToInt32(timeLandIn->Text); // values are intilized to reduce compiler warnings. 
			int timeTakeoff= Convert::ToInt32(timeTakeoffIn->Text);
			int timeCrash = Convert::ToInt32(timeCrashIn->Text);
			int avgArrive = Convert::ToInt32(avgArriveIn->Text);
			int avgDepart = Convert::ToInt32(avgDepartIn->Text);
			int steps = Convert::ToInt32(stepsIn->Text);

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

			arrivalsOut->Text = Convert::ToString(arrivals);
			departuresOut->Text = Convert::ToString(departures);
			crashesOut->Text = Convert::ToString(crashes);
			numWaitingToLandOut->Text = Convert::ToString(waitingToLand.size());
			numWaitingToTakeoffOut->Text = Convert::ToString(waitingToTakeoff.size());
			avgArrivalsOutputOut->Text = Convert::ToString(avgLandOutput);
			avgDeparturesOutputOut->Text = Convert::ToString(avgTakeoffOutput);
				  }
}
;};


