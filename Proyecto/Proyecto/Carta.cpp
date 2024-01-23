#include "Carta.h"

// ======= CONSTRUCTORES DE CARTA ========== //
Carta::Carta() { valor = "???"; palo = "???"; bocaAbajo = true; }
Carta::Carta(string val, string pal, bool bocaA) : valor(val), palo(pal), bocaAbajo(bocaA) {}

// ========= DESTRUCTOR =========== //
Carta::~Carta(){}

// =========== MUTADORES =========== //
void Carta::setValor(string val){}
void Carta::setPalo(string pal){}
void Carta::setBocaAbajo(bool boca){}

// ========== ACCESORES ============ //
string Carta::getValor() { return valor; }
string Carta::getPalo() { return palo; }

// ========== MOSTRAR CARTA =========== //
string Carta::toString(){
	stringstream salida;
	salida << "    ======= CARTA =======" << endl
		<< "    Valor   : " << valor << endl
		<< "    Palo    : " << palo << endl
		<< "    Estado  : "; if (bocaAbajo) {
							salida << "Boca Abajo" << endl;
							} else salida << "Boca Arriba" << endl;
	salida << "    =====================" << endl;
	return salida.str();
}