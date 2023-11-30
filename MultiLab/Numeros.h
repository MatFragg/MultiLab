#pragma once
#include "iostream"
#include "math.h"
#include "ctime"
using namespace std;

class Numeros
{
public:
	Numeros();
	~Numeros();
	int  SetNumero1();
	int  SetNumero2();
	int  SetNumero3();
	int  SetNumero4();
	int  SetNumero5();
	int  SetNumero6();
	int  SetNumero7();
	int  SetNumero8();
	int  SetNumero9();
	int  SetNumero10();
	int Sumar();
	float Restar();
	float Restar2();
	float Multiplicar();
	float Multiplicar2();

	float OperacionL1();
	float OperacionL2();


private:
	int numero1, numero2;
	int numero3, numero4;
	int numero5, numero6;
	int numero7, numero8;
	int numero9, numero10;
	float suma, resta, multi;
	float operacion1, operacion2;

};

inline Numeros::Numeros()
{
	srand(time(NULL));
}

inline Numeros::~Numeros()
{
}

inline int Numeros::SetNumero1()
{
	numero1 = rand() % 20;
	return numero1;
}
inline int Numeros::SetNumero2()
{
	numero2 = rand() % 10;
	return numero2;
}

inline int Numeros::SetNumero3()
{
	numero3 = rand() % 20;
	return numero3;
}
inline int Numeros::SetNumero4()
{
	numero4 = rand() % 10;
	return numero4;
}

inline int Numeros::SetNumero5()
{
	numero5 = rand() % 20;
	return numero5;
}
inline int Numeros::SetNumero6()
{
	numero6 = rand() % 10;
	return numero6;
}
inline int Numeros::SetNumero7()
{
	numero7 = rand() % 20;
	return numero7;
}
inline int Numeros::SetNumero8()
{
	numero8 = rand() % 10;
	return numero8;
}
inline int Numeros::SetNumero9()
{
	numero9 = rand() % 20;
	return numero9;
}
inline int Numeros::SetNumero10()
{
	numero10 = rand() % 10;
	return numero10;
}


inline int Numeros::Sumar()
{
	return suma = numero1+numero2;
}
inline float Numeros::Restar()
{
	return resta = numero3 - numero4;
}
inline float Numeros::Restar2()
{
	return resta = numero5 - numero6;
}

inline float Numeros::Multiplicar()
{
	return multi = numero7*numero8;
}
inline float Numeros::Multiplicar2()
{
	return multi = numero9 * numero10;
}

inline float Numeros::OperacionL1()
{
	return operacion1 = pow(numero1, 2) - pow(numero3, 2) + (numero4 + numero2);
}
inline float Numeros::OperacionL2()
{
	return operacion2 = pow(numero6, 2) + pow(numero10, 2) - (numero8);
}