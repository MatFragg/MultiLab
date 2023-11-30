#pragma once
#include "iostream"
#include "String.h"
#include "Enemigo.h"
#include "Enemigo2.h"
#include "Enemigo3.h"

using namespace System::Drawing;
using namespace std;

//define enum
enum Direcciones { Up, Down, Left, Right, Nothing };

class Personaje2
{
private:
	int x, y;
	int dx, dy;
	int W, H;
	int puntaje;
	int valorW = 0;
	string nombre_archivo;
	int indice_columnas, indice_filas;

public:
	Personaje2();
	~Personaje2();
	void cambia_dx_dy(Direcciones teclapulsada);
	void carga_imagen(string pnombre_archivo);
	void mostrar_imagen(Graphics^ lienzo);
	void mover_imagen(Direcciones teclapulsada);
	void colisionesEntorno2();
	void setX(int valor);
	void setY(int valor);
	void setPuntuacion(int valor);
	void setValor(int valor);
	void setDX(int valor);
	void setDY(int valor);


	int getValor();
	int getX();
	int getY();
	int getW();
	int getH();
	int getPuntuacion();
	int getDX();
	int getDY();

};

inline Personaje2::Personaje2()
{
	x = 30;
	y = 230;
	dx = 1;
	dy = 1;
	puntaje = 0;
	indice_columnas = indice_filas = 0;
}


inline Personaje2::~Personaje2()
{}

inline void Personaje2::cambia_dx_dy(Direcciones teclapulsada) {

	switch (teclapulsada) {
	case Up:	dx = 0; dy = -1; break;
	case Down:		dx = 0; dy = 1; break;
	case Right:	dx = 1; dy = 0; break;
	case Left: dx = -1; dy = 0; break;
	case Nothing:	dx = 0; dy = 0;  break;
	}
}

inline void Personaje2::carga_imagen(string pnombre_archivo)
{

	Bitmap^ miSprite = gcnew Bitmap(gcnew System::String("Sprites/Doctor.png"));

	W = miSprite->Width / 4;
	H = miSprite->Height / 4;

	delete miSprite;
}

inline void Personaje2::mostrar_imagen(Graphics^ lienzo)
{

	Bitmap^ miSprite = gcnew Bitmap(gcnew System::String("Sprites/Doctor.png"));

	Rectangle cuadro = Rectangle(indice_columnas * W, indice_filas * H, W, H);

	Rectangle zoom = Rectangle(x, y, W, H);

	lienzo->DrawImage(miSprite, zoom, cuadro, GraphicsUnit::Pixel);

}

inline void Personaje2::mover_imagen(Direcciones teclapulsada)
{
	if (teclapulsada == Up)		indice_filas = 2;
	if (teclapulsada == Down)		indice_filas = 3;
	if (teclapulsada == Right)	indice_filas = 0;
	if (teclapulsada == Left)  indice_filas = 1;

	indice_columnas++;
	if (indice_columnas > 3) indice_columnas = 0;

	x += dx;
	y += dy;


}


inline void Personaje2::setX(int valor) {
	x = valor;
}
inline void Personaje2::setY(int valor) {
	y = valor;
}

inline void Personaje2::setPuntuacion(int valor)
{
	puntaje = valor;
}

inline int Personaje2::getX()
{
	return x;
}
inline int Personaje2::getY()
{
	return y;
}
inline int Personaje2::getH()
{
	return H;
}
inline int Personaje2::getW()
{
	return W;
}

inline int Personaje2::getPuntuacion()
{
	return puntaje;
}

inline void Personaje2::setValor(int valor)
{
	valorW = valor;
}

inline int Personaje2::getValor()
{
	return valorW;

}
inline void Personaje2::setDX(int valor)
{
	dx = valor;
}

inline int Personaje2::getDX()
{
	return dx;

}

inline void Personaje2::setDY(int valor)
{
	dy = valor;
}

inline int Personaje2::getDY()
{
	return dy;

}

