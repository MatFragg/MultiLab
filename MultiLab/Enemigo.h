#pragma once
#include "iostream"
#include <string.h>

using namespace System::Drawing;
using namespace std;

class Insecto
{	
public:
	Insecto(int x,int y);
	~Insecto();

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

inline Insecto::Insecto(int px,int py)
{
	x = px;
	y = py;
	dx = 0;
	dy = 3;


}

inline Insecto::~Insecto()
{
}


inline void Insecto::carga_imagen(string pnombre_archivo)
{

	Bitmap^ spriteInsecto = gcnew Bitmap(gcnew System::String("Sprites/Insecto.png"));

	ancho = spriteInsecto->Width / 4;
	alto = spriteInsecto->Height / 4;

	delete spriteInsecto;
}

inline void Insecto::movimiento(Graphics^ lienzo) {
	if (x > 1 || x < 800)
	{
		indiceX = indiceY = 0;
	}
	y += dy;
	if (y + alto > lienzo->VisibleClipBounds.Height - 285) dy *= -1;
	else if (y < 0 ) dy *= -1;

	
	
	
	show_imagen(lienzo);
}


inline void Insecto::show_imagen(Graphics^ lienzo)
{

	Bitmap^ miSprite = gcnew Bitmap(gcnew System::String("Sprites/Insecto.png"));

	Rectangle cuadro = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);

	Rectangle zoom = Rectangle(x, y, ancho , alto);

	lienzo->DrawImage(miSprite, zoom, cuadro, GraphicsUnit::Pixel);
}

inline void Insecto::parar_imagen()
{
	dx = 0;
	dy = 0;
}

inline void Insecto::enviar_fuera()
{
	x = 1070;
	y = 40;

}

inline void Insecto::setX(int valor) {
	x = valor;
}
inline void Insecto::setY(int valor) {
	y = valor;
}

inline int Insecto::getX() {
	return x;
}
inline int Insecto::getY() {
	return y;
}
inline int Insecto::getW() {
	return ancho;
}
inline int Insecto::getH() {
	return alto;
}