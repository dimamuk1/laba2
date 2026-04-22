#pragma once
const int n = 10;
int mas[n];   // глобальний масив

namespace laboratorna2 {

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

	protected:

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(530, 382);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(222, 33);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Знайти і сортувати";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(280, 376);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 39);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Заповнити";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(592, 73);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(265, 285);
			this->dataGridView2->TabIndex = 7;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(260, 73);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(104, 285);
			this->dataGridView1->TabIndex = 6;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1012, 545);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		dataGridView1->Columns->Clear();
		dataGridView2->Columns->Clear();

		dataGridView1->Columns->Add("c1", "");
		dataGridView2->Columns->Add("c1", "");
		dataGridView2->Columns->Add("c2", "");

		dataGridView1->Columns[0]->HeaderText = "Початковий\nмасив";
		dataGridView1->Width = 230;

		dataGridView2->Columns[0]->HeaderText = "Змінений\nмасив";
		dataGridView2->Columns[1]->HeaderText = "Сортований\nмасив";
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView1->Rows->Clear();
	dataGridView1->Rows->Add(n);

	Random^ rand = gcnew Random();
	for (int i = 0; i < n; i++) {
		mas[i] = rand->Next(-100, 100);
		dataGridView1->Rows[i]->Cells[0]->Value = mas[i];
		dataGridView1->Rows[i]->Cells[0]->Style->BackColor = Color::Plum;
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView2->Rows->Clear();

	int tempMas[100];

	// Збільшити вдвічі всі елементи
	for (int i = 0; i < n; i++) {
		tempMas[i] = mas[i] * 2;
	}

	// Додаємо рядки
	dataGridView2->Rows->Add(n);

	// Перший стовпець — змінений масив
	for (int i = 0; i < n; i++) {
		dataGridView2->Rows[i]->Cells[0]->Value = tempMas[i];
		dataGridView2->Rows[i]->Cells[0]->Style->BackColor = Color::Pink;
	}

	// Сортування за спаданням методом обміну
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (tempMas[j] < tempMas[j + 1]) {
				int temp = tempMas[j];
				tempMas[j] = tempMas[j + 1];
				tempMas[j + 1] = temp;
			}
		}
	}

	// Другий стовпець — сортований масив
	for (int i = 0; i < n; i++) {
		dataGridView2->Rows[i]->Cells[1]->Value = tempMas[i];
		dataGridView2->Rows[i]->Cells[1]->Style->BackColor = Color::AliceBlue;
	}
}
};
}