inline void Personaje2::colisionesEntorno2()
{
	// Colisiones Generales

	if (y + dy == 0 || y + dy == 430)
	{
		dy *= -1;

	}
	if (x + dx == 0)
	{
		dx *= -1;
	}

	//Lado Horizontal 1 - Pasillo Principal

	if (y + dy == 220 && x + dx > 0 && x + dx < 290)
	{
		dx *= -1;
		dy *= -1;
	}
	else if (y + dy == 170 && x + dx > 0 && x + dx < 290)
	{
		dy *= -1;
	}

	//Lado Horizontal 2 - Pasillo Principal
	if (y + dy == 220 && x + dx > 350 && x + dx < 440)
	{
		dx *= -1;
		dy *= -1;
	}
	else if (y + dy == 170 && x + dx > 350 && x + dx < 440)
	{
		dy *= -1;
	}

	//Lado Horizontal 3 - Pasillo Principal
	if (y + dy == 220 && x + dx > 500 && x + dx < 1000)
	{
		dx *= -1;
		dy *= -1;
	}
	else if (y + dy == 170 && x + dx > 500 && x + dx < 1000)
	{
		dy *= -1;
	}

	//Lado Horizontal 4 - Pasillo Principal

	if (y + dy == 240 && x + dx > 0 && x + dx < 200)
	{
		dy *= -1;
		dx *= -1;
	}
	else if (y + dy == 300 && x + dx > 0 && x + dx < 200)
	{
		dy *= -1;
		dx *= -1;
	}
	//Lado Horizontal 5 - Pasillo Principal
	if (y + dy == 240 && x + dx > 260 && x + dx < 540)
	{
		dy *= -1;
		dx *= -1;
	}
	else if (y + dy == 300 && x + dx > 260 && x + dx < 540)
	{
		dy *= -1;
		dx *= -1;
	}

	//Lado Horizontal 6 - Pasillo Principal

	if (y + dy == 240 && x + dx > 600 && x + dx < 810)
	{
		dy *= -1;
		dx *= -1;
	}
	else if (y + dy == 300 && x + dx > 600 && x + dx < 810)
	{
		dy *= -1;
		dx *= -1;
	}

	//Lado Horizontal 7 - Pasillo Principal

	if (y + dy == 240 && x + dx > 870 && x + dx < 1000)
	{
		dy *= -1;
		dx *= -1;
	}
	else if (y + dy == 300 && x + dx > 870 && x + dx < 1000)
	{
		dy *= -1;
		dx *= -1;
	}

	//Lado Horizontal 8
	if (y + dy == 30 && x + dx > 0 && x + dx < 130)
	{
		dy *= -1;
		dx *= -1;
	}
	else if (y + dy == 80 && x + dx > 0 && x + dx < 130)
	{
		dy *= -1;
		dx *= -1;
	}
	//lado Horizontal 9

	if (y + dy == 30 && x + dx > 190 && x + dx < 250)
	{
		dy *= -1;
		dx *= -1;
	}
	else if (y + dy == 80 && x + dx > 190 && x + dx < 250)
	{
		dy *= -1;
		dx *= -1;
	}

	//Lado Horizontal 10
	if (y + dy == 90 && x + dx > 60 && x + dx < 130)
	{
		dy *= -1;
		dx *= -1;
	}
	else if (y + dy == 150 && x + dx > 60 && x + dx < 130)
	{
		dy *= -1;
		dx *= -1;
	}
	//Lado Horizontal 11
	if (y + dy == 20 && x + dx > 350 && x + dx < 700)
	{
		dy *= -1;
		dx *= -1;
	}
	else if (y + dy == 60 && x + dx > 350 && x + dx < 700)
	{
		dy *= -1;
		dx *= -1;
	}
	//Lado Horizontal 12
	if (y + dy == 320 && x + dx > 210 && x + dx < 270)
	{
		dy *= -1;
		dx *= -1;
	}
	else if (y + dy == 380 && x + dx > 210 && x + dx < 270)
	{
		dy *= -1;
		dx *= -1;
	}
	//Lado Horizontal 13
	if (y + dy == 330 && x + dx > 330 && x + dx < 390)
	{
		dy *= -1;
		dx *= -1;
	}
	else if (y + dy == 380 && x + dx > 330 && x + dx < 390)
	{
		dy *= -1;
		dx *= -1;
	}

	//Lado Horizontal 14
	if (y + dy == 400 && x + dx > 270 && x + dx < 330)
	{
		dy *= -1;
		dx *= -1;
	}
	else if (y + dy == 450 && x + dx > 270 && x + dx < 330)
	{
		dy *= -1;
		dx *= -1;
	}
	//Lado Horizontal 15

	if (y + dy == 360 && x + dx > 600 && x + dx < 700)
	{
		dy *= -1;
		dx *= -1;
	}
	else if (y + dy == 410 && x + dx > 600 && x + dx < 700)
	{
		dy *= -1;
		dx *= -1;
	}

	//Lado Horizontal 16
	if (y + dy == 310 && x + dx > 800 && x + dx < 880)
	{
		dy *= -1;
		dx *= -1;
	}
	else if (y + dy == 350 && x + dx > 800 && x + dx < 880)
	{
		dy *= -1;
		dx *= -1;
	}

	//Lado Vertical 1

	if (x + dx == 250 && y + dy > 300 && y + dy < 360)
	{
		dx *= -1;
	}
	else if (x + dx == 280 && y + dy > 300 && y + dy < 360)
	{
		dx *= -1;
	}


	//Lado Vertical 2
	if (x + dx == 40 && y + dy > 100 && y + dy < 160)
	{
		dx *= -1;

	}
	else if (x + dx == 70 && y + dy > 100 && y + dy < 160)
	{
		dx *= -1;
	}

	//Lado Vertical 3
	if (x + dx == 250 && y + dy > 40 && y + dy < 160)
	{
		dx *= -1;

	}
	else if (x + dx == 280 && y + dy > 40 && y + dy < 160)
	{
		dx *= -1;
	}
	//Lado Lateral 4
	if (x + dx == 330 && y + dy > 0 && y + dy < 190)
	{
		dx *= -1;

	}
	else if (x + dx == 360 && y + dy > 0 && y + dy < 190)
	{
		dx *= -1;
	}
	//Lado Vertical 5
	if (x + dx == 480 && y + dy > 90 && y + dy < 220)
	{
		dx *= -1;
	}
	else if (x + dx == 510 && y + dy > 90 && y + dy < 220)
	{
		dx *= -1;
	}
	//Lado Vertical 6
	if (x + dx == 560 && y + dy > 30 && y + dy < 130)
	{
		dx *= -1;
	}
	if (x + dx == 590 && y + dy > 30 && y + dy < 130)
	{
		dx *= -1;
	}
	//Lado Vertical 7
	if (x + dx == 320 && y + dy > 370 && y + dy < 430)
	{
		dx *= -1;
	}
	else if (x + dx == 340 && y + dy > 370 && y + dy < 430)
	{
		dx *= -1;
	}
	//Lado Vertical 8

	if (x + dx == 530 && y + dy > 290 && y + dy < 430)
	{
		dx *= -1;
	}
	else if (x + dx == 560 && y + dy > 290 && y + dy < 430)
	{
		dx *= -1;
	}

	//Lado Vertical 9

	if (x + dx == 610 && y + dy > 290 && y + dy < 350)
	{
		dx *= -1;
	}
	else if (x + dx == 640 && y + dy > 290 && y + dy < 350)
	{
		dx *= -1;
	}

	//Lado Vertical 10

	if (x + dx == 780 && y + dy > 290 && y + dy < 320)
	{
		dx *= -1;
	}
	else if (x + dx == 810 && y + dy > 290 && y + dy < 320)
	{
		dx *= -1;
	}



	//Lado Vertical 11
	if (x + dx == 860 && y + dy > 290 && y + dy < 320)
	{
		dx *= -1;
	}
	else if (x + dx == 880 && y + dy > 290 && y + dy < 320)
	{
		dx *= -1;
	}



	x = dx + x;
	y = dy + y;

}