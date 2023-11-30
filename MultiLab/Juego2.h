#pragma once
#include "Personaje2.h"
#include "Preguntas.h"
#include "Aersosol.h"
#include "Frasco.h"
#include "Mezclador.h"
#include "Enemigo.h"
#include "Enemigo2.h"
#include "Enemigo3.h"
#include "Win.h"
#include "Lose.h"

namespace MultiLab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Juego2
	/// </summary>
	public ref class Juego2 : public System::Windows::Forms::Form
	{
	public:
		Juego2(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//


			objPersonaje2 = new Personaje2();
			objPersonaje2->carga_imagen("Sprites/Doctor.png");

			objFrasco = new Quimico(18, 365);
			objFrasco->CargarImagen("Sprites/FrascoQ.png");

			objElemento1 = new Elemento1(18, 160);
			objElemento1->CargarImagen("Sprites/Elementos.png");

			objElemento2 = new Elemento2(175, 154);
			objElemento2->CargarImagen("Sprites/Elementos.png");

			objElemento3 = new Elemento3(959, 383);
			objElemento3->CargarImagen("Sprites/Elementos.png");

			objElemento4 = new Elemento4(750, 20);
			objElemento4->CargarImagen("Sprites/Elementos.png");

			objElemento5 = new Elemento5(832, 296);
			objElemento5->CargarImagen("Sprites/Elementos.png");

			objMezcladora = new Mezcla(380, 415);
			objMezcladora->CargarImagen("Sprites/Mezcladora.png");

			objAerosol = new Cura(518, 370);
			objAerosol->CargarImagen("Sprites/Aerosol.png");

			objInsecto1 = new Insecto(300, 35);
			objInsecto1->carga_imagen("Sprites/Insecto.png");

			objInsecto2 = new Insecto2(570, 235);
			objInsecto2->carga_imagen("Sprites/Insecto.png");

			objInsecto3 = new Insecto3(670, 235);
			objInsecto3->carga_imagen("Sprites/Insecto.png");



			fondo = gcnew Bitmap(gcnew System::String("Sprites/Laboratorio2.png"));

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Juego2()
		{
			if (components)
			{
				delete components;
				delete components;
				delete objPersonaje2;
				delete objElemento1;
				delete objElemento2;
				delete objElemento3;
				delete objElemento4;
				delete objElemento5;
				delete objInsecto1;
				delete objInsecto2;
				delete objInsecto3;

				delete objFrasco;
				delete objMezcladora;
			}
		}



	protected:

	protected:


	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

		Personaje2* objPersonaje2;
		Direcciones teclapulsada;
		Bitmap^ fondo;
		Graphics^ lienzo;
		Quimico* objFrasco;
		Mezcla* objMezcladora;
		Cura* objAerosol;
		Insecto* objInsecto1;
		Insecto2* objInsecto2;
		Insecto3* objInsecto3;


		Elemento1* objElemento1;
		Elemento2* objElemento2;
		Elemento3* objElemento3;
		Elemento4* objElemento4;
		Elemento5* objElemento5;

		bool recoger;
		bool colision;
		bool colision2,colisionM;
		bool colisionInsecto;
		bool colisionInsecto2;
		bool colisionInsecto3;
		bool colisionF = false;

		int valor;
		int valorP = 0;
		int contador = 5;
		int vidas = 0;
		int enemigos = 3;
		int aumento = 0;




private: System::Windows::Forms::Label^ lblMensaje21;
private: System::Windows::Forms::Label^ lblVidas2;
private: System::Windows::Forms::Label^ lblPuntuacion2;
private: System::Windows::Forms::Label^ lblPuntuacionC2;
private: System::Windows::Forms::Label^ lblMensaje22;

private: System::Windows::Forms::Label^ lblMensaje23;
private: System::Windows::Forms::Label^ lblVidasC2;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Label^ lblEnemigoC2;




#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblMensaje21 = (gcnew System::Windows::Forms::Label());
			this->lblVidas2 = (gcnew System::Windows::Forms::Label());
			this->lblPuntuacion2 = (gcnew System::Windows::Forms::Label());
			this->lblPuntuacionC2 = (gcnew System::Windows::Forms::Label());
			this->lblMensaje22 = (gcnew System::Windows::Forms::Label());
			this->lblMensaje23 = (gcnew System::Windows::Forms::Label());
			this->lblVidasC2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblEnemigoC2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 30;
			this->timer1->Tick += gcnew System::EventHandler(this, &Juego2::timer1_Tick);
			// 
			// lblMensaje21
			// 
			this->lblMensaje21->AutoSize = true;
			this->lblMensaje21->BackColor = System::Drawing::Color::Black;
			this->lblMensaje21->ForeColor = System::Drawing::Color::Yellow;
			this->lblMensaje21->Location = System::Drawing::Point(47, 512);
			this->lblMensaje21->Name = L"lblMensaje21";
			this->lblMensaje21->Size = System::Drawing::Size(10, 13);
			this->lblMensaje21->TabIndex = 15;
			this->lblMensaje21->Text = L"-";
			// 
			// lblVidas2
			// 
			this->lblVidas2->AutoSize = true;
			this->lblVidas2->BackColor = System::Drawing::Color::Black;
			this->lblVidas2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->lblVidas2->Location = System::Drawing::Point(205, 512);
			this->lblVidas2->Name = L"lblVidas2";
			this->lblVidas2->Size = System::Drawing::Size(132, 13);
			this->lblVidas2->TabIndex = 16;
			this->lblVidas2->Text = L"Exposicion a la Radiación:";
			this->lblVidas2->Click += gcnew System::EventHandler(this, &Juego2::lblVidas2_Click);
			// 
			// lblPuntuacion2
			// 
			this->lblPuntuacion2->AutoSize = true;
			this->lblPuntuacion2->BackColor = System::Drawing::Color::Black;
			this->lblPuntuacion2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->lblPuntuacion2->ForeColor = System::Drawing::Color::Cyan;
			this->lblPuntuacion2->Location = System::Drawing::Point(648, 510);
			this->lblPuntuacion2->Name = L"lblPuntuacion2";
			this->lblPuntuacion2->Size = System::Drawing::Size(72, 15);
			this->lblPuntuacion2->TabIndex = 17;
			this->lblPuntuacion2->Text = L"Puntuación:";
			// 
			// lblPuntuacionC2
			// 
			this->lblPuntuacionC2->AutoSize = true;
			this->lblPuntuacionC2->BackColor = System::Drawing::Color::Black;
			this->lblPuntuacionC2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->lblPuntuacionC2->ForeColor = System::Drawing::Color::Cyan;
			this->lblPuntuacionC2->Location = System::Drawing::Point(756, 510);
			this->lblPuntuacionC2->Name = L"lblPuntuacionC2";
			this->lblPuntuacionC2->Size = System::Drawing::Size(11, 15);
			this->lblPuntuacionC2->TabIndex = 18;
			this->lblPuntuacionC2->Text = L"-";
			// 
			// lblMensaje22
			// 
			this->lblMensaje22->AutoSize = true;
			this->lblMensaje22->BackColor = System::Drawing::Color::Black;
			this->lblMensaje22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->lblMensaje22->ForeColor = System::Drawing::Color::White;
			this->lblMensaje22->Location = System::Drawing::Point(825, 510);
			this->lblMensaje22->Name = L"lblMensaje22";
			this->lblMensaje22->Size = System::Drawing::Size(124, 15);
			this->lblMensaje22->TabIndex = 19;
			this->lblMensaje22->Text = L"Elementos Restantes";
			// 
			// lblMensaje23
			// 
			this->lblMensaje23->AutoSize = true;
			this->lblMensaje23->BackColor = System::Drawing::Color::Black;
			this->lblMensaje23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->lblMensaje23->ForeColor = System::Drawing::Color::White;
			this->lblMensaje23->Location = System::Drawing::Point(966, 510);
			this->lblMensaje23->Name = L"lblMensaje23";
			this->lblMensaje23->Size = System::Drawing::Size(11, 15);
			this->lblMensaje23->TabIndex = 21;
			this->lblMensaje23->Text = L"-";
			// 
			// lblVidasC2
			// 
			this->lblVidasC2->AutoSize = true;
			this->lblVidasC2->BackColor = System::Drawing::Color::Black;
			this->lblVidasC2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->lblVidasC2->Location = System::Drawing::Point(358, 512);
			this->lblVidasC2->Name = L"lblVidasC2";
			this->lblVidasC2->Size = System::Drawing::Size(10, 13);
			this->lblVidasC2->TabIndex = 22;
			this->lblVidasC2->Text = L"-";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->ForeColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(416, 512);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(163, 13);
			this->label1->TabIndex = 23;
			this->label1->Text = L"Nivel Maximo de Radiación:  300";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label2->Location = System::Drawing::Point(1006, 510);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 13);
			this->label2->TabIndex = 24;
			this->label2->Text = L"Enemigos Restantes:";
			// 
			// lblEnemigoC2
			// 
			this->lblEnemigoC2->AutoSize = true;
			this->lblEnemigoC2->BackColor = System::Drawing::Color::Black;
			this->lblEnemigoC2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->lblEnemigoC2->Location = System::Drawing::Point(1121, 510);
			this->lblEnemigoC2->Name = L"lblEnemigoC2";
			this->lblEnemigoC2->Size = System::Drawing::Size(13, 13);
			this->lblEnemigoC2->TabIndex = 25;
			this->lblEnemigoC2->Text = L"3";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Black;
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(1037, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(106, 13);
			this->label3->TabIndex = 26;
			this->label3->Text = L"Enemigos Eliminados";
			this->label3->Click += gcnew System::EventHandler(this, &Juego2::label3_Click);
			// 
			// Juego2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1176, 536);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lblEnemigoC2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lblVidasC2);
			this->Controls->Add(this->lblMensaje23);
			this->Controls->Add(this->lblMensaje22);
			this->Controls->Add(this->lblPuntuacionC2);
			this->Controls->Add(this->lblPuntuacion2);
			this->Controls->Add(this->lblVidas2);
			this->Controls->Add(this->lblMensaje21);
			this->Name = L"Juego2";
			this->Text = L"Juego2";
			this->Load += gcnew System::EventHandler(this, &Juego2::Juego2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego2::Juego2_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Juego2_Load(System::Object^ sender, System::EventArgs^ e) {


	}
	private: System::Void Juego2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

		if (e->KeyCode == Keys::Up) teclapulsada = Direcciones::Up;
		if (e->KeyCode == Keys::Down) teclapulsada = Direcciones::Down;
		if (e->KeyCode == Keys::Right) teclapulsada = Direcciones::Right;
		if (e->KeyCode == Keys::Left) teclapulsada = Direcciones::Left;


		objPersonaje2->cambia_dx_dy(teclapulsada);
		objPersonaje2->mover_imagen(teclapulsada);
		objPersonaje2->colisionesEntorno2();

		if (e->KeyCode == Keys::S && colision == true)
		{
			lblMensaje21->Text = "Objeto Recogido";
			contador = contador - 1;
			vidas = vidas - 5;
			valorP = valorP + 100;
			objPersonaje2->setPuntuacion(valorP);
		}
		else
		{
			colision = false;
			lblMensaje21->Text = "-";
			contador = contador - 0;
		}

		if (e->KeyCode == Keys::D && colision2 == true && contador == 0 && colisionM == true)
		{
			Preguntas^ op = gcnew Preguntas();
			op->Show();
			contador = 5;
			objPersonaje2->setPuntuacion(valorP);
		}
		else
		{
			colision = false;
		}
		//recoger el frasco

		if (e->KeyCode == Keys::A && recoger == true && contador == 5)
		{
			lblMensaje21->Text = "Frasco recogido";
		}

		//Para recoger el aerosol
		if (e->KeyCode == Keys::F && colisionF == true)
		{
			lblMensaje21->Text = "Aerosol recogido";
			aumento = aumento + 1;
		}

		//Para salir de la Pabtalla
		if (e->KeyCode == Keys::Escape)
		{
			Close();
		}

		//Para detener un enemigo
		if (e->KeyCode == Keys::Space &&  aumento==1 && colisionInsecto==true  )
		{
			objInsecto1->parar_imagen();
			objInsecto1->enviar_fuera();
			enemigos = enemigos - 1;
		}
		if (e->KeyCode == Keys::Space && aumento==2 && colisionInsecto3 == true)
		{
			objInsecto3->parar_imagen();
			objInsecto3->enviar_fuera();
			enemigos = enemigos - 1;
		}

		if (e->KeyCode == Keys::Space && aumento==3 && colisionInsecto2 == true)
		{
			objInsecto2->parar_imagen();
			objInsecto2->enviar_fuera();
			enemigos = enemigos - 1;
		}



		//Definiendo limite del contador

		if (contador < 0)
		{
			contador = 0;
		}

		//Para que no sobrepase las vidas
		if (vidas < 0)
		{
			vidas = 0;
		}
		if (enemigos < 0)
		{
			enemigos = 0;
		}


	}

		   bool Colision_por_Bounding_Box(int obj1X, int obj1Y, int obj1A, int obj1L,
			   int obj2X, int obj2Y, int obj2A, int obj2L)
		   {
			   return (obj1X + obj1A > obj2X && obj1X < obj2X + obj2A
				   && obj1Y + obj1L > obj2Y && obj1Y < obj2Y + obj2L);

		   }


private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

	lienzo = this->CreateGraphics();

	//Creacion de lienzo
	BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
	BufferedGraphics^ buffer = espacioBuffer->Allocate(lienzo, this->ClientRectangle);

	buffer->Graphics->DrawImage(fondo, 0, 0, Rectangle(0, 0, this->ClientRectangle.Width,
		this->ClientRectangle.Height), GraphicsUnit::Pixel);

	objPersonaje2->mostrar_imagen(buffer->Graphics);

	objElemento1->MoverImagen(buffer->Graphics);
	objElemento2->MoverImagen(buffer->Graphics);
	objElemento3->MoverImagen(buffer->Graphics);
	objElemento4->MoverImagen(buffer->Graphics);
	objElemento5->MoverImagen(buffer->Graphics);

	objPersonaje2->mostrar_imagen(buffer->Graphics);
	objFrasco->MoverImagen(buffer->Graphics);
	objMezcladora->MoverImagen(buffer->Graphics);
	objAerosol->MoverImagen(buffer->Graphics);

	objInsecto1->movimiento(buffer->Graphics);
	objInsecto3->movimiento(buffer->Graphics);
	objInsecto2->movimiento(buffer->Graphics);


	buffer->Render(lienzo);



	//Eliminar estos espacios 

	delete buffer;
	delete espacioBuffer;

	lblMensaje23->Text = Convert::ToString(contador);
	lblVidasC2->Text = Convert::ToString(vidas);
	lblPuntuacionC2->Text = Convert::ToString(objPersonaje2->getPuntuacion());
	lblEnemigoC2->Text = Convert::ToString(enemigos);

	if (colisionInsecto)
	{
		vidas = vidas + 1;
	}

	if (colisionInsecto2)
	{
		vidas = vidas + 1;
	}
	if (colisionInsecto3)
	{
		vidas = vidas + 1;
	}
	//Ganar o perder 
	if (enemigos == 0)
	{
		timer1->Interval = 10000;
		Win^ seleccion = gcnew Win();
		seleccion->ShowDialog();
		delete seleccion;
	}

	if (vidas == 500)
	{
		timer1->Interval = 10000;
		Lose^ seleccion = gcnew Lose();
		seleccion->ShowDialog();
		delete seleccion;
	}

	// Colisiones entre objetos
    // 
    //Colision con los Elementos

	if (Colision_por_Bounding_Box(objPersonaje2->getX(), objPersonaje2->getY(), objPersonaje2->getW(), objPersonaje2->getH(),
		objElemento1->getX(), objElemento1->getY(), objElemento1->getW(), objElemento1->getH()) && recoger == true)
	{
		colision = true;
	}
	if (Colision_por_Bounding_Box(objPersonaje2->getX(), objPersonaje2->getY(), objPersonaje2->getW(), objPersonaje2->getH(),
		objElemento2->getX(), objElemento2->getY(), objElemento2->getW(), objElemento2->getH()) && recoger == true)
	{
		colision = true;
	}
	if (Colision_por_Bounding_Box(objPersonaje2->getX(), objPersonaje2->getY(), objPersonaje2->getW(), objPersonaje2->getH(),
		objElemento3->getX(), objElemento3->getY(), objElemento3->getW(), objElemento3->getH()) && recoger == true)
	{
		colision = true;
	}
	if (Colision_por_Bounding_Box(objPersonaje2->getX(), objPersonaje2->getY(), objPersonaje2->getW(), objPersonaje2->getH(),
		objElemento4->getX(), objElemento4->getY(), objElemento4->getW(), objElemento4->getH()) && recoger == true)
	{
		colision = true;
	}
	if (Colision_por_Bounding_Box(objPersonaje2->getX(), objPersonaje2->getY(), objPersonaje2->getW(), objPersonaje2->getH(),
		objElemento5->getX(), objElemento5->getY(), objElemento5->getW(), objElemento5->getH()) && recoger == true)
	{
		colision = true;
	}

	//Colsion con el Frasco
	if (Colision_por_Bounding_Box(objPersonaje2->getX(), objPersonaje2->getY(), objPersonaje2->getW(), objPersonaje2->getH(),
		objFrasco->getX(), objFrasco->getY(), objFrasco->getW(), objFrasco->getH()))
	{
		colision2 = true;
		recoger = true;
	}
	//colision con la Maquina
	if (Colision_por_Bounding_Box(objPersonaje2->getX(), objPersonaje2->getY(), objPersonaje2->getW(), objPersonaje2->getH(),
		objMezcladora->getX(), objMezcladora->getY(), objMezcladora->getW(), objMezcladora->getH()))
	{
		colisionM = true;
	}

	//colision con el Frasco
	if (Colision_por_Bounding_Box(objPersonaje2->getX(), objPersonaje2->getY(), objPersonaje2->getW(), objPersonaje2->getH(),
		objAerosol->getX(), objAerosol->getY(), objAerosol->getW(), objAerosol->getH()))
	{
		colisionF = true;
	}

	//Colision con el enemigo
	if (Colision_por_Bounding_Box(objPersonaje2->getX(), objPersonaje2->getY(), objPersonaje2->getW(), objPersonaje2->getH(),
		objInsecto1->getX(), objInsecto1->getY(), objInsecto1->getW(), objInsecto1->getH()))
	{
		colisionInsecto = true;

	}
	else
	{
		colisionInsecto = false;
	}

	if (Colision_por_Bounding_Box(objPersonaje2->getX(), objPersonaje2->getY(), objPersonaje2->getW(), objPersonaje2->getH(),
		objInsecto2->getX(), objInsecto2->getY(), objInsecto2->getW(), objInsecto2->getH()))
	{
		colisionInsecto2 = true;

	}
	else
	{
		colisionInsecto2 = false;
	}

	if (Colision_por_Bounding_Box(objPersonaje2->getX(), objPersonaje2->getY(), objPersonaje2->getW(), objPersonaje2->getH(),
		objInsecto3->getX(), objInsecto3->getY(), objInsecto3->getW(), objInsecto3->getH()))
	{
		colisionInsecto3 = true;

	}
	else
	{
		colisionInsecto3 = false;
	}

    }
	private: System::Void lblVidas2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
