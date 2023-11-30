#pragma once
#include "iostream"
#include "string.h"
using namespace System::Drawing;
using namespace std;

class Elementos
{
public:
	Elementos(int px, int py);
	~Elementos();
	virtual void CargarImagen(string pnombre_archivo);
	virtual void MoverImagen(Graphics^ lienzo);
	virtual void MostrarImagen(Graphics^ lienzo);

	virtual void setX();
	virtual void setY();

	virtual int getX();
	virtual int getY();
	virtual int getW();
	virtual int getH();


protected:

	int x, y, dx, dy;
	int W, H;
	int width, height;
	int indice_filas, indice_columnas;

};

inline Elementos::Elementos(int px, int py)
{
	x = px;
	y = py;

}

inline Elementos::~Elementos()
{

}

inline void Elementos::CargarImagen(string pnombre_archivo)
{

}
inline void Elementos::MoverImagen(Graphics^ lienzo)
{

}
inline void Elementos::MostrarImagen(Graphics^ lienzo)
{

}

inline void Elementos::setX()
{

}
inline void Elementos::setY()
{

}

inline int Elementos::getX()
{
	return x;
}
inline int Elementos::getY()
{
	return y;
}
inline int Elementos::getW()
{
	return W;
}
inline int Elementos::getH()
{
	return H;
}