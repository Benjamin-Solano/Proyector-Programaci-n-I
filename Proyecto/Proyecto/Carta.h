#pragma once
#include<iostream>
#include<sstream>
using namespace std;

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
	
	string toString();
};