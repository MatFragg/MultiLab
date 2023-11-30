#pragma once
#include "iostream"
#include "string.h"
using namespace System::Drawing;
using namespace std;

class Elemento3 :public Elementos
{
public:
	Elemento3(int px, int py);
	~Elemento3();
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

inline Elemento3::Elemento3(int px, int py) : Elementos(px, py)
{
	x = px;
	y = py;
	dx = 0;
	dy = 0;
}

inline Elemento3::~Elemento3()
{

}

inline void Elemento3::CargarImagen(string pnombre_archivo)
{
	Bitmap^ SpriteE1 = gcnew Bitmap(gcnew System::String("Sprites/Elementos.png"));

	//ahora.. hallamos el W, H de cada imagen
	W = SpriteE1->Width / 5;
	H = SpriteE1->Height / 4;

	delete SpriteE1;
}
inline void Elemento3::MoverImagen(Graphics^ lienzo)
{
	if (x > 1 || x < 800)
	{
		indiceFilas = indiceColumnas = 2;
	}

	x = x + dx;
	y = y + dy;

	MostrarImagen(lienzo);
}
inline void Elemento3::MostrarImagen(Graphics^ lienzo)
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

inline void Elemento3::setX(int valor) {
	x = valor;
}
inline void Elemento3::setY(int valor) {
	y = valor;
}

inline int Elemento3::getX()
{
	return x;
}
inline int Elemento3::getY()
{
	return y;
}
inline int Elemento3::getW()
{
	return W;
}
inline int Elemento3::getH()
{
	return H;
}