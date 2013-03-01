// Main Scene form for drawing lab
#pragma once

#include "MyRect.h"
#include "MyOval.h"
#include "MyLine.h"

#include "drawList.h"

#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>
#using <System.dll>

// Include files for debugging console window
//#include <windows.h>
//#include <conio.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::Forms;

using namespace macs262_labs;


namespace SceneForm
{
	// current shapes being created
	MyRect *myRect;
	MyOval *oval;
	MyLine *line;

	// current drawing attributes
	macs262_labs::Point startPoint;
	macs262_labs::Color drawColor;
	bool drawFilled;

	// list of shapes
	DrawList list;

	public ref class Scene: public Form
	{
	private:
		BufferedGraphicsContext^ context;
		BufferedGraphics^ grafx;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  drawingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  changeColorToolStripMenuItem;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  filledToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private: System::Windows::Forms::ToolStripMenuItem^  shapeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rectangleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lineToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  circleToolStripMenuItem;

	public:
		Scene()
			: Form()
		{
			/*			
			#ifdef _DEBUG
			if (!AllocConsole())
			System::Windows::Forms::MessageBox::Show("Failed to create the console", "Error", 
			System::Windows::Forms::MessageBoxButtons::OK); 
			#endif
			*/			

			// Configure the Form for this example.
			this->Text = "Draw Program";
			this->Size = System::Drawing::Size(300, 300);

			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->drawingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changeColorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->filledToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->shapeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rectangleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->circleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lineToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();

			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->drawingToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(292, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->exitToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F));
			this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::X));
			this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->exitToolStripMenuItem->Text = L"E&xit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Scene::OnClickedExit);
			// 
			// drawingToolStripMenuItem
			// 
			this->drawingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->changeColorToolStripMenuItem, 
				this->filledToolStripMenuItem, this->shapeToolStripMenuItem});
			this->drawingToolStripMenuItem->Name = L"drawingToolStripMenuItem";
			this->drawingToolStripMenuItem->Size = System::Drawing::Size(58, 20);
			this->drawingToolStripMenuItem->Text = L"&Drawing";
			// 
			// changeColorToolStripMenuItem
			// 
			this->changeColorToolStripMenuItem->Name = L"changeColorToolStripMenuItem";
			this->changeColorToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::C));
			this->changeColorToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->changeColorToolStripMenuItem->Text = L"Change &Color";
			this->changeColorToolStripMenuItem->ToolTipText = L"Change Object\'s Color";
			this->changeColorToolStripMenuItem->Click += gcnew System::EventHandler(this, &Scene::OnClickedColor);
			// 
			// filledToolStripMenuItem
			// 
			this->filledToolStripMenuItem->Name = L"filledToolStripMenuItem";
			this->filledToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::I));
			this->filledToolStripMenuItem->Size = System::Drawing::Size(173, 22);
			this->filledToolStripMenuItem->Text = L"&Filled";
			this->filledToolStripMenuItem->Click += gcnew System::EventHandler(this, &Scene::OnClickFilled);
			// 
			// shapeToolStripMenuItem
			// 
			this->shapeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->rectangleToolStripMenuItem, 
				this->circleToolStripMenuItem, this->lineToolStripMenuItem});
			this->shapeToolStripMenuItem->Name = L"shapeToolStripMenuItem";
			this->shapeToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->shapeToolStripMenuItem->Text = L"&Shape";
			// 
			// rectangleToolStripMenuItem
			// 
			this->rectangleToolStripMenuItem->Name = L"rectangleToolStripMenuItem";
			this->rectangleToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->rectangleToolStripMenuItem->Text = L"&Rectangle";
			this->rectangleToolStripMenuItem->Checked = true;
			this->rectangleToolStripMenuItem->Click += gcnew System::EventHandler(this, &Scene::rectangleToolStripMenuItem_Click);
			// 
			// circleToolStripMenuItem
			// 
			this->circleToolStripMenuItem->Name = L"circleToolStripMenuItem";
			this->circleToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->circleToolStripMenuItem->Text = L"&Oval";
			this->circleToolStripMenuItem->Click += gcnew System::EventHandler(this, &Scene::circleToolStripMenuItem_Click);
			// 
			// lineToolStripMenuItem
			// 
			this->lineToolStripMenuItem->Name = L"lineToolStripMenuItem";
			this->lineToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->lineToolStripMenuItem->Text = L"&Line";
			this->lineToolStripMenuItem->Click += gcnew System::EventHandler(this, &Scene::lineToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(1, 23);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(266, 245);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Scene::OnMouseDown);
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Scene::OnPaint);
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Scene::OnMouseUp);

			Init();
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 300);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"My Fancy Drawing Program";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Scene::OnKeyDown);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private:
		void Draw( Graphics^ g );
		void Scene::Init( );


	protected:

	private: System::Void OnClickedExit(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
			 }
	private: System::Void OnClickedColor(System::Object^  sender, System::EventArgs^  e) {

				 this->colorDialog1->ShowHelp = true;
				 this->colorDialog1->Color = drawColor.getNetColor();

				 if (this->colorDialog1->ShowDialog() == 
					 System::Windows::Forms::DialogResult::OK)
				 {
					 drawColor.setColor(colorDialog1->Color);

				 }
				 pictureBox1->Invalidate();

			 }

	private: System::Void OnPaint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 __super::OnPaint( e );	

				 // Need graphics context for drawing				 
				 Graphics^ g = e->Graphics;
				 Draw( g );
			 }


	private: System::Void OnMouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

				 float x = Convert::ToSingle(e->X);
				 float y = Convert::ToSingle(e->Y);

				 startPoint = macs262_labs::Point(x, y);
			 }

	private: System::Void OnMouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 if (e->Button == System::Windows::Forms::MouseButtons::Left)
				 {
					if (rectangleToolStripMenuItem->Checked)
					 {
						 myRect->setPoint1(startPoint);
						 myRect->setColor(drawColor);
						 myRect->setFilled(drawFilled);
						 myRect->setPoint2(macs262_labs::Point(Convert::ToSingle(e->X), Convert::ToSingle(e->Y)));
						 list.insert(myRect);
					 }
					else if (circleToolStripMenuItem->Checked)
						 {
						 oval->setPoint1(startPoint);
						 oval->setColor(drawColor);
						 oval->setFilled(drawFilled);
						 oval->setPoint2(macs262_labs::Point(Convert::ToSingle(e->X), Convert::ToSingle(e->Y)));
						 list.insert(oval);
					 }
					else if (lineToolStripMenuItem->Checked)
					 {
						 line->setPoint1(startPoint);
						 line->setColor(drawColor);
						 line->setPoint2(macs262_labs::Point(Convert::ToSingle(e->X), Convert::ToSingle(e->Y)));
						 list.insert(line);
					 }

					 pictureBox1->Invalidate();

				 }
	
			 }

	private: System::Void OnClickFilled(System::Object^  sender, System::EventArgs^  e) {
				 drawFilled = !drawFilled;
			 }

	private: System::Void OnKeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

				 if (e->KeyCode == System::Windows::Forms::Keys::Delete && list.size() > 0)
				 {
					 list.remove_last();
					 this->pictureBox1->Invalidate();
				 }
			 }

	private: System::Void rectangleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				rectangleToolStripMenuItem->Checked = true;
				circleToolStripMenuItem->Checked = false;
				lineToolStripMenuItem->Checked = false;
				filledToolStripMenuItem->Enabled = true;
			 }
	private: System::Void circleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				rectangleToolStripMenuItem->Checked = false;
				circleToolStripMenuItem->Checked = true;
				lineToolStripMenuItem->Checked = false;
				filledToolStripMenuItem->Enabled = true;
			 }
	private: System::Void lineToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				rectangleToolStripMenuItem->Checked = false;
				circleToolStripMenuItem->Checked = false;
				lineToolStripMenuItem->Checked = true;
				filledToolStripMenuItem->Enabled = false;
			 }

	};
}

/*
#ifdef _DEBUG
_cprintf("color r%i g%i b%i\n", colorDialog1->Color.R, colorDialog1->Color.G,
colorDialog1->Color.B);

#endif
*/
