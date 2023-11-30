#pragma once
#include "Juego.h"
#include "Juego2.h"

namespace MultiLab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Seleccion
	/// </summary>
	public ref class Seleccion : public System::Windows::Forms::Form
	{
	public:
		Seleccion(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			dificultad = gcnew Bitmap(gcnew System::String("Sprites/dificultad.jpg"));
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Seleccion()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnNormal;
	private: System::Windows::Forms::Button^ btnDificil;
	private: System::ComponentModel::IContainer^ components;
	protected:


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

	private:
		Graphics^ lienzo;
		Bitmap^ dificultad;
	private: System::Windows::Forms::Timer^ timer1;
		   
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btnNormal = (gcnew System::Windows::Forms::Button());
			this->btnDificil = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// btnNormal
			// 
			this->btnNormal->BackColor = System::Drawing::Color::ForestGreen;
			this->btnNormal->Font = (gcnew System::Drawing::Font(L"Italic Outline Art", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(178)));
			this->btnNormal->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnNormal->Location = System::Drawing::Point(129, 336);
			this->btnNormal->Margin = System::Windows::Forms::Padding(4);
			this->btnNormal->Name = L"btnNormal";
			this->btnNormal->Size = System::Drawing::Size(357, 117);
			this->btnNormal->TabIndex = 1;
			this->btnNormal->Text = L"Normal";
			this->btnNormal->UseVisualStyleBackColor = false;
			this->btnNormal->Click += gcnew System::EventHandler(this, &Seleccion::btnNormal_Click);
			// 
			// btnDificil
			// 
			this->btnDificil->BackColor = System::Drawing::Color::ForestGreen;
			this->btnDificil->Font = (gcnew System::Drawing::Font(L"Italic Outline Art", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(178)));
			this->btnDificil->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnDificil->Location = System::Drawing::Point(733, 336);
			this->btnDificil->Margin = System::Windows::Forms::Padding(4);
			this->btnDificil->Name = L"btnDificil";
			this->btnDificil->Size = System::Drawing::Size(355, 117);
			this->btnDificil->TabIndex = 2;
			this->btnDificil->Text = L"Dificil";
			this->btnDificil->UseVisualStyleBackColor = false;
			this->btnDificil->Click += gcnew System::EventHandler(this, &Seleccion::btnDificil_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Seleccion::timer1_Tick);
			// 
			// Seleccion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1224, 603);
			this->Controls->Add(this->btnDificil);
			this->Controls->Add(this->btnNormal);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Seleccion";
			this->Text = L"Seleccion";
			this->Load += gcnew System::EventHandler(this, &Seleccion::Seleccion_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnNormal_Click(System::Object^ sender, System::EventArgs^ e) {

		Juego^ nivel1 = gcnew Juego();
		nivel1->Show();

	}
	private: System::Void btnDificil_Click(System::Object^ sender, System::EventArgs^ e) {

		Juego2^ nivel2 = gcnew Juego2();
		nivel2->Show();
		//nivel dificil aun no esta terminado
	}
	private: System::Void Seleccion_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		lienzo = this->CreateGraphics();

		BufferedGraphicsContext^ space = BufferedGraphicsManager::Current;

		BufferedGraphics^ buffer = space->Allocate(lienzo, this->ClientRectangle);
		int ancho = buffer->Graphics->VisibleClipBounds.Width;
		int alto = buffer->Graphics->VisibleClipBounds.Height;

		buffer->Graphics->DrawImage(dificultad, 0, 0,ancho, alto);
		buffer->Render(lienzo);
		delete buffer;
		delete space;
}
};
}
