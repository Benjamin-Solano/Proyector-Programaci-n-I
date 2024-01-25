#pragma once
#include "NodoJ.h"
class ListaJ
{
private:
	NodoJ* head;

public:
	ListaJ();
	~ListaJ();

	bool existe(string nick);
	void ingresarPrimero(JugadorGenerico* player);
	void ingresarUltimo(JugadorGenerico* player);
	void eliminar(string nick);

	JugadorGenerico* getJugador(string nick);
	JugadorGenerico* getJugador(int lugar);
	JugadorGenerico* getGanador();
	NodoJ* getNodo(string nick);
	int cantidad();

	string toString();
	//string imprimir(); //imprime todos menos casa


};
