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


void JugadorGenerico::ingresar(Carta* carta)
{
	mano->ingresarCarta(carta);
}



void JugadorGenerico::guardar(ostream& salida) {
	salida << nickname << DELIMITA_CAMPO;
	salida << mano->Cantidad_de_Cartas() << DELIMITA_REGISTRO;
	for (int i = 0; i < mano->Cantidad_de_Cartas(); i++) {
		salida << mano->getCarta(i)->getValor() << DELIMITA_CAMPO;
		salida << mano->getCarta(i)->getPalo() << DELIMITA_CAMPO;
		salida << mano->getCarta(i)->getBocaAbajo() << DELIMITA_REGISTRO;
	}
	salida << endl;
}

JugadorGenerico* JugadorGenerico::recuperar(fstream& archivo){
	string nombreStr = "";
	string cantidadCartas = "";
	Mano* mano = new Mano();
	getline(archivo, nombreStr, DELIMITA_CAMPO);
	getline(archivo, cantidadCartas, DELIMITA_REGISTRO);
	while (Carta* carta = Carta::recuperar(archivo)) {
		if (carta == nullptr)
			break;
		mano->ingresarCarta(carta);
	}
	return new JugadorGenerico(nombreStr, mano);
}
