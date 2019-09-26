#pragma once

namespace WindowsFoRms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ ShemaPB;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ TrueTB;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ Chainlbl;
	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->ShemaPB = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->TrueTB = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Chainlbl = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ShemaPB))->BeginInit();
			this->SuspendLayout();
			// 
			// ShemaPB
			// 
			this->ShemaPB->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->ShemaPB->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ShemaPB.Image")));
			this->ShemaPB->Location = System::Drawing::Point(0, 168);
			this->ShemaPB->Name = L"ShemaPB";
			this->ShemaPB->Size = System::Drawing::Size(443, 263);
			this->ShemaPB->TabIndex = 0;
			this->ShemaPB->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 51);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(165, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Введите цепочку";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(16, 78);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(254, 29);
			this->textBox1->TabIndex = 2;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::TextBox1_KeyPress);
			// 
			// TrueTB
			// 
			this->TrueTB->AutoSize = true;
			this->TrueTB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TrueTB->Location = System::Drawing::Point(282, 81);
			this->TrueTB->Name = L"TrueTB";
			this->TrueTB->Size = System::Drawing::Size(0, 24);
			this->TrueTB->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(282, 51);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Ответ";
			// 
			// Chainlbl
			// 
			this->Chainlbl->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Chainlbl->Location = System::Drawing::Point(12, 110);
			this->Chainlbl->Name = L"Chainlbl";
			this->Chainlbl->Size = System::Drawing::Size(419, 55);
			this->Chainlbl->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(443, 431);
			this->Controls->Add(this->Chainlbl);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->TrueTB);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ShemaPB);
			this->Name = L"MyForm";
			this->Text = L"Проверка цепочки";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ShemaPB))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		bool scan_G(String^ Chain)
		{
			enum state { H, BC,BD, S, ER };
			enum state CS;
			CS = H;
			wchar_t c;
			int i = 0;
			Chainlbl->Text = "";
			do
			{
				if (i == Chain->Length)
				{
					CS = ER;
					break;
				}
				c = Chain[i];
				switch (CS)
				{
				case H:
					if (c == '0')
					{
						//c = fgetc(fp);
						Chainlbl->Text += "H -> BD";
						CS = BD;
					}
					else
					{
						CS = ER;
					}
					break;
				case BD:
					if (c == '0')
					{
						//	c = fgetc(fp);
						CS = BD;
						Chainlbl->Text += " -> BD";
					}
					else if (c == '1')
					{
						CS = BC;
						Chainlbl->Text += " -> BC";
					}
					else
						CS = ER;
					break;
				case BC:
					if (c == '1')
					{
						//	c = fgetc(fp);
						CS = BC;
						Chainlbl->Text += " -> BC";

					}
					else if (c == '*' && i == Chain->Length-1)
					{
						CS = S;
						Chainlbl->Text += " -> S";

					}
					else
						CS = ER;
					break;

				}
				i++;
			} while (CS != S && CS != ER);
			if (CS == ER) return 0;
			else return 1;

		}
	private: System::Void TextBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == '0' || e->KeyChar == '1' || e->KeyChar == '*' ||
			e->KeyChar == (Char)Keys::Back)
			e->Handled = 0;
		else if (e->KeyChar == (Char)Keys::Enter)
		{
			if (scan_G(textBox1->Text))
				TrueTB->Text = "Принято";
			else TrueTB->Text = "Отклонено";
		}
		else e->Handled = 1;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

	}
};
}
