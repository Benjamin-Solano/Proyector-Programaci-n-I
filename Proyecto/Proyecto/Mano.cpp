#include"Mano.h"
#include <string> // Libreria para la implementacion del stoi...


Mano::Mano(){
	tam = 3;
	can = 0;
	cartas = new Carta * [tam];
}
Mano::Mano(const Mano& CopyMano) : tam(CopyMano.tam), can(CopyMano.can) {
    cartas = new Carta * [tam];
    for (int i = 0; i < tam; ++i) {
        cartas[i] = new Carta(*(CopyMano.cartas[i]));
    }
}

Mano::~Mano(){
	limpiar();
}

void Mano::agregarCarta(Mazo* mazo){
	if (can < tam) {
		cartas[can++] = mazo->tomarCarta();
	}
}

void Mano::limpiar() {
    for (int i = 0; i < can; ++i) {
        delete cartas[i];
        cartas[i] = nullptr;
    }
    delete[] cartas;
    cartas = nullptr;
    tam = 0;
    can = 0;
}


int Mano::getPuntos(){
        int puntos = 0;
        int as = 0;
        for (int i = 0; i < can; ++i) {
            string valor = cartas[i]->getValor();
            if (valor == "A") {  // As
                puntos += 11;
                as++;
            }
            else if (valor == "10" || valor == "J" || valor == "Q" || valor == "K")  // 10, J, Q, K
                puntos += 10;
            else puntos += stoi(valor);  // Se convierte el string a entero (string to Integer)
        }
        // Ajuste de los ases
        while (puntos > 21 && as > 0) {
            puntos -= 10;
            as--;
        }
        return puntos;
}

string Mano::toString() {
    stringstream s;
    s << "======= CARTAS EN MANO ========" << endl << endl;
    if (can > 0) {
        for (int i = 0; i < can; i++)
            s << cartas[i]->toString() << endl;
    }
    else {
        s << "Mano vacia..." << endl;
    }
    s << "         PUNTOS: " << this->getPuntos() << endl;
    s << "===============================" << endl << endl;
    return s.str();
}
