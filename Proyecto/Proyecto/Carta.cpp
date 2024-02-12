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
	salida << valor << DELIMITA_CAMPO;
	salida << palo << DELIMITA_CAMPO;
	salida << bocaAbajo << DELIMITA_REGISTRO;
}

Carta* Carta::recuperar(fstream& strm)
{
	string valorStr, paloStr, baStr = ""; // Creacion de variables string para almacenar datos procedentes del archivo
	bool bocaAbajo = false;
	getline(strm, valorStr, DELIMITA_CAMPO);
	getline(strm, paloStr, DELIMITA_CAMPO);
	getline(strm, baStr, DELIMITA_REGISTRO);
	// Validaciones del atributo BocaAbajo
	if (baStr == "")
		return nullptr;
	if (baStr == "1")
		bocaAbajo = true;
	// Creacion de objeto tipo Carta
	return new Carta(valorStr, paloStr, bocaAbajo);
}
