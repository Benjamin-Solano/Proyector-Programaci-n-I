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
	void pedirCarta(Mazo* mazo);
	Carta* getCarta(int lugar);
	bool sePaso();
	int getPuntos();
	string getNick();
	string toString();
};