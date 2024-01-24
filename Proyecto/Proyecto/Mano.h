#include"Mazo.h"

class Mano {
private:
	Carta** cartas;
	int tam;
	int can;
public:
	Mano();
	Mano(const Mano& CopyMano);
	~Mano();

	void agregarCarta(Mazo*);
	void limpiar();
	int getPuntos();
	Carta* getCarta(int lugar);
	string toString();

};
