#include "Carta.h"

// ======= CONSTRUCTORES DE CARTA ========== //
Carta::Carta() { valor = "???"; palo = "???"; bocaAbajo = true; }
Carta::Carta(string val, string pal, bool bocaA) : valor(val), palo(pal), bocaAbajo(bocaA) {}

Carta::Carta(Carta* car)
{
	valor = car->getValor();
	palo = car->getPalo();
	bocaAbajo = car->getBocaAbajo();
}
// ========= DESTRUCTOR =========== //
Carta::~Carta(){}

// =========== MUTADORES =========== //
void Carta::setValor(string val){}
void Carta::setPalo(string pal){}
void Carta::setBocaAbajo(bool boca){}

// ========== ACCESORES ============ //
string Carta::getValor() { return valor; }
string Carta::getPalo() { return palo; }

bool Carta::getBocaAbajo()
{
	return bocaAbajo;
}

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

// ============ GUARDAR MAZO EN SSD =========== //
void Carta::guardar(ostream& salida) {
	salida << valor << DELIMITADOR_CAMPO;
	salida << palo << DELIMITADOR_CAMPO;
	salida << bocaAbajo << DELIMITADOR_REGISTRO;
}

Carta* Carta::recuperar(fstream& strm)
{
	string valorStr, paloStr, baStr = "";
	bool bocaAbajo = false;
	getline(strm, valorStr, DELIMITADOR_CAMPO);
	getline(strm, paloStr, DELIMITADOR_CAMPO);
	getline(strm, baStr, DELIMITADOR_REGISTRO);
	if (baStr == "")
		return nullptr;
	if (baStr == "1")
		bocaAbajo = true;
	return new Carta(valorStr, paloStr, bocaAbajo);

}
