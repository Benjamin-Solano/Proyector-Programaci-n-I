#include "Mazo.h"


//	===== CONSTRUCTOR ====== //
Mazo::Mazo(){
	tam = 52;
	can = 0;
	carta = new Carta * [tam];
}
// ======= DESTRUCTOR ========= //
Mazo::~Mazo(){
	for (int i = 0; i < can; i++) delete carta[i];
	delete[] carta;
}

// ====== METODO PARA ESTABLECER LOS VALORES DE CADA CARTA ===== //
void Mazo::Inicializar() {
	string NuevoValor[13] = { "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
	string NuevoPalo[4] = { "Espadas", "Corazones", "Diamantes", "Treboles" };
	int auxV = 0;
	int auxP = 0;
	for (int i = 0; i < tam; i++) {
		if (can < tam) {
			Carta* NuevaCarta = new Carta(NuevoValor[auxV++],NuevoPalo[auxP], false);
			carta[can++] = NuevaCarta;
			// REINICIAR LOS VALORES Y SUMAR +1 AL PALO, PARA EVITAR ERRORES CON ELEMENTOS DEL VECTOR
			if (auxV == 13) {
				auxV = 0;
				auxP++;
			}
		}
	}
}


// ========= METODOS DE SUGERENCIA POR PARTE DEL TUTOR ============= //
//                   PARA BARAJAR (ALEATORIO)                        //
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
	// ========== ANTIGUO METODO PARA BARAJAR HECHO POR NOSOTROS (SI FUNCIONA PROFE) ================ //
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

// ================ SOLICITA UNA PARTA AL MAZO Y LA RETIRA DEL MISMO ============== //
Carta* Mazo::tomarCarta() {
	if (can > 0) {
		// Toma la carta, se envia a la mano y se disminuye la cantidad de 
		// cartas disponibles para tomar en el mazo;
		return carta[--can];
	}
	else {
		cout << "Nos quedamos sin cartas!" << endl;
		return nullptr;
	}
}

// ============ MOSTRAR MAZO ========== //
// Se hizo para comprobar que todas las cartas
// estan correctamente inicializadas...
string Mazo::toString(){
	stringstream salida;
	for (int i = 0; i < can; i++) {
		salida << carta[i]->toString() << endl;
	}
	return salida.str();
}

// ============= GUARDAR MAZO =========== //
void Mazo::guardarMazo() {
	ofstream salida;
	string rutaArchivo = "..//Mazo.txt";
	salida.open(rutaArchivo.c_str());
	for (int i = 0; i < tam; i++) {
		carta[i]->guardar(salida);
	}
	salida.close();
}