#pragma once
#include"Mano.h"
#include<fstream>

#define DELIMITA_CAMPO ','
#define DELIMITA_REGISTRO '\n'

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

	void ingresar(Carta* carta);
	virtual void guardar(ostream& salida);
	static JugadorGenerico* recuperar(fstream& strm);

};