#pragma once
#include "Seleccion.h"

namespace MultiLab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Presentacion
	/// </summary>
	public ref class Presentacion : public System::Windows::Forms::Form
	{
	public:
		Presentacion(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			fondo = gcnew Bitmap(gcnew System::String("Sprites/fondo.jpg"));
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Presentacion()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ btnEmpezar;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Timer^ timer1;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


	private:
		Graphics^ lienzo;
		Bitmap^ fondo;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btnEmpezar = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// btnEmpezar
			// 
			this->btnEmpezar->BackColor = System::Drawing::Color::Olive;
			this->btnEmpezar->Font = (gcnew System::Drawing::Font(L"Italic Outline Art", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(178)));
			this->btnEmpezar->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnEmpezar->Location = System::Drawing::Point(749, 545);
			this->btnEmpezar->Margin = System::Windows::Forms::Padding(4);
			this->btnEmpezar->Name = L"btnEmpezar";
			this->btnEmpezar->Size = System::Drawing::Size(353, 54);
			this->btnEmpezar->TabIndex = 1;
			this->btnEmpezar->Text = L"Empezar";
			this->btnEmpezar->UseVisualStyleBackColor = false;
			this->btnEmpezar->Click += gcnew System::EventHandler(this, &Presentacion::btnEmpezar_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Presentacion::timer1_Tick);
			// 
			// Presentacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1262, 673);
			this->Controls->Add(this->btnEmpezar);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Presentacion";
			this->Text = L"Presentacion";
			this->Load += gcnew System::EventHandler(this, &Presentacion::Presentacion_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnEmpezar_Click(System::Object^ sender, System::EventArgs^ e) {

		Seleccion^ seleccion = gcnew Seleccion();
		seleccion->ShowDialog();
		delete seleccion;
	}
	private: System::Void Presentacion_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		lienzo = this->CreateGraphics();
		BufferedGraphicsContext^ space = BufferedGraphicsManager::Current;

		BufferedGraphics^ buffer = space->Allocate(lienzo, this->ClientRectangle);
		int ancho = buffer->Graphics->VisibleClipBounds.Width;
		int alto = buffer->Graphics->VisibleClipBounds.Height;

		buffer->Graphics->DrawImage(fondo, 0, 0, ancho, alto);
		buffer->Render(lienzo);
		delete buffer;
		delete space;
	}
};
}
