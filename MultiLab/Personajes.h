#pragma once
#include "iostream"
#include "String.h"
#include "ElementosQ1.h"
#include "ElementosQ2.h"
#include "ElementoQ3.h"
#include "ElementoQ4.h"
#include "ElementoQ5.h"

using namespace System::Drawing;
using namespace std;

//define enum
enum Direccion { Arriba, Abajo, Izquierda, Derecha, Ninguno };

class Personaje
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
	Personaje();
	Personaje(int px, int py);
	~Personaje();
	void cambia_dx_dy(Direccion teclapulsada);
	void carga_imagen(string pnombre_archivo);
	void mostrar_imagen(Graphics^ lienzo);
	void mover_imagen(Direccion teclapulsada);
	void colisionesEntorno1(Graphics^ lienzo);
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

inline Personaje::Personaje()
{
	x = 940;
	y = 200;
	dx = 1; 
	dy = 1;
	puntaje = 0;
	indice_columnas = indice_filas = 0;
}

inline Personaje::Personaje(int px, int py)
{
	x = px;
	y = py;
	dx = 1;
	dy = 1;
	puntaje = 0;
	indice_columnas = indice_filas = 0;

}

inline Personaje::~Personaje()
{}

inline void Personaje::cambia_dx_dy(Direccion teclapulsada) {

	switch (teclapulsada) {
	case Arriba:	dx = 0; dy = -1; break;
	case Abajo:		dx = 0; dy = 1; break;
	case Derecha:	dx = 1; dy = 0; break;
	case Izquierda: dx = -1; dy = 0; break;
	case Ninguno:	dx = 0; dy = 0;  break;
	}
}

inline void Personaje::carga_imagen(string pnombre_archivo)
{

	Bitmap^ miSprite = gcnew Bitmap(gcnew System::String("Sprites/Doctor.png"));

	W = miSprite->Width / 4;
	H = miSprite->Height / 4;

	delete miSprite;
}

inline void Personaje::mostrar_imagen(Graphics^ lienzo)
{

	Bitmap^ miSprite = gcnew Bitmap(gcnew System::String("Sprites/Doctor.png"));

	Rectangle cuadro = Rectangle(indice_columnas * W, indice_filas * H, W, H);

	Rectangle zoom = Rectangle(x, y, W, H);

	lienzo->DrawImage(miSprite, zoom, cuadro, GraphicsUnit::Pixel);

}

inline void Personaje::mover_imagen(Direccion teclapulsada)
{
	if (teclapulsada == Arriba)		indice_filas = 2;
	if (teclapulsada == Abajo)		indice_filas = 3;
	if (teclapulsada == Derecha)	indice_filas = 0;
	if (teclapulsada == Izquierda)  indice_filas = 1;

	indice_columnas++;
	if (indice_columnas > 3) indice_columnas = 0;

	x += dx;
	y += dy;


}


inline void Personaje::setX(int valor) {
	x = valor;
}
inline void Personaje::setY(int valor) {
	y = valor;
}

inline void Personaje::setPuntuacion(int valor)
{
	puntaje = valor;
}

inline int Personaje::getX()
{
	return x;
}
inline int Personaje::getY()
{
	return y;
}
inline int Personaje::getH()
{
	return H;
}
inline int Personaje::getW()
{
	return W;
}

inline int Personaje::getPuntuacion()
{
	return puntaje;
}

inline void Personaje::setValor(int valor)
{
	valorW = valor;
}

inline int Personaje::getValor()
{
	return valorW;

}
inline void Personaje::setDX(int valor)
{
	dx = valor;
}

inline int Personaje::getDX()
{
	return dx;

}

inline void Personaje::setDY(int valor)
{
	dy = valor;
}

inline int Personaje::getDY()
{
	return dy;

}

inline void Personaje::colisionesEntorno1(Graphics^ lienzo)
{
	//Colisiones Generales
	if (y + dy == 0 || y + dy == 430)
	{
		dy *= -1;
	}
	if (x + dx == 0 || x + dx == 990)
	{
		dx *= -1;
	}

	//Lado Horizontal 1
	if (y + dy == 190 && x + dx > 774 && x + dx < 1000)
	{
		dx *= -1;
		dy *= -1;
	}
	else if (y + dy == 140 && x + dx > 774 && x + dx < 1000)
	{
		dy *= -1;
	}

	//Lado Horizontal 2

	if (y + dy == 190 && x + dx > 434 && x + dx < 720)
	{
		dx *= -1;
		dy *= -1;
	}
	else if (y + dy == 140 && x + dx > 434 && x + dx < 720)
	{
		dy *= -1;
	}

	//Lado Horizontal 3

	if (y + dy == 190 && x + dx > 175 && x + dx < 360)
	{
		dx *= -1;
		dy *= -1;
	}
	else if (y + dy == 140 && x + dx > 175 && x + dx < 360)
	{
		dy *= -1;
	}

	//Lado Horizontal 4
	if (y + dy == 190 && x + dx > 1 && x + dx < 120)
	{
		dx *= -1;
		dy *= -1;
	}
	else if (y + dy == 140 && x + dx > 1 && x + dx < 120)
	{
		dy *= -1;
	}
	// Lado Horizontal 5

	if (y + dy == 220 && x + dx > 1 && x + dx < 320)
	{
		dy *= -1;
	}
	else if (y + dy == 270 && x + dx > 1 && x + dx < 320)
	{
		dy *= -1;
		dx *= -1;
	}

	// Lado Horizontal 6

	if (y + dy == 220 && x + dx > 380 && x + dx < 650)
	{
		dy *= -1;
	}
	else if (y + dy == 270 && x + dx > 380 && x + dx < 650)
	{
		dy *= -1;
		dx *= -1;
	}
	// Lado Horizontal 7

	if (y + dy == 220 && x + dx > 700 && x + dx < 1000)
	{
		dy *= -1;
	}
	else if (y + dy == 270 && x + dx > 700 && x + dx < 1000)
	{
		dy *= -1;
		dx *= -1;
	}

	//Lado Vertical 1
	if (x + dx == 700 && y + dy > 220 && y + dy < 360)
	{
		dx *= -1;
	}
	else if (x + dx == 730 && y + dy > 220 && y + dy < 360)
	{
		dx *= -1;
	}

	//Lado Vertical 2

	if (x + dx == 700 && y + dy > 410 && y + dy < 480)
	{
		dx *= -1;
	}
	else if (x + dx == 730 && y + dy > 410 && y + dy < 480)
	{
		dx *= -1;
	}

	//Lado Vertical 3
	if (x + dx == 620 && y + dy > 220 && y + dy < 480)
	{
		dx *= -1;
	}
	else if (x + dx == 650 && y + dy > 220 && y + dy < 480)
	{
		dx *= -1;
	}

	//Lado Vertical 4

	if (x + dx == 340 && y + dy > 0 && y + dy < 170)
	{
		dx *= -1;
	}
	else if (x + dx == 370 && y + dy > 0 && y + dy < 170)
	{
		dx *= -1;
	}

	//Lado Vertical 5

	if (x + dx == 420 && y + dy > 0 && y + dy < 170)
	{
		dx *= -1;
	}
	else if (x + dx == 450 && y + dy > 0 && y + dy < 170)
	{
		dx *= -1;
	}
	x = dx + x;
	y = dy + y;

}