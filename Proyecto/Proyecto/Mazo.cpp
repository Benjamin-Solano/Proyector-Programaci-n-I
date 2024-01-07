#include "Mazo.h"



Mazo::Mazo(){
	tam = 52;
	can = 0;
	carta = new Carta * [tam];
}
Mazo::~Mazo(){
	for (int i = 0; i < can; i++) delete carta[i];
	delete[] carta;
}
void Mazo::Inicializar() {
	string NuevoValor[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	string NuevoPalo[4] = { "Espadas", "Corazones", "Diamantes", "Treboles" };
	int auxV = 0;
	int auxP = 0;
	for (int i = 0; i < tam; i++) {
		if (can < tam) {
			Carta* NuevaCarta = new Carta(NuevoValor[auxV++],NuevoPalo[auxP], false);
			carta[can++] = NuevaCarta;
			if (auxV == 13) {
				auxV = 0;
				auxP++;
			}
		}
	}
}

void Mazo:: intercambiar(int pos1, int pos2) {
	Carta* auxCarta = carta[pos1];
	carta[pos1] = carta[pos2];
	carta[pos2] = auxCarta;
}

int generarNumeroAleatorio(int limiteInferior, int limiteSuperior) { // Ambos inclusive.
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distribucion(limiteInferior, limiteSuperior);
	return distribucion(gen);
}

void Mazo::barajar(){
	// ========== ANTIGUO METODO DE (DES)ORDENAMIENTO ================ //
	//Carta* vecAuxiliar1[26];
	//Carta* vecAuxiliar2[26];	
	//// Se repite la fase de barajar 4 veces....
	//for (int i = 0; i < 4; i++) { 
	//	// Se parte en 2 el vector inicial y cada mitad se coloca en un vector auxiliar...
	//	for (int i = 0; i < 26; i++) vecAuxiliar1[i] = carta[i];
	//	for (int i = 0; i < 26; i++) vecAuxiliar2[i] = carta[i + 26];
	//	// Colocar intercaladamente cada carta dentro del vector inicial...
	//	int pos1 = 0;
	//	for (int i = 0; i < 26; i++) {
	//		carta[pos1] = vecAuxiliar2[i];
	//		pos1 += 2;
	//	}
	//	int pos2 = 0;
	//	for (int i = 1; i < 52; i += 2) carta[i] = vecAuxiliar1[pos2++];
	//}

	for (int i = 0; i < can; i++) {
		int posAleatoria = generarNumeroAleatorio(0,can-1);
		intercambiar(i, posAleatoria);
	}


}
Carta* Mazo::tomarCarta() {
	if (can > 0) {
		return carta[--can];
	}
	else {
		cout << "Nos quedamos sin cartas!" << endl;
		return nullptr;
	}
}

string Mazo::toString(){
	stringstream salida;
	for (int i = 0; i < can; i++) {
		salida << carta[i]->toString() << endl;
	}
	return salida.str();
}