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

	int Cantidad_de_Cartas();
	void agregarCarta(Mazo*);
	void ingresarCarta(Carta* c);
	void limpiar();
	int getPuntos();
	Carta* getCarta(int lugar);
	string toString();

	void guardar(fstream& strm) {
		for (int i = 0;i < can; i++) {
			cartas[i]->guardar(strm);
		}
	}

	static Mano* recuperar(fstream& strm) {
		Mano* mano = new Mano();
		while (Carta* carta = Carta::recuperar(strm)) {
			if (carta == nullptr)
				break;
			mano->ingresarCarta(carta);
		}
		return mano;
	}

};
