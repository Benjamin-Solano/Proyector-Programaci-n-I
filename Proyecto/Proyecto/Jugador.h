/*

PROYECTO PROGRAMACION 1
ESTUDIANTES:
BENJAMIN SOLANO
JONATHAN AVALOS

*/

#pragma once
#include "JugadorGenerico.h"

class Jugador : public JugadorGenerico {
private:
	//No hay juas juas
public:
	Jugador(string nickname, Mano* man);
	virtual ~Jugador();
	
};