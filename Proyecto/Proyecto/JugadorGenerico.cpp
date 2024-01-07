#include"JugadorGenerico.h"

JugadorGenerico :: JugadorGenerico(){
	nickname = " ??? ";
	mano = nullptr;
}
JugadorGenerico :: JugadorGenerico(string nick, Mano* man) : nickname(nick), mano(man) {}

JugadorGenerico :: ~JugadorGenerico() { if (mano) delete mano; }



// ===== CONSULTAR CON EL PROFESOR ESTE METODO ===== //
Carta* JugadorGenerico :: pedirCarta(Mazo* mazo){ 
	
	Carta* nuevaCarta = nullptr;
	nuevaCarta = mazo->tomarCarta();
	return nuevaCarta;
	
}

bool JugadorGenerico :: sePaso(){
	return (mano->getPuntos() > 21);
}

string JugadorGenerico :: toString(){
	stringstream salida;
	salida << "====== JUGADOR " << nickname << " =======" << endl;
	salida << mano->toString() << endl;
	return salida.str();
}
