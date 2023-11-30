#pragma once
#include "iostream"
#include <string.h>

using namespace System::Drawing;
using namespace std;

class Insecto2
{
public:
	Insecto2(int x, int y);
	~Insecto2();

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

inline Insecto2::Insecto2(int px, int py)
{
	x = px;
	y = py;
	dx = 0;
	dy = 3;


}

inline Insecto2::~Insecto2()
{
}


inline void Insecto2::carga_imagen(string pnombre_archivo)
{

	Bitmap^ spriteInsecto = gcnew Bitmap(gcnew System::String("Sprites/Insecto.png"));

	ancho = spriteInsecto->Width / 4;
	alto = spriteInsecto->Height / 4;

	delete spriteInsecto;
}

inline void Insecto2::movimiento(Graphics^ lienzo) {
	if (x > 1 || x < 800)
	{
		indiceX = indiceY = 0;
	}


	if (y + alto > 470)
	{
		dy *= -1;
	}
	else if (y <  218)
	{
		dy *= -1;
	}

	y += dy;


	show_imagen(lienzo);
}


inline void Insecto2::show_imagen(Graphics^ lienzo)
{

	Bitmap^ miSprite = gcnew Bitmap(gcnew System::String("Sprites/Insecto.png"));

	Rectangle cuadro = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);

	Rectangle zoom = Rectangle(x, y, ancho, alto);

	lienzo->DrawImage(miSprite, zoom, cuadro, GraphicsUnit::Pixel);
}

inline void Insecto2::parar_imagen()
{
	dx = 0;
	dy = 0;
}

inline void Insecto2::enviar_fuera()
{
	x = 1070;
	y = 140;

}

inline void Insecto2::setX(int valor) {
	x = valor;
}
inline void Insecto2::setY(int valor) {
	y = valor;
}

inline int Insecto2::getX() {
	return x;
}
inline int Insecto2::getY() {
	return y;
}
inline int Insecto2::getW() {
	return ancho;
}
inline int Insecto2::getH() {
	return alto;
}