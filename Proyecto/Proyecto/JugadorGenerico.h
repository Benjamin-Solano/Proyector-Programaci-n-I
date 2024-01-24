#pragma once
#include"Mano.h"

class JugadorGenerico {
private:
	string nickname;
	Mano* mano;
public:
	JugadorGenerico();
	JugadorGenerico(string nick, Mano* mano);

	virtual ~JugadorGenerico();
	void pedirCarta(Mazo& mazo);
	bool sePaso();
	string getNick();
	string toString();
};