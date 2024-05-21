#include <iostream>
#include <istream>
#include "Peticio.h"

#include "Hora.h"

using namespace std;

// CONSTRUCTORS
Peticio::Peticio() {
	// Pre: --
	// Post: peticio inicialitzada
	a_nom = "";
	a_unitats = 1;
	a_hora = Hora();
}

Peticio::Peticio(string nom, int unitats, Hora hora) {
	// Pre: --
	// Post: peticio inicialitzada amb dades passades per funció
	a_nom = nom;
	a_unitats = unitats;
	a_hora = hora;
}

Peticio::Peticio(const Peticio& p) {
	// Pre: --
	// Post: peticio inicialitzada amb dades  de p
	a_nom = p.a_nom;
	a_unitats = p.a_unitats;
	a_hora = p.a_hora;
}

// CONSULTORS
void Peticio::mostrar() const {
	// Pre: --
	// Post: mostra per pantalla informacio de la peticio
	a_hora.mostrar();
	cout << ": " << a_nom << " -> " << a_unitats << " UNITATS" << endl;
}

// MODIFICADORS 
bool Peticio::llegir_peticio(const Hora& hora_inici) {
	// Pre: --
	// Post: llegir per pantalla informacio de la peticio, retorna fals si l'hora de la peticio es anterior a l'hora d'inici, cert altrament
	cout << "NOM CLIENT:" << endl;
	cin.ignore();
	getline(cin, a_nom);
	cout << "NOMBRE D'UNITATS:" << endl;
	cin >> a_unitats;
	while (a_unitats == 0) {
		cin >> a_unitats;
	}
	cout << "HORA PETICIO:" << endl;
	a_hora.llegir_hora();

	bool correcta = true;
	if (hora_inici > a_hora) correcta = false;
	return correcta;
}

bool Peticio::processar(int& unitats_processades, int& unitats_disponibles, const int venda_maxima, const Hora& hora_inici) {
	// Pre: --
	// Post: processar la petició de compravenda, retorna cert si s'ha de crear unaltre peticio
	bool crear_peticio = false;
	if (a_unitats > 0 and a_unitats <= 10) { //pos inferior o igual a 10
		int unitats_inici = unitats_disponibles;
		if (a_unitats <= unitats_disponibles) {
			unitats_disponibles -= a_unitats;
			unitats_processades = unitats_inici - unitats_disponibles;
		}
		else {
			unitats_processades = unitats_disponibles;
			unitats_disponibles = 0;
		}
	}
	else if (a_unitats < 0) { //negatiu
		if (a_unitats >= (venda_maxima * -1)) {
			unitats_processades = a_unitats;
			unitats_disponibles += (a_unitats*-1);
		}
		else {
			unitats_processades = (venda_maxima * -1);
			unitats_disponibles += venda_maxima;
			a_hora.supar_hores();
			a_unitats += venda_maxima;
			if (!(hora_inici > a_hora)) crear_peticio = true;
		}
	}
	else { //supera el maxim
		cout << "LA PETICIO SUPERA EL MAXIM." << endl;
		cout << "S'ANUL.LA LA PETICIO." << endl;
	}
	return crear_peticio;
}

// OPERADORS REDEFINITS 
bool Peticio::operator==(const Peticio& p) const {
	// Pre: --
	// Post: retorna cert si peticio actual és igual a p
	return a_nom == p.a_nom and a_unitats == p.a_unitats and a_hora == p.a_hora;
}

bool Peticio::operator>(const Peticio& p) const {
	// Pre: --
	// Post: retorna cert si peticio actual és superior a p
	return a_nom > p.a_nom or (a_nom == p.a_nom and a_unitats > p.a_unitats) or (a_nom == p.a_nom and a_unitats == p.a_unitats and a_hora > p.a_hora);
}
