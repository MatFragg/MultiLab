#pragma once
#include "iostream"
#include "string.h"
using namespace System::Drawing;
using namespace std;

class Elemento5 :public Elementos
{
public:
	Elemento5(int px, int py);
	~Elemento5();
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

inline Elemento5::Elemento5(int px, int py) : Elementos(px, py)
{
	x = px;
	y = py;
	dx = 0;
	dy = 0;
}

inline Elemento5::~Elemento5()
{

}

inline void Elemento5::CargarImagen(string pnombre_archivo)
{
	Bitmap^ SpriteE1 = gcnew Bitmap(gcnew System::String("Sprites/Elementos.png"));

	//ahora.. hallamos el W, H de cada imagen
	W = SpriteE1->Width / 5;
	H = SpriteE1->Height /4;

	delete SpriteE1;
}
inline void Elemento5::MoverImagen(Graphics^ lienzo)
{
	if (x > 1 || x < 800)
	{
		indiceFilas = 0;
		indiceColumnas=4;
	}

	x = x + dx;
	y = y + dy;

	MostrarImagen(lienzo);
}
inline void Elemento5::MostrarImagen(Graphics^ lienzo)
{
	//carga la imagen en el puntero de tipo Bitmap
	Bitmap^ miSprite = gcnew Bitmap(gcnew System::String("Sprites/Elementos.png"));

	//define un rectangulo para cada imagen
	Rectangle cuadro = Rectangle(indiceColumnas * W, indiceFilas * H, W, H);

	//zoom
	Rectangle zoom = Rectangle(x, y, W, H);

	//dibuja la imagen
	lienzo->DrawImage(miSprite, zoom, cuadro, GraphicsUnit::Pixel);

}

inline void Elemento5::setX(int valor) {
	x = valor;
}
inline void Elemento5::setY(int valor) {
	y = valor;
}

inline int Elemento5::getX()
{
	return x;
}
inline int Elemento5::getY()
{
	return y;
}
inline int Elemento5::getW()
{
	return W;
}
inline int Elemento5::getH()
{
	return H;
}