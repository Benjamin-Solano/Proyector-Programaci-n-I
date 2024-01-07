#pragma once
#include"JugadorGenerico.h"

class Dealer : public JugadorGenerico {
private: 
	// Tampoco hay Juas juas
public:
	Dealer(string nickname, Mano* man);
	virtual ~Dealer();
	void volteaSegunda();

	
};