#pragma once
#include "ListaJ.h"
#include <stdlib.h>
class Juego
{
private:
	ListaJ* listaJugadores;
	Mazo* mazo;

public:

	Juego();

	~Juego();

	JugadorGenerico* crearJugadorGenerico();

	JugadorGenerico* crearDealer();



};