// Lab05.cpp : main project file.

#include "Form1.h"

using namespace SceneForm;

void Scene::Init( )	// Actions and settings before the scene is drawn
{
	// Set up variables
	drawColor.setColor(System::Drawing::Color::Red);
	drawFilled = true;

	// set default characteristics of shape - Rectangle
	myRect = new MyRect();
	line = new MyLine();
	oval = new MyOval();

}

void Scene::Draw( Graphics^ g ) // 	// Actions performed every time when the scene is redrawn
{
	MyShape* drawShape;	 

	for (list.begin(); !list.end(); ++list)
	{
		drawShape = *list;
		drawShape->draw(g);
	}
}

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Scene());
	return 0;
}
