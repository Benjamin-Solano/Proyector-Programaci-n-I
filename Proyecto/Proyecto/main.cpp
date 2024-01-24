#include "JugadorGenerico.h"

int main() {

	system("color 03");
	// Commentario 
	Mazo* mazo = new Mazo();
	mazo->Inicializar();
	mazo->barajar();

	Mano* mano = new Mano();
	JugadorGenerico* player = new JugadorGenerico("BENJAMIN", mano);
	mano->agregarCarta(mazo);
	mano->agregarCarta(mazo);

	mano->getPuntos();

	cout << player->toString() << endl;

	system("pause");
	return 0;
}