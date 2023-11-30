#pragma once
#include "Numeros.h"
#include "Personajes.h"

namespace MultiLab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Preguntas
	/// </summary>
	public ref class Preguntas : public System::Windows::Forms::Form
	{
	public:
		Preguntas(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			ObjNumeros = new Numeros();
			objValorW = new Personaje();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Preguntas()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblMensaje1;
	protected:
	private: System::Windows::Forms::Label^ lblNumero1;
	private: System::Windows::Forms::Label^ lblNumero2;
	private: System::Windows::Forms::Button^ btnVerificar;
	private: System::Windows::Forms::TextBox^ txtBox1;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		
		Numeros* ObjNumeros;
		Personaje* objValorW;




		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::TextBox^ txtBox2;
	private: System::Windows::Forms::TextBox^ txtBox3;
	private: System::Windows::Forms::TextBox^ txtBox4;
	private: System::Windows::Forms::TextBox^ txtBox5;




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblNumero3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lblNumero4;
	private: System::Windows::Forms::Label^ lblNumero5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ lblNumero6;
	private: System::Windows::Forms::Label^ lblNumero7;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ lblNumero8;

	private: System::Windows::Forms::Label^ lblNumero9;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ lblNum1;





#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblMensaje1 = (gcnew System::Windows::Forms::Label());
			this->lblNumero1 = (gcnew System::Windows::Forms::Label());
			this->lblNumero2 = (gcnew System::Windows::Forms::Label());
			this->btnVerificar = (gcnew System::Windows::Forms::Button());
			this->txtBox1 = (gcnew System::Windows::Forms::TextBox());
			this->txtBox2 = (gcnew System::Windows::Forms::TextBox());
			this->txtBox3 = (gcnew System::Windows::Forms::TextBox());
			this->txtBox4 = (gcnew System::Windows::Forms::TextBox());
			this->txtBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblNumero3 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lblNumero4 = (gcnew System::Windows::Forms::Label());
			this->lblNumero5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->lblNumero6 = (gcnew System::Windows::Forms::Label());
			this->lblNumero7 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->lblNumero8 = (gcnew System::Windows::Forms::Label());
			this->lblNumero9 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->lblNum1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblMensaje1
			// 
			this->lblMensaje1->AutoSize = true;
			this->lblMensaje1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->lblMensaje1->Location = System::Drawing::Point(62, 20);
			this->lblMensaje1->Name = L"lblMensaje1";
			this->lblMensaje1->Size = System::Drawing::Size(235, 25);
			this->lblMensaje1->TabIndex = 0;
			this->lblMensaje1->Text = L"Responde Correctamente";
			// 
			// lblNumero1
			// 
			this->lblNumero1->AutoSize = true;
			this->lblNumero1->Location = System::Drawing::Point(131, 65);
			this->lblNumero1->Name = L"lblNumero1";
			this->lblNumero1->Size = System::Drawing::Size(35, 13);
			this->lblNumero1->TabIndex = 1;
			this->lblNumero1->Text = L"label1";
			// 
			// lblNumero2
			// 
			this->lblNumero2->AutoSize = true;
			this->lblNumero2->Location = System::Drawing::Point(198, 65);
			this->lblNumero2->Name = L"lblNumero2";
			this->lblNumero2->Size = System::Drawing::Size(44, 13);
			this->lblNumero2->TabIndex = 2;
			this->lblNumero2->Text = L"label2.1";
			// 
			// btnVerificar
			// 
			this->btnVerificar->Location = System::Drawing::Point(112, 244);
			this->btnVerificar->Name = L"btnVerificar";
			this->btnVerificar->Size = System::Drawing::Size(93, 29);
			this->btnVerificar->TabIndex = 3;
			this->btnVerificar->Text = L"Verificar";
			this->btnVerificar->UseVisualStyleBackColor = true;
			this->btnVerificar->Click += gcnew System::EventHandler(this, &Preguntas::btnVerificar_Click);
			// 
			// txtBox1
			// 
			this->txtBox1->Location = System::Drawing::Point(264, 58);
			this->txtBox1->Name = L"txtBox1";
			this->txtBox1->Size = System::Drawing::Size(34, 20);
			this->txtBox1->TabIndex = 4;
			// 
			// txtBox2
			// 
			this->txtBox2->Location = System::Drawing::Point(263, 90);
			this->txtBox2->Name = L"txtBox2";
			this->txtBox2->Size = System::Drawing::Size(34, 20);
			this->txtBox2->TabIndex = 5;
			// 
			// txtBox3
			// 
			this->txtBox3->Location = System::Drawing::Point(264, 119);
			this->txtBox3->Name = L"txtBox3";
			this->txtBox3->Size = System::Drawing::Size(33, 20);
			this->txtBox3->TabIndex = 6;
			// 
			// txtBox4
			// 
			this->txtBox4->Location = System::Drawing::Point(264, 150);
			this->txtBox4->Name = L"txtBox4";
			this->txtBox4->Size = System::Drawing::Size(33, 20);
			this->txtBox4->TabIndex = 7;
			// 
			// txtBox5
			// 
			this->txtBox5->Location = System::Drawing::Point(264, 184);
			this->txtBox5->Name = L"txtBox5";
			this->txtBox5->Size = System::Drawing::Size(33, 20);
			this->txtBox5->TabIndex = 8;
			this->txtBox5->TextChanged += gcnew System::EventHandler(this, &Preguntas::txtBox5_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label1->Location = System::Drawing::Point(173, 61);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(16, 17);
			this->label1->TabIndex = 9;
			this->label1->Text = L"+";
			// 
			// lblNumero3
			// 
			this->lblNumero3->AutoSize = true;
			this->lblNumero3->Location = System::Drawing::Point(131, 93);
			this->lblNumero3->Name = L"lblNumero3";
			this->lblNumero3->Size = System::Drawing::Size(35, 13);
			this->lblNumero3->TabIndex = 10;
			this->lblNumero3->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(173, 90);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(13, 17);
			this->label3->TabIndex = 11;
			this->label3->Text = L"-";
			// 
			// lblNumero4
			// 
			this->lblNumero4->AutoSize = true;
			this->lblNumero4->Location = System::Drawing::Point(198, 94);
			this->lblNumero4->Name = L"lblNumero4";
			this->lblNumero4->Size = System::Drawing::Size(35, 13);
			this->lblNumero4->TabIndex = 12;
			this->lblNumero4->Text = L"label4";
			// 
			// lblNumero5
			// 
			this->lblNumero5->AutoSize = true;
			this->lblNumero5->Location = System::Drawing::Point(131, 126);
			this->lblNumero5->Name = L"lblNumero5";
			this->lblNumero5->Size = System::Drawing::Size(35, 13);
			this->lblNumero5->TabIndex = 13;
			this->lblNumero5->Text = L"label5";
			this->lblNumero5->Click += gcnew System::EventHandler(this, &Preguntas::lblNumero5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label6->Location = System::Drawing::Point(172, 122);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(13, 17);
			this->label6->TabIndex = 14;
			this->label6->Text = L"-";
			// 
			// lblNumero6
			// 
			this->lblNumero6->AutoSize = true;
			this->lblNumero6->Location = System::Drawing::Point(198, 126);
			this->lblNumero6->Name = L"lblNumero6";
			this->lblNumero6->Size = System::Drawing::Size(35, 13);
			this->lblNumero6->TabIndex = 15;
			this->lblNumero6->Text = L"label7";
			// 
			// lblNumero7
			// 
			this->lblNumero7->AutoSize = true;
			this->lblNumero7->Location = System::Drawing::Point(131, 157);
			this->lblNumero7->Name = L"lblNumero7";
			this->lblNumero7->Size = System::Drawing::Size(35, 13);
			this->lblNumero7->TabIndex = 16;
			this->lblNumero7->Text = L"label8";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(172, 157);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(14, 13);
			this->label9->TabIndex = 17;
			this->label9->Text = L"X";
			// 
			// lblNumero8
			// 
			this->lblNumero8->AutoSize = true;
			this->lblNumero8->Location = System::Drawing::Point(198, 157);
			this->lblNumero8->Name = L"lblNumero8";
			this->lblNumero8->Size = System::Drawing::Size(41, 13);
			this->lblNumero8->TabIndex = 18;
			this->lblNumero8->Text = L"label10";
			// 
			// lblNumero9
			// 
			this->lblNumero9->AutoSize = true;
			this->lblNumero9->Location = System::Drawing::Point(131, 191);
			this->lblNumero9->Name = L"lblNumero9";
			this->lblNumero9->Size = System::Drawing::Size(41, 13);
			this->lblNumero9->TabIndex = 20;
			this->lblNumero9->Text = L"label12";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(173, 191);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(14, 13);
			this->label13->TabIndex = 21;
			this->label13->Text = L"X";
			// 
			// lblNum1
			// 
			this->lblNum1->AutoSize = true;
			this->lblNum1->Location = System::Drawing::Point(198, 191);
			this->lblNum1->Name = L"lblNum1";
			this->lblNum1->Size = System::Drawing::Size(41, 13);
			this->lblNum1->TabIndex = 22;
			this->lblNum1->Text = L"label14";
			// 
			// Preguntas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(328, 285);
			this->Controls->Add(this->lblNum1);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->lblNumero9);
			this->Controls->Add(this->lblNumero8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->lblNumero7);
			this->Controls->Add(this->lblNumero6);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->lblNumero5);
			this->Controls->Add(this->lblNumero4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lblNumero3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtBox5);
			this->Controls->Add(this->txtBox4);
			this->Controls->Add(this->txtBox3);
			this->Controls->Add(this->txtBox2);
			this->Controls->Add(this->txtBox1);
			this->Controls->Add(this->btnVerificar);
			this->Controls->Add(this->lblNumero2);
			this->Controls->Add(this->lblNumero1);
			this->Controls->Add(this->lblMensaje1);
			this->Name = L"Preguntas";
			this->Text = L"Preguntas";
			this->Load += gcnew System::EventHandler(this, &Preguntas::Preguntas_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Preguntas_Load(System::Object^ sender, System::EventArgs^ e) {

		lblNumero1->Text = Convert::ToString(ObjNumeros->SetNumero1());
		lblNumero2->Text = Convert::ToString(ObjNumeros->SetNumero2());
		lblNumero3->Text = Convert::ToString(ObjNumeros->SetNumero3());
		lblNumero4->Text = Convert::ToString(ObjNumeros->SetNumero4());
		lblNumero5->Text = Convert::ToString(ObjNumeros->SetNumero5());
		lblNumero6->Text = Convert::ToString(ObjNumeros->SetNumero6());
		lblNumero7->Text = Convert::ToString(ObjNumeros->SetNumero7());
		lblNumero8->Text = Convert::ToString(ObjNumeros->SetNumero8());
		lblNumero9->Text = Convert::ToString(ObjNumeros->SetNumero9());
		lblNum1->Text = Convert::ToString(ObjNumeros->SetNumero10());
	}
	private: System::Void btnVerificar_Click(System::Object^ sender, System::EventArgs^ e) {

		int propuesto = Convert::ToInt32(txtBox1->Text);
		float propuesto2 = Convert::ToInt32(txtBox2->Text);
		float propuesto3 = Convert::ToInt32(txtBox3->Text);
		float propuesto4 = Convert::ToInt32(txtBox4->Text);
		float propuesto5 = Convert::ToInt32(txtBox5->Text);

		if (propuesto == ObjNumeros->Sumar() && propuesto2 == ObjNumeros->Restar() && propuesto3 == ObjNumeros->Restar2()
			&& propuesto4 == ObjNumeros->Multiplicar()&& propuesto5== ObjNumeros->Multiplicar2())
	{
			objValorW->setValor(1);
		    MessageBox::Show("Respuestas correctas");
		    Close();


	}
	else
	{
		MessageBox::Show("Respuestas Incorrectas...¡Vuelve a recolectar los elementos!");
		Close();
		//objValorW->setValor(0);
	}


}
private: System::Void lblNumero5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txtBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
