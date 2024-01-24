#include "JugadorGenerico.h"
#include "ListaJ.h"

int main() {

	system("color 03");
	// Commentario 
	/*Mazo* mazo = new Mazo();
	mazo->Inicializar();
	mazo->barajar();

	Mano* mano = new Mano();
	JugadorGenerico* player = new JugadorGenerico("BENJAMIN", mano);
	mano->agregarCarta(mazo);
	mano->agregarCarta(mazo);

	mano->getPuntos();

	cout << player->toString() << endl;*/

	Mazo* mazo = new Mazo();
	mazo->Inicializar();
	mazo->barajar();

	Mano* mano1 = new Mano();
	JugadorGenerico* p1 = new JugadorGenerico("Benjamin", mano1);
	mano1->agregarCarta(mazo);	mano1->agregarCarta(mazo);

	Mano* mano2 = new Mano();
	JugadorGenerico* p2 = new JugadorGenerico("Jonathan", mano2);
	mano2->agregarCarta(mazo);	mano2->agregarCarta(mazo);

	Mano* mano3 = new Mano();
	JugadorGenerico* p3 = new JugadorGenerico("Lalo", mano3);
	mano3->agregarCarta(mazo);	mano3->agregarCarta(mazo);

	Mano* mano4 = new Mano();
	JugadorGenerico* p4 = new JugadorGenerico("Pepe", mano4);
	mano4->agregarCarta(mazo);	mano4->agregarCarta(mazo);

	ListaJ* lista = new ListaJ();
	lista->ingresarUltimo(p1);


	lista->ingresarUltimo(p2);
	lista->ingresarUltimo(p3);
	lista->ingresarUltimo(p4);
	cout << lista->cantidad() << endl;
	cout << lista->toString() << endl;

	system("pause");
	return 0;
}