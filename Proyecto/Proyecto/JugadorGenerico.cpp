#include"JugadorGenerico.h"

JugadorGenerico::JugadorGenerico() {
	nickname = " ??? ";
	mano = nullptr;
}
JugadorGenerico::JugadorGenerico(string nick, Mano* man) : nickname(nick), mano(man) {}

JugadorGenerico :: ~JugadorGenerico() { if (mano) delete mano; }



// ===== CONSULTAR CON EL PROFESOR ESTE METODO ===== //
void JugadorGenerico::pedirCarta(Mazo* mazo) {

	mano->agregarCarta(mazo);

}

Carta* JugadorGenerico::getCarta(int lugar)
{
	return mano->getCarta(lugar);
}

bool JugadorGenerico::sePaso() {
	return (mano->getPuntos() > 21);
}

int JugadorGenerico::getPuntos()
{
	return mano->getPuntos();
}

string JugadorGenerico::getNick()
{
	return nickname;
}

string JugadorGenerico::toString() {
	stringstream salida;
	salida << "====== JUGADOR " << nickname << " =======" << endl;
	salida << mano->toString() << endl;
	return salida.str();
}
