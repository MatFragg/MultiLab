#pragma once
#include "iostream"
#include <string.h>

using namespace System::Drawing;
using namespace std;

class Insecto3
{
public:
	Insecto3(int x, int y);
	~Insecto3();

	void carga_imagen(string pnombre_archivo);
	void movimiento(Graphics^ lienzo);
	void show_imagen(Graphics^ lienzo);
	void parar_imagen();
	void enviar_fuera();

	void setX(int valor);
	void setY(int valor);

	int getX();
	int getY();
	int getW();
	int getH();

private:
	int x, y, dx, dy, ancho, alto, indiceX, indiceY;

};

inline Insecto3::Insecto3(int px, int py)
{
	x = px;
	y = py;
	dx = 3;
	dy = 0;


}

inline Insecto3::~Insecto3()
{
}


inline void Insecto3::carga_imagen(string pnombre_archivo)
{

	Bitmap^ spriteInsecto = gcnew Bitmap(gcnew System::String("Sprites/Insecto.png"));

	ancho = spriteInsecto->Width / 4;
	alto = spriteInsecto->Height / 4;

	delete spriteInsecto;
}

inline void Insecto3::movimiento(Graphics^ lienzo) {
	if (y > 1 || y < 500)
	{
		indiceX = indiceY = 0;
	}


	if (x-ancho< 300 || x + ancho> 900)
	{
		dx *= -1;
	}

	x += dx;
	y += dy;


	show_imagen(lienzo);
}


inline void Insecto3::show_imagen(Graphics^ lienzo)
{

	Bitmap^ miSprite = gcnew Bitmap(gcnew System::String("Sprites/Insecto.png"));

	Rectangle cuadro = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);

	Rectangle zoom = Rectangle(x, y, ancho, alto);

	lienzo->DrawImage(miSprite, zoom, cuadro, GraphicsUnit::Pixel);
}

inline void Insecto3::parar_imagen()
{
	dx = 0;
	dy = 0;
}

inline void Insecto3::enviar_fuera()
{
	x = 1070;
	y = 240;

}

inline void Insecto3::setX(int valor) {
	x = valor;
}
inline void Insecto3::setY(int valor) {
	y = valor;
}

inline int Insecto3::getX() {
	return x;
}
inline int Insecto3::getY() {
	return y;
}
inline int Insecto3::getW() {
	return ancho;
}
inline int Insecto3::getH() {
	return alto;
}