// Main Scene form for drawing lab
#pragma once
//#include "stdafx.h"

#include "MyRect.h"
#include "drawList.h"

#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>
#using <System.dll>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Drawing;
using namespace System::Windows::Forms;

using namespace macs262_labs;


namespace SceneForm
{
		// current rectangle being created
		MyRect myRect;

		// current drawing attributes
		macs262_labs::Point startPoint;
		macs262_labs::Color drawColor;
		bool drawFilled;

		// list of rectangles
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


	public:
		Scene()
			: Form()
		{
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
			this->drawingToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->changeColorToolStripMenuItem, 
				this->filledToolStripMenuItem});
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
			this->ClientSize = System::Drawing::Size(292, 273);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Second Draw Program";
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

				 // Must convert our lab 262 color class to .Net color
				 this->colorDialog1->Color = drawColor.getNetColor();

				 // If user clicks OK, update drawing color
				 if (this->colorDialog1->ShowDialog() == 
					 System::Windows::Forms::DialogResult::OK)
				 {
					 drawColor.setColor(colorDialog1->Color);

				 }
				 // Always repaint
				 pictureBox1->Invalidate();

		 }

	private: System::Void OnPaint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				 __super::OnPaint( e );	

				 // Need graphics context for drawing				 
				 Graphics^ g = e->Graphics;
				 Draw( g );

							 }

	private: System::Void OnMouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

				 // convert pixel coordinates to floating point
				 float x = Convert::ToSingle(e->X);
				 float y = Convert::ToSingle(e->Y);
			 
				 startPoint = macs262_labs::Point(x, y);

			 }

	private: System::Void OnMouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 // Set all variables for myRect to drawing variables stored by form
				 myRect.setPoint1(startPoint);
				 // Convert pixel coordinates to floating point
				 float x = Convert::ToSingle(e->X);
				 float y = Convert::ToSingle(e->Y);
				 myRect.setPoint2(macs262_labs::Point(x, y));
				 myRect.setColor(drawColor);
				 myRect.setFilled(drawFilled);

				 // Now insert myRect into the list 
				 list.insert(myRect);

				 // Finally update the screen display
				 pictureBox1->Invalidate();
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

	};
}

/*
#ifdef _DEBUG
		_cprintf("color r%i g%i b%i\n", colorDialog1->Color.R, colorDialog1->Color.G,
			colorDialog1->Color.B);

#endif
*/
