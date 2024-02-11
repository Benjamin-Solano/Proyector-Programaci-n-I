#include "Juego.h"

Juego::Juego() {
	//cosas
	mazo = new Mazo();
	mazo->Inicializar(); mazo->barajar();

	listaJugadores = new ListaJ();
	char op = 'y';
	int lugar = 1;
	int salir = 0;
	int primero = 0;
	int ptsDealer = 0;
	int comodin = 0;

	//llenar la lista
	do {
		cout << "Desea agregar un jugador?: ( 'y' || 'n' ) o Recuperar Partida Anterior?: ( 'r' )" << endl;cin >> op;
		if (op == 'y' || op == 'Y') {
			system("cls");
			listaJugadores->ingresarUltimo(crearJugadorGenerico());
		}
		else if (op == 'r' || op == 'R') {
			delete listaJugadores;
			listaJugadores = ListaJ().RecuperandoDatos();
		}
		system("cls");
	} while (op == 'y' || op == 'Y');


	//creacion de dealer
	JugadorGenerico* dealer = crearDealer();

	//dar dos cartas a los jugadores
	int numDeJugadores = listaJugadores->cantidad();
	for (int i = 1; i <= numDeJugadores; i++) {
		listaJugadores->getJugador(i)->pedirCarta(mazo);
		listaJugadores->getJugador(i)->pedirCarta(mazo);
	}

	//dar dos cartas al dealer
	dealer->pedirCarta(mazo);
	dealer->pedirCarta(mazo);



	//opciones por turno
	do {
		cout << listaJugadores->getJugador(lugar)->toString() << endl;
		cout << "(D)eme carta - (P)asar - (G)uardar Partida - (S)alir y ver resultados" << endl; cin >> op;
		switch (op)
		{
		case 'd':
			if (!listaJugadores->getJugador(lugar)->sePaso())
				listaJugadores->getJugador(lugar)->pedirCarta(mazo);
			break;

		case 'p':
			break;
		case 'g':
			listaJugadores->guardandoDatos();
			mazo->guardarMazo();
			break;
		case 's':
			salir = -1;
			break;

		}

		system("cls");
		cout << listaJugadores->getJugador(lugar)->toString() << endl;
		system("pause");
		system("cls");
		//mostrar la primera carta del dealer en la primera ronda
		if (comodin == listaJugadores->cantidad() - 1) {
			/*dealer->pedirCarta(mazo);
			dealer->pedirCarta(mazo);*/
			cout << "la primera carta del dealer es: " << endl;
			cout << dealer->getCarta(0)->toString() << endl;
			system("pause");
			system("cls");
			ptsDealer = dealer->getPuntos();
		}
		comodin++;

		//verificaciones y turnos
		if (listaJugadores->getJugador(lugar)->getPuntos() == 21) {
			primero = lugar;
		}
		lugar++;
		if (lugar > listaJugadores->cantidad()) {
			lugar = 1;
		}

		system("cls");

	} while (lugar > 0 && salir == 0);


	ptsDealer = dealer->getPuntos();

	//resultados (comentar para entrega final, se deja por ahora para ver bien como va todo)
	/*if (primero != 0) {
		cout << "El primero jugador en alcanzar 21 fue: " << listaJugadores->getJugador(primero)->getNick() << endl;
		return;
	}
	if (listaJugadores->getGanador() != nullptr) {
		cout << " El jugador con puntaje mas cercano a 21 es: " << listaJugadores->getGanador()->getNick() << endl;
	}
	

	if (ptsDealer == 21)
		cout << "GANO EL DEALER POR TENER 21 PUNTOS" << endl;


	if (listaJugadores->getGanador()->getPuntos() > ptsDealer) {
		cout << "EL GANADOR ES: " << listaJugadores->getGanador()->getNick() << endl;
		cout << "Con una puntuacion de: " << listaJugadores->getGanador()->getPuntos() << endl;
		cout << "(el dealer obtuvo una puntuacion de: " << ptsDealer << " )" << endl;
	}

	else
		cout << "GANO EL DEALER CON " << ptsDealer << " puntos!" << endl;*/

	//RESULTADOS
	cout << listaJugadores->toString() << endl;
	cout << dealer->toString() << endl;
}

Juego::~Juego() {
	delete listaJugadores;
	delete mazo;
}

JugadorGenerico* Juego::crearJugadorGenerico() {
	string nombre = "";
	do {
		cout << "ingrese un nuevo nombre para jugador: " << endl; cin >> nombre;
	} while (listaJugadores->existe(nombre));

	Mano* m = new Mano();
	JugadorGenerico* player = new JugadorGenerico(nombre, m);
	return player;
}

JugadorGenerico* Juego::crearDealer() {

	Mano* m = new Mano();
	JugadorGenerico* dealer = new Dealer("DEALER", m);

	return dealer;
}
