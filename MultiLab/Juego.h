#pragma once
#include "Personajes.h"
#include "Frasco.h"
#include "Preguntas.h"
#include "Mezclador.h"
#include "Aersosol.h"
#include "Enemigo.h"
#include "Enemigo2.h"
#include "Lose.h"
#include "Win.h"

namespace MultiLab {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Juego
	/// </summary>
	public ref class Juego : public System::Windows::Forms::Form
	{
	public:
		Juego(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			objFrasco = new Quimico(18, 60);
			objFrasco->CargarImagen("Sprites/FrascoQ.png");

			objPersonaje = new Personaje();
			objPersonaje->carga_imagen("Sprites/Doctor.png");

			objElemento1 = new Elemento1(70, 420);
			objElemento1->CargarImagen("Sprites/Elementos.png");

			objElemento2 = new Elemento2(474, 60);
			objElemento2->CargarImagen("Sprites/Elementos.png");

			objElemento3 = new Elemento3(959, 63);
			objElemento3->CargarImagen("Sprites/Elementos.png");

			objElemento4 = new Elemento4(590, 430);
			objElemento4->CargarImagen("Sprites/Elementos.png");

			objElemento5 = new Elemento5(810, 286);
			objElemento5->CargarImagen("Sprites/Elementos.png");

			objInsecto1 = new Insecto(390, 35);
			objInsecto1->carga_imagen("Sprites/Insecto.png");

			objInsecto2 = new Insecto2(670, 235);
			objInsecto2->carga_imagen("Sprites/Insecto.png");

			objMezcladora = new Mezcla(320, 65);
			objMezcladora->CargarImagen("Sprites/Mezcladora.png");

			objAerosol = new Cura(332, 140);
			objAerosol->CargarImagen("Sprites/Aerosol.png");



			fondo = gcnew Bitmap(gcnew System::String("Sprites/Laboratorio.png"));
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Juego()
		{
			if (components)
			{
				delete components;
				delete objPersonaje;
				delete objElemento1;
				delete objElemento2;
				delete objElemento3;
				delete objElemento4;
				delete objElemento5;
				delete objInsecto1;

				delete objFrasco;
				delete objMezcladora;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ lblMensaje1;
	private: System::Windows::Forms::Label^ lblMensaje2;
	private: System::Windows::Forms::Label^ lblMensaje3;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		Personaje* objPersonaje;
		Elemento1* objElemento1;
		Elemento2* objElemento2;
		Elemento3* objElemento3;
		Elemento4* objElemento4;
		Elemento5* objElemento5;
		Insecto* objInsecto1;
		Insecto2* objInsecto2;

		Quimico* objFrasco;
		Direccion teclapulsada;
		Bitmap^ fondo;
		Graphics^ lienzo;
		Mezcla* objMezcladora;
		Cura* objAerosol;

		bool recoger;
		bool colision;
		bool colision2, colisionM;
		bool colisionInsecto;
		bool colisionInsecto2;
		bool colisionF = false;

		int valor;
		int valorP=0;
		int contador = 5;
		int vidas = 0;
		int ganar = 0;
		int enemigos = 2;//2;


	private: System::Windows::Forms::Label^ lblVidas;

	private: System::Windows::Forms::Label^ lblPuntuacion;
	private: System::Windows::Forms::Label^ lblPuntuacionC;

private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Label^ lblEnemigos;
private: System::Windows::Forms::Label^ lblEnemigosC;
	private: System::Windows::Forms::Label^ lblVidasC;




#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->lblMensaje1 = (gcnew System::Windows::Forms::Label());
			this->lblMensaje2 = (gcnew System::Windows::Forms::Label());
			this->lblMensaje3 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->lblVidasC = (gcnew System::Windows::Forms::Label());
			this->lblPuntuacion = (gcnew System::Windows::Forms::Label());
			this->lblPuntuacionC = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblEnemigos = (gcnew System::Windows::Forms::Label());
			this->lblEnemigosC = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblMensaje1
			// 
			this->lblMensaje1->AutoSize = true;
			this->lblMensaje1->BackColor = System::Drawing::Color::Black;
			this->lblMensaje1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->lblMensaje1->ForeColor = System::Drawing::Color::Yellow;
			this->lblMensaje1->Location = System::Drawing::Point(64, 516);
			this->lblMensaje1->Name = L"lblMensaje1";
			this->lblMensaje1->Size = System::Drawing::Size(11, 15);
			this->lblMensaje1->TabIndex = 1;
			this->lblMensaje1->Text = L"-";
			// 
			// lblMensaje2
			// 
			this->lblMensaje2->AutoSize = true;
			this->lblMensaje2->BackColor = System::Drawing::Color::Black;
			this->lblMensaje2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->lblMensaje2->ForeColor = System::Drawing::Color::White;
			this->lblMensaje2->Location = System::Drawing::Point(843, 514);
			this->lblMensaje2->Name = L"lblMensaje2";
			this->lblMensaje2->Size = System::Drawing::Size(122, 15);
			this->lblMensaje2->TabIndex = 2;
			this->lblMensaje2->Text = L"Elementos Faltantes:";
			this->lblMensaje2->Click += gcnew System::EventHandler(this, &Juego::lblMensaje2_Click);
			// 
			// lblMensaje3
			// 
			this->lblMensaje3->AutoSize = true;
			this->lblMensaje3->BackColor = System::Drawing::Color::Black;
			this->lblMensaje3->ForeColor = System::Drawing::Color::White;
			this->lblMensaje3->Location = System::Drawing::Point(984, 516);
			this->lblMensaje3->Name = L"lblMensaje3";
			this->lblMensaje3->Size = System::Drawing::Size(10, 13);
			this->lblMensaje3->TabIndex = 3;
			this->lblMensaje3->Text = L"-";
			this->lblMensaje3->Click += gcnew System::EventHandler(this, &Juego::lblMensaje3_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 35;
			this->timer1->Tick += gcnew System::EventHandler(this, &Juego::timer1_Tick);
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->BackColor = System::Drawing::Color::Black;
			this->lblVidas->ForeColor = System::Drawing::Color::LightCoral;
			this->lblVidas->Location = System::Drawing::Point(223, 516);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(132, 13);
			this->lblVidas->TabIndex = 4;
			this->lblVidas->Text = L"Exposicion a la Radiacion:";
			// 
			// lblVidasC
			// 
			this->lblVidasC->AutoSize = true;
			this->lblVidasC->BackColor = System::Drawing::Color::Black;
			this->lblVidasC->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->lblVidasC->Location = System::Drawing::Point(386, 516);
			this->lblVidasC->Name = L"lblVidasC";
			this->lblVidasC->Size = System::Drawing::Size(0, 13);
			this->lblVidasC->TabIndex = 5;
			// 
			// lblPuntuacion
			// 
			this->lblPuntuacion->AutoSize = true;
			this->lblPuntuacion->BackColor = System::Drawing::Color::Black;
			this->lblPuntuacion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->lblPuntuacion->ForeColor = System::Drawing::Color::Cyan;
			this->lblPuntuacion->Location = System::Drawing::Point(666, 514);
			this->lblPuntuacion->Name = L"lblPuntuacion";
			this->lblPuntuacion->Size = System::Drawing::Size(72, 15);
			this->lblPuntuacion->TabIndex = 7;
			this->lblPuntuacion->Text = L"Puntuacion:";
			// 
			// lblPuntuacionC
			// 
			this->lblPuntuacionC->AutoSize = true;
			this->lblPuntuacionC->BackColor = System::Drawing::Color::Black;
			this->lblPuntuacionC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->lblPuntuacionC->ForeColor = System::Drawing::Color::Cyan;
			this->lblPuntuacionC->Location = System::Drawing::Point(774, 516);
			this->lblPuntuacionC->Name = L"lblPuntuacionC";
			this->lblPuntuacionC->Size = System::Drawing::Size(11, 15);
			this->lblPuntuacionC->TabIndex = 8;
			this->lblPuntuacionC->Text = L"-";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Black;
			this->label2->ForeColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(1043, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(106, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Enemigos Eliminados";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Black;
			this->label1->ForeColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(434, 516);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(163, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Nivel Maximo de Radiación:  200";
			// 
			// lblEnemigos
			// 
			this->lblEnemigos->AutoSize = true;
			this->lblEnemigos->BackColor = System::Drawing::Color::Black;
			this->lblEnemigos->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->lblEnemigos->Location = System::Drawing::Point(1024, 514);
			this->lblEnemigos->Name = L"lblEnemigos";
			this->lblEnemigos->Size = System::Drawing::Size(107, 13);
			this->lblEnemigos->TabIndex = 12;
			this->lblEnemigos->Text = L"Enemigos Restantes:";
			// 
			// lblEnemigosC
			// 
			this->lblEnemigosC->AutoSize = true;
			this->lblEnemigosC->BackColor = System::Drawing::Color::Black;
			this->lblEnemigosC->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->lblEnemigosC->Location = System::Drawing::Point(1139, 514);
			this->lblEnemigosC->Name = L"lblEnemigosC";
			this->lblEnemigosC->Size = System::Drawing::Size(10, 13);
			this->lblEnemigosC->TabIndex = 13;
			this->lblEnemigosC->Text = L"-";
			// 
			// Juego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1176, 536);
			this->Controls->Add(this->lblEnemigosC);
			this->Controls->Add(this->lblEnemigos);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblPuntuacionC);
			this->Controls->Add(this->lblPuntuacion);
			this->Controls->Add(this->lblVidasC);
			this->Controls->Add(this->lblVidas);
			this->Controls->Add(this->lblMensaje3);
			this->Controls->Add(this->lblMensaje2);
			this->Controls->Add(this->lblMensaje1);
			this->Name = L"Juego";
			this->Text = L"Juego";
			this->Load += gcnew System::EventHandler(this, &Juego::Juego_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Juego::Juego_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Juego_Load(System::Object^ sender, System::EventArgs^ e) {
	
	}
	private: System::Void Juego_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {


		if (e->KeyCode == Keys::Up) teclapulsada = Direccion::Arriba;
		if (e->KeyCode == Keys::Down) teclapulsada = Direccion::Abajo;
		if (e->KeyCode == Keys::Right) teclapulsada = Direccion::Derecha;
		if (e->KeyCode == Keys::Left) teclapulsada = Direccion::Izquierda;


		//colision con objetos factores booleanos

		if (e->KeyCode == Keys::S && colision == true)
		{
			lblMensaje1->Text = "Objeto Recogido";
			contador = contador - 1;
			vidas = vidas - 5;
			valorP=valorP + 100;
			objPersonaje->setPuntuacion(valorP);
		}
		else
		{
			colision = false;
			lblMensaje1->Text = "-";
			contador = contador - 0;
		}



		//Abrir pestaña de preguntas
		if (e->KeyCode == Keys::D && colision2 == true && contador == 0 && colisionM==true)
		{
			Preguntas^ op = gcnew Preguntas();
			op->Show();
			contador = 5;
			objPersonaje->setPuntuacion(valorP);
		}
		else
		{
			colision = false;
		}



		//Recoger el frasco
		if (e->KeyCode==Keys::A && recoger == true && contador==5)
		{
			lblMensaje1->Text = "Frasco recogido";
		}


		//Para recoger el aerosol
		if (e->KeyCode == Keys::F && colisionF==true )
		{
			lblMensaje1->Text = "Aerosol recogido";
		}


		//Para salir de la Pabtalla
		if (e->KeyCode==Keys::Escape)
		{
			Close();
		}


		//Para detener un enemigo
		if (e->KeyCode==Keys::Space && colisionF==true)
		{
			objInsecto1->parar_imagen();
			objInsecto1->enviar_fuera();
			enemigos = enemigos - 1;
			colisionF = false;
		}

		if (e->KeyCode == Keys::Space && colisionF == false && colisionInsecto2 == true)
		{
			objInsecto2->parar_imagen();
			objInsecto2->enviar_fuera();
			enemigos = enemigos - 1;
			colisionF = false;
		}

		//Definiendo limite del contador

		if (contador < 0)
		{
			contador = 0;
		}

		//Para que no sobrepase las vidas
		if (vidas<0)
		{
			vidas = 0;
		}
		if (enemigos<0)
		{
			enemigos = 0;
		}



		//Movimiento por pasos a pasos

		objPersonaje->cambia_dx_dy(teclapulsada);
		objPersonaje->mover_imagen(teclapulsada);
		objPersonaje->colisionesEntorno1(lienzo);

	}


private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

	 lienzo = this->CreateGraphics();

	//Creacion de lienzo
	 BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
	 BufferedGraphics^ buffer = espacioBuffer->Allocate(lienzo, this->ClientRectangle);

	 buffer->Graphics->DrawImage(fondo, 0, 0, Rectangle(0, 0, this->ClientRectangle.Width,
		this->ClientRectangle.Height), GraphicsUnit::Pixel);

	 //Mostrasr Imagen en el buffer

	 objElemento1->MoverImagen(buffer->Graphics);
	 objElemento2->MoverImagen(buffer->Graphics);
	 objElemento3->MoverImagen(buffer->Graphics);
	 objElemento4->MoverImagen(buffer->Graphics);
	 objElemento5->MoverImagen(buffer->Graphics);

	 objPersonaje->mostrar_imagen(buffer->Graphics);
	 objFrasco->MoverImagen(buffer->Graphics);
	 objMezcladora->MoverImagen(buffer->Graphics);
	 objAerosol->MoverImagen(buffer->Graphics);

	 objInsecto1->movimiento(buffer->Graphics);
	 objInsecto2->movimiento(buffer->Graphics);

	 buffer->Render(lienzo);

	 //Eliminar estos espacios 

	 delete buffer;
	 delete espacioBuffer;

	 //Mensaje del Contador


	 lblMensaje3->Text = Convert::ToString(contador);
	 lblVidasC->Text = Convert::ToString(vidas);
	 lblPuntuacionC->Text=Convert::ToString(objPersonaje->getPuntuacion());
	 lblEnemigosC->Text = Convert::ToString(enemigos);


	 if (colisionInsecto)
	 {
		 vidas= vidas + 1;
	 }

	 if (colisionInsecto2)
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

	 if (vidas==250)
	 {
		 timer1->Interval = 10000;
		 Lose^ seleccion = gcnew Lose();
		 seleccion->ShowDialog();
		 delete seleccion;
	 }

	 // Colisiones entre objetos
	 // 
	 //Colision con los Elementos
	 if (Colision_por_Bounding_Box(objPersonaje->getX(), objPersonaje->getY(), objPersonaje->getW(), objPersonaje->getH(),
		 objElemento1->getX(), objElemento1->getY(), objElemento1->getW(), objElemento1->getH()) && recoger==true)
	 {
		 colision = true;
	 }
	 if (Colision_por_Bounding_Box(objPersonaje->getX(), objPersonaje->getY(), objPersonaje->getW(), objPersonaje->getH(),
		 objElemento2->getX(), objElemento2->getY(), objElemento2->getW(), objElemento2->getH()) && recoger == true)
	 {
		 colision = true;
	 }
	 if (Colision_por_Bounding_Box(objPersonaje->getX(), objPersonaje->getY(), objPersonaje->getW(), objPersonaje->getH(),
		 objElemento3->getX(), objElemento3->getY(), objElemento3->getW(), objElemento3->getH()) && recoger == true)
	 {
		 colision = true;
	 }
	 if (Colision_por_Bounding_Box(objPersonaje->getX(), objPersonaje->getY(), objPersonaje->getW(), objPersonaje->getH(),
		 objElemento4->getX(), objElemento4->getY(), objElemento4->getW(), objElemento4->getH()) && recoger == true)
	 {
		 colision = true;
	 }
	 if (Colision_por_Bounding_Box(objPersonaje->getX(), objPersonaje->getY(), objPersonaje->getW(), objPersonaje->getH(),
		 objElemento5->getX(), objElemento5->getY(), objElemento5->getW(), objElemento5->getH()) && recoger == true)
	 {
		 colision = true;
	 }
	 //Colision con el enemigo 
	 if (Colision_por_Bounding_Box(objPersonaje->getX(), objPersonaje->getY(), objPersonaje->getW(), objPersonaje->getH(),
		 objInsecto1->getX(), objInsecto1->getY(), objInsecto1->getW(), objInsecto1->getH()))
	 {
		 colisionInsecto = true;

	 }
	 else
	 {
		 colisionInsecto = false;
	 }

	 if (Colision_por_Bounding_Box(objPersonaje->getX(), objPersonaje->getY(), objPersonaje->getW(), objPersonaje->getH(),
		 objInsecto2->getX(), objInsecto2->getY(), objInsecto2->getW(), objInsecto2->getH()))
	 {
		 colisionInsecto2 = true;

	 }
	 else
	 {
		 colisionInsecto2 = false;
	 }



	 //Colsion con el Frasco
	 if (Colision_por_Bounding_Box(objPersonaje->getX(), objPersonaje->getY(), objPersonaje->getW(), objPersonaje->getH(),
		 objFrasco->getX(), objFrasco->getY(), objFrasco->getW(), objFrasco->getH()))
	 {
		 colision2 = true;
		 recoger = true;
	 }

	 //colision con la Maquina
	 if (Colision_por_Bounding_Box(objPersonaje->getX(), objPersonaje->getY(), objPersonaje->getW(), objPersonaje->getH(),
		 objMezcladora->getX(), objMezcladora->getY(), objMezcladora->getW(), objMezcladora->getH()))
	 {
		 colisionM = true;
	 }
	 //Colision con el Spray

	 if (Colision_por_Bounding_Box(objPersonaje->getX(), objPersonaje->getY(), objPersonaje->getW(), objPersonaje->getH(),
		 objAerosol->getX(), objAerosol->getY(), objAerosol->getW(), objAerosol->getH()))
	 {
		 colisionF = true;
	 }


    }

	   //Funciones que validan las colisiones 

	   bool Colision_por_Bounding_Box(int obj1X, int obj1Y, int obj1A, int obj1L,
		   int obj2X, int obj2Y, int obj2A, int obj2L)
	   {
		   return (obj1X + obj1A > obj2X && obj1X < obj2X + obj2A
			   && obj1Y + obj1L > obj2Y && obj1Y < obj2Y + obj2L);

	   }

private: System::Void lblMensaje2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblMensaje3_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
