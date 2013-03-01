// Lab2.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"

using namespace SceneForm;

void Scene::Init( )	// Actions and settings before the scene is drawn
{
	// Set up variables
	drawColor.setColor(System::Drawing::Color::Red);
	drawFilled = true;

}

void Scene::Draw( Graphics^ g )
{
        MyRect drawRect;

        for (list.begin(); !list.end(); ++list)
        {
                drawRect = **list;
                drawRect.draw(g);
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
