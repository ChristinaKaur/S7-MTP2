#include <iostream>
#include "Hora.h"

using namespace std;

// CONSTRUCTORS
Hora::Hora() {
	// Pre: --
	// Post: Hora inicialitzat
	a_hora = 0;
	a_minut = 0;
}

Hora::Hora(int hora) {
	// Pre: --
	// Post: Hora inicialitzat amb dades passades per funcio
	if (!es_valida(hora, 0)) {
		a_hora = hora / 100;
		a_minut = hora % 100;
	}
}

// CONSULTORS
void Hora::mostrar() const {
	// Pre: --
	// Post: mostrar per pantalla l'hora actual
	cout << "[";
	if (a_hora / 10 == 0) cout << 0;
	cout << a_hora << ":";
	if (a_minut / 10 == 0) cout << 0;
	cout << a_minut << "]";
}

bool Hora::es_valida(int hora, int i) const {
	// Pre: --
	// Post: retorna cert si hora actual es valida si i es 1, si i es 0 retorna cert si hora es valida
	bool correcte = false;
	if (i == 0) {
		int Hora = hora / 100;
		int Minut = hora % 100;
		correcte = (Hora >= 0 and Hora < 24 and Minut < 60 and Minut >= 0);
	}
	else if (i == 1) {
		correcte = (a_hora >= 0 and a_hora < 24 and a_minut < 60 and a_minut >= 0);
	}
	return correcte;
}

// MODIFICADORS
void Hora::llegir_hora() {
	// Pre: --
	// Post: llegir hora per teclat
	int hora;
	cin >> hora;
	while (!es_valida(hora, 0)) {
		cin >> hora;
	}
	a_hora = hora / 100;
	a_minut = hora % 100;
}

void Hora::supar_hores() {
	// Pre: --
	// Post: sumar 2 hores a hora actual
	if (a_hora > 21) a_hora = a_hora + 2 - 24;
	else a_hora += 2;
}

// OPERADORS REDEFINITS 
bool Hora::operator==(const Hora& h) const {
	// Pre: --
	// Post: retorna cert si hora actual és igual a h
	return a_hora == h.a_hora and a_minut == h.a_minut;
}

bool Hora::operator>(const Hora& h) const {
	// Pre: --
	// Post: retorna cert si hora actual és major a h
	return a_hora > h.a_hora or (a_hora == h.a_hora and a_minut > h.a_minut);
}