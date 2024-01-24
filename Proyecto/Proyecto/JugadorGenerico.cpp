#include"JugadorGenerico.h"

// ======== CONSTRUCTORES ======== //
JugadorGenerico :: JugadorGenerico(){
	nickname = " ??? ";
	mano = nullptr;
}
JugadorGenerico :: JugadorGenerico(string nick, Mano* man) : nickname(nick), mano(man) {}

// ======== DESTRUCTOR ========= // 
JugadorGenerico :: ~JugadorGenerico() { if (mano) delete mano; }



// ===== MODIFICACION DEL METODO ===== //
// Para que esto funcione, se envia el mazo como referencia
// la mano se encarga de tomar la carta y guardarla con el 
// resto...
void JugadorGenerico :: pedirCarta(Mazo& mazo){
	 mano->agregarCarta(&mazo);
}

// VALIDACION POR SI ALGUN JUGADOR SE PASA DE 21 //
bool JugadorGenerico :: sePaso(){
	return (mano->getPuntos() > 21);
}

string JugadorGenerico::getNick()
{
	return nickname;
}

// ======== MOSTRAR JUGADOR ============ //
string JugadorGenerico :: toString(){
	stringstream salida;
	salida << "====== JUGADOR " << nickname << " =======" << endl;
	salida << mano->toString() << endl;
	return salida.str();
}
