#ifndef PETICIO_H
#define PETICIO_H

#include "Hora.h"

#include <string>

using namespace std;

class Peticio { // Descripci�: una peticio
public:
	// CONSTRUCTORS
	Peticio();
	// Pre: --
	// Post: peticio inicialitzada
	Peticio(string nom, int unitats, Hora hora);
	// Pre: --
	// Post: peticio inicialitzada amb dades passades per funcio
	Peticio(const Peticio& p);
	// Pre: --
	// Post: peticio inicialitzada amb dades  de p

	// CONSULTORS
	void mostrar() const;
	// Pre: --
	// Post: mostra per pantalla informacio de la peticio

	// MODIFICADORS 
	bool llegir_peticio(const Hora& hora_inici);
	// Pre: --
	// Post: llegir per pantalla informacio de la peticio, retorna fals si l'hora de la peticio es anterior a l'hora d'inici, cert altrament
	bool processar(int& unitats_processades, int& unitats_disponibles, const int venda_maxima, const Hora& hora_inici);
	// Pre: --
	// Post: processar la petició de compravenda, retorna cert si s'ha de crear unaltre peticio

	// OPERADORS REDEFINITS 
	bool operator==(const Peticio& p) const;
	// Pre: --
	// Post: retorna cert si peticio actual �s igual a p
	bool operator>(const Peticio& p) const;
	// Pre: --
	// Post: retorna cert si peticio actual �s superior a p

private:
	string a_nom;
	int a_unitats;
	Hora a_hora;
};
#endif // PETICIO_H
