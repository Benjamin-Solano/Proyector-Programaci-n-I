#include "ListaJ.h"

ListaJ::ListaJ()
{
	head = nullptr;
}

ListaJ::~ListaJ()
{
	NodoJ* pex = head;
	while (pex != nullptr) {
		head = head->getNext();
		delete pex;
		pex = head;
	}
}

bool ListaJ::existe(string nick)
{
	NodoJ* pex = head;
	while (pex != nullptr) {
		if (pex->getJugador()->getNick() == nick) {
			return true;
		}
		pex = pex->getNext();
	}
	return false;
}

void ListaJ::ingresarPrimero(JugadorGenerico* player)
{
	head = new NodoJ(player, head);
}

void ListaJ::ingresarUltimo(JugadorGenerico* player)
{
	NodoJ* pex = head;
	NodoJ* nuevo = nullptr;
	//if (!existe(player->getNick())) {
	if (head == nullptr) {
		ingresarPrimero(player);
	}
	else {
		while (pex->getNext() != nullptr) {
			pex = pex->getNext();
		}
		nuevo = new NodoJ(player, nullptr);
		pex->setNext(nuevo);
	}
	//}


}

void ListaJ::eliminar(string nick)
{
	NodoJ* pex = head;
	NodoJ* victima = nullptr;

	if (existe(nick)) {
		if (pex->getJugador()->getNick() == nick) {
			victima = head;
			head = head->getNext();
			delete victima->getJugador();
			delete victima; return;
		}
		else {
			while (pex->getNext() != nullptr) {
				if (pex->getNext() == getNodo(nick)) {
					victima = pex->getNext();
					pex->setNext(victima->getNext());
					delete victima->getJugador();
					delete victima; return;
				}
				pex = pex->getNext();
			}
		}
	}

}

JugadorGenerico* ListaJ::getJugador(string nick)
{
	NodoJ* pex = head;
	while (pex != nullptr) {
		if (pex->getJugador()->getNick() == nick) {
			return pex->getJugador();
		}
		pex = pex->getNext();
	}
	return nullptr;
}

JugadorGenerico* ListaJ::getJugador(int lugar)
{
	int cont = 1;
	NodoJ* pex = head;
	if (lugar == 1) {
		return pex->getJugador();
	}
	else {
		while (pex != nullptr && cont < lugar) {
			pex = pex->getNext();
			cont++;
		}
		if (cont == lugar) {
			return pex->getJugador();
		}
		if (pex == nullptr) {
			return nullptr;
		}
	}
	return nullptr;
}

JugadorGenerico* ListaJ::getGanador()
{
	int cont = 0;
	NodoJ* pex = head;
	NodoJ* w = nullptr;
	while (pex != nullptr) {
		if (pex->getJugador()->getPuntos() > cont && pex->getJugador()->getPuntos() <= 21) {
			cont = pex->getJugador()->getPuntos();
			w = pex;
		}
		pex = pex->getNext();
	}
	return w->getJugador();

}

NodoJ* ListaJ::getNodo(string nick)
{
	NodoJ* pex = head;
	while (pex != nullptr) {
		if (pex->getJugador()->getNick() == nick) {
			return pex;
		}
		pex = pex->getNext();
	}
	return nullptr;
}

int ListaJ::cantidad()
{
	int cant = 0;
	NodoJ* pex = head;
	while (pex != nullptr) {
		cant++;
		pex = pex->getNext();
	}
	return cant;
}

string ListaJ::toString()
{
	stringstream s;
	NodoJ* pex = head;
	s << "--------------LISTA DE JUGADORES----------" << endl;
	s << endl;
	while (pex != nullptr) {
		s << pex->getJugador()->toString() << endl;
		pex = pex->getNext();
	}
	s << endl;
	s << "-----------------------------------------" << endl;
	return s.str();
}

void ListaJ::guardandoDatos() {
	//string rutaArchivo = "..//Jugadores.txt";
	NodoJ* exo = head;
	fstream salida("..//Jugadores.txt", ios::out);
	if (!salida.is_open())
		return;
	//salida.open(rutaArchivo.c_str());
	while (exo != nullptr) {
		exo->getJugador()->guardar(salida);
		exo = exo->getNext();
	}
	salida.close();
}

ListaJ* ListaJ::RecuperandoDatos(){
	fstream strm("..//Jugadores.txt", ios::in);
	if (strm.is_open()) {
		ListaJ* lista = new ListaJ();
		while (JugadorGenerico* jugador = JugadorGenerico::recuperar(strm)) {
			if (jugador == nullptr || jugador->getNick()=="")
				break;
			lista->ingresarUltimo(jugador);
		}
		return lista;
		strm.close();
	}
	return nullptr;
}
