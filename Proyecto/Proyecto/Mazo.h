/*

PROYECTO PROGRAMACION 1
ESTUDIANTES:
BENJAMIN SOLANO
JONATHAN AVALOS

*/

#pragma once
#include"Carta.h"
#include <fstream>
#include <random> 
class Mazo {
private:
	Carta** carta;
	int tam;
	int can;
public:
	Mazo();
	~Mazo();
	void Inicializar();
	void intercambiar(int,int);
	void barajar();
	Carta* tomarCarta();
	string toString();
	void ingresar(Carta* c);

	void guardarMazo();
	void recuperar();

};