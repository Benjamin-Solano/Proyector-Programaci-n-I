#pragma once
#include "JugadorGenerico.h"

class Jugador : public JugadorGenerico {
private:
	//No hay juas juas
public:
	Jugador(string nickname, Mano* man);
	virtual ~Jugador();

	
};