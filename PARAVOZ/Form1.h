#pragma once 
//#include <windows.h> 
#include "TFigure.h" 
namespace CppCLR_WinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form {
		Graphics^gz;
		int size;
		int coordX = 0, coordY = 0;
		int pointX = 0, pointY = 0;
		int borderR, borderL;
		bool stopBut = true;
		int timerCounter = 0;
		int flag = 1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;

	private: System::Windows::Forms::Timer^  timer1;

			 TFigure** mas;
	public:
		Form1(void) {
			InitializeComponent();
			size = 10;
			mas = new TFigure*[size];
			gz = CreateGraphics();
		}

	protected:
		~Form1() {
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::ComponentModel::IContainer^  components;

	private:
#pragma region Windows Form Designer generated code 
		void InitializeComponent(void) {
			this->components = (gcnew System::ComponentModel::Container());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(801, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(84, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Нарисовать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(801, 41);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(84, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Скрыть";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(801, 70);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(84, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Сдвинуть";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(801, 122);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(84, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Старт";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(801, 151);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(84, 23);
			this->button5->TabIndex = 7;
			this->button5->Text = L"Стоп";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(694, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(84, 20);
			this->textBox1->TabIndex = 8;
			this->textBox1->Text = L"0";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(694, 38);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(84, 20);
			this->textBox2->TabIndex = 9;
			this->textBox2->Text = L"0";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(932, 621);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion 
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		coordX = (Convert::ToDouble(textBox1->Text));
		coordY = (Convert::ToDouble(textBox2->Text));
		pointX = (Convert::ToDouble(textBox1->Text));
		pointY = (Convert::ToDouble(textBox2->Text));
		mas[0] = new TCircle(coordX + 30, coordY + 185, 20); //колесо 1
		mas[1] = new TCircle(coordX + 130, coordY + 185, 20); //колесо 2
		mas[2] = new TCircle(coordX + 190, coordY + 185, 20); //колесо 3
		mas[3] = new TRectangle(coordX + 0, coordY + 45, 210, 120); //тело
		mas[4] = new TRectangle(coordX + 155, coordY + 0, 40, 45); //труба
		mas[5] = new TRectangle(coordX + 0, coordY + 75, 45, 90); //передник
		mas[6] = new TRectangle(coordX + 75, coordY + 85, 30, 40); //окно 1
		mas[7] = new TRectangle(coordX + 75 + 45, coordY + 85, 30, 40); //окно 2
		mas[8] = new TRectangle(coordX + 75 + 45 + 45, coordY + 85, 30, 40); //окно 3
		mas[9] = new TLine(coordX + 130, coordY + 185, coordX + 130 +60, coordY + 185); //палка

		for (int i = 0; i < size; i++) mas[i]->Show(gz);

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < size; i++) mas[i]->Hide(gz);
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < size; i++) mas[i]->Hide(gz);

		coordX = (Convert::ToDouble(textBox1->Text));
		coordY = (Convert::ToDouble(textBox2->Text));

		pointX += coordX;
		pointY += coordY;
		if (pointX > -30 && pointX < 350) {
			for (int i = 0; i < size; i++) mas[i]->Move(gz, coordX + 0, coordY + 0);

		}
		else {
			textBox1->Text = Convert::ToString((Convert::ToDouble(textBox1->Text)) * (-1));
			for (int i = 0; i < size; i++) mas[i]->Move(gz, coordX + 0, coordY + 0);
			pointX -= coordX;
			pointX -= coordX;

		}
		if (pointY > -40 && pointY < 200) {
			for (int i = 0; i < size; i++) mas[i]->Move(gz, coordX + 0, coordY + 0);
		}
		else {
			textBox2->Text = Convert::ToString((Convert::ToDouble(textBox2->Text)) * (-1));
			for (int i = 0; i < size; i++) mas[i]->Move(gz, coordX + 0, coordY + 0);
			pointY -= coordY;
			pointY -= coordY;
		}
		for (int i = 0; i < size; i++) mas[i]->Show(gz);
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Interval = 100;
		timer1->Enabled = true;
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = false;
		stopBut = false;
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void Button6_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < size - 1; i++)	mas[i]->Move(gz, -150, -150);
		for (int i = 0; i < size; i++) mas[i]->Show(gz);
	}
	private: System::Void Button7_Click(System::Object^ sender, System::EventArgs^ e) {
		for (int j = 0; j < 5; j++) {
			for (int i = 0; i < size; i++)	mas[i]->Hide(gz);

			coordX = (Convert::ToDouble(textBox1->Text));
			coordY = (Convert::ToDouble(textBox2->Text));
			for (int i = 0; i < size; i++) mas[i]->Move(gz, (-1) * coordX + 0, (-1) * coordY + 0);
			for (int i = 0; i < size; i++) mas[i]->Show(gz);
		}
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		for (int i = 0; i < size; i++) mas[i]->Hide(gz);

		coordX = (Convert::ToDouble(textBox1->Text));
		coordY = (Convert::ToDouble(textBox2->Text));

		pointX += coordX;
		pointY += coordY;
		if (pointX > -5 && pointX < 355) {
			for (int i = 0; i < size; i++) mas[i]->Move(gz, coordX + 0, coordY + 0);
		}
		else {
			textBox1->Text = Convert::ToString((Convert::ToDouble(textBox1->Text)) * (-1));
			for (int i = 0; i < size; i++) mas[i]->Move(gz, coordX + 0, coordY + 0);
			pointX -= coordX;
			pointX -= coordX;
		}
		if (pointY > -10 && pointY < 200) {
			for (int i = 0; i < size; i++) mas[i]->Move(gz, coordX + 0, coordY + 0);
		}
		else {
			textBox2->Text = Convert::ToString((Convert::ToDouble(textBox2->Text)) * (-1));
			for (int i = 0; i < size; i++) mas[i]->Move(gz, coordX + 0, coordY + 0);
			pointY -= coordY;
			pointY -= coordY;

		}
		for (int i = 0; i < size; i++) mas[i]->Show(gz);
	}
	};
}
