#pragma once
#include "JugadorGenerico.h"
#include "Dealer.h"
class NodoJ
{
private:
	JugadorGenerico* jugador;
	NodoJ* next;

public:
	NodoJ();
	NodoJ(JugadorGenerico* juador, NodoJ* next);
	~NodoJ();

	JugadorGenerico* getJugador();
	NodoJ* getNext();

	void setJugador(JugadorGenerico* jugador);
	void setNext(NodoJ* next);


};

