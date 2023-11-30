#pragma once
#include "iostream"
#include "string.h"
using namespace System::Drawing;
using namespace std;

class Mezcla
{
public:
	Mezcla(int px, int py);
	~Mezcla();
	void CargarImagen(string pnombre_archivo);
	void MoverImagen(Graphics^ lienzo);
	void MostrarImagen(Graphics^ lienzo);


	void setX(int valor);
	void setY(int valor);

	int getX();
	int getY();
	int getW();
	int getH();

private:
	int x, y;
	int W, H;
	int dx, dy;
	int width, height;
	int indiceFilas, indiceColumnas;
};

inline Mezcla::Mezcla(int px, int py)
{
	x = px;
	y = py;
	dx = 0;
	dy = 0;
}

inline Mezcla::~Mezcla()
{

}

inline void Mezcla::CargarImagen(string pnombre_archivo)
{
	Bitmap^ SpriteE1 = gcnew Bitmap(gcnew System::String("Sprites/Mezcladora.png"));

	//ahora.. hallamos el W, H de cada imagen
	W = SpriteE1->Width / 1;
	H = SpriteE1->Height / 1;

	delete SpriteE1;
}
inline void Mezcla::MoverImagen(Graphics^ lienzo)
{
	if (x > 1 || x < 800)
	{
		indiceFilas = indiceColumnas = 0;
	}

	x = x + dx;
	y = y + dy;

	MostrarImagen(lienzo);
}
inline void Mezcla::MostrarImagen(Graphics^ lienzo)
{
	//carga la imagen en el puntero de tipo Bitmap
	Bitmap^ miSprite = gcnew Bitmap(gcnew System::String("Sprites/Mezcladora.png"));

	//define un rectangulo para cada imagen
	Rectangle cuadro = Rectangle(indiceColumnas * W, indiceFilas * H, W, H);

	//zoom
	Rectangle zoom = Rectangle(x, y, W, H);

	//dibuja la imagen
	lienzo->DrawImage(miSprite, zoom, cuadro, GraphicsUnit::Pixel);

}

inline void Mezcla::setX(int valor) {
	x = valor;
}
inline void Mezcla::setY(int valor) {
	y = valor;
}

inline int Mezcla::getX()
{
	return x;
}
inline int Mezcla::getY()
{
	return y;
}
inline int Mezcla::getW()
{
	return W;
}
inline int Mezcla::getH()
{
	return H;
}