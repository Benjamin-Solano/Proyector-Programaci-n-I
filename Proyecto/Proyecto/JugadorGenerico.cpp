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

// RETORNA UNA CARTA EN POSICION ESPECIFICA
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


// GUARDAR DATOS DEL JUGADOR...
void JugadorGenerico::guardar(fstream& salida) {
	salida << nickname << DELIMITA_CAMPO;
	salida << cantidadCartasMano() << DELIMITA_REGISTRO;
	mano->guardar(salida);
}

// RECUPERAR DATOS DEL JUGADOR
JugadorGenerico* JugadorGenerico::recuperar(fstream& archivo){
	// VARIABLES AUXILIARES PARA ALMACENAR DATOS PROCEDENTES DEL ARCHIVO...
	string nombreStr = "";
	string cantidadCartas = ""; 
	Mano* mano;
	// LECTURA DEL ARCHIVO
	getline(archivo, nombreStr, DELIMITA_CAMPO);
	getline(archivo, cantidadCartas, DELIMITA_REGISTRO);
	// VALIDACIONES...
	if (cantidadCartas == "")
		return nullptr;
	int cantidad = stoi(cantidadCartas);

	mano = Mano::recuperar(archivo, cantidad);
	if (mano == nullptr)
		return nullptr;
	return new JugadorGenerico(nombreStr, mano);
}
