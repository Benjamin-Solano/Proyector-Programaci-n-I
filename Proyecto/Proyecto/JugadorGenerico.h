#pragma once
#include"Mano.h"

class JugadorGenerico {
private:
	string nickname;
	Mano* mano;
public:
	JugadorGenerico();
	JugadorGenerico(string nick, Mano* mano);

	~JugadorGenerico();
	Carta* pedirCarta(Mazo* mazo);
	bool sePaso();

	string toString();
};