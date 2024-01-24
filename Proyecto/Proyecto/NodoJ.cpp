#include "NodoJ.h"

NodoJ::NodoJ()
{
	jugador = nullptr;
	next = nullptr;
}

NodoJ::NodoJ(JugadorGenerico* jugador, NodoJ* next)
{
	this->jugador = jugador;
	this->next = next;
}

NodoJ::~NodoJ()
{
	delete jugador;
}

JugadorGenerico* NodoJ::getJugador()
{
	return jugador;
}

NodoJ* NodoJ::getNext()
{
	return next;
}

void NodoJ::setJugador(JugadorGenerico* jugador)
{
	this->jugador = jugador;
}

void NodoJ::setNext(NodoJ* next)
{
	this->next = next;
}
