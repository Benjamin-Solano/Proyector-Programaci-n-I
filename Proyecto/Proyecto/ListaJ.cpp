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
