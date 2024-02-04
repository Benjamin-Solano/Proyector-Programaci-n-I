#pragma once
#include<iostream>
#include<sstream>
using namespace std;

#define DELIMITADOR_CAMPO '\t'
#define DELIMITADOR_REGISTRO '\n'

class Carta {
private:
	string valor;
	string palo;
	bool bocaAbajo;
public:
	Carta();
	Carta(string, string, bool);
	~Carta();

	void setValor(string val);
	void setPalo(string pal);
	void setBocaAbajo(bool boca);

	string getValor();
	string getPalo();
	
	virtual void guardar(ostream& salida);

	string toString();
};