#pragma once

namespace MultiLab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Win
	/// </summary>
	public ref class Win : public System::Windows::Forms::Form
	{
	public:
		Win(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			youWon = gcnew Bitmap(gcnew System::String("Sprites/YouLose.jpg"));
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Win()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

	private:
		Bitmap^ youWon;
		Graphics^ lienzo;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Win::timer1_Tick);
			// 
			// Win
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(557, 486);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Win";
			this->Text = L"Win";
			this->Load += gcnew System::EventHandler(this, &Win::Win_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		lienzo = this->CreateGraphics();

		BufferedGraphicsContext^ space = BufferedGraphicsManager::Current;

		BufferedGraphics^ buffer = space->Allocate(lienzo, this->ClientRectangle);
		int ancho = buffer->Graphics->VisibleClipBounds.Width;
		int alto = buffer->Graphics->VisibleClipBounds.Height;

		buffer->Graphics->DrawImage(youWon, 0, 0, ancho, alto);
		buffer->Render(lienzo);
		delete buffer;
		delete space;
	}
		   
	private: System::Void Win_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
