#pragma once
#include"Carta.h"
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
};