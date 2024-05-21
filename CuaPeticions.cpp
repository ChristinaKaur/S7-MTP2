#include <iostream>
#include "CuaPeticions.h"

#include "Peticio.h"
#include <string>


// CONSTRUCTORS I DESTRUCTOR
CuaPeticions::CuaPeticions() {
	// Pre: --; Post: cua buida
	// COST: O(1)
	a_primer = a_darrer = NULL;
}
CuaPeticions::CuaPeticions(const CuaPeticions& o) {
	// Pre: --; Post: aquesta cua �s c�pia de la cua o
	// COST: O(n)
	a_primer = a_darrer = NULL;
	copia(o); // crida a metode privat
}
CuaPeticions::~CuaPeticions() {
	// Pre: --; Post: memoria alliberada
	// COST: O(n)
	allibera(); // crida a metode privat
}

// CONSULTORS
bool CuaPeticions::buida() const {
	// Pre: -- ; Post: retorna cert si la cua es buida; fals en cas contrari
	// COST: O(1)
	return a_primer == NULL;
}
Peticio* CuaPeticions::primer() {
	// Pre: cua no buida; Post: retorna copia del primer de la cua
	// COST: O(1)
	return a_primer->p;
}

void CuaPeticions::mostrar() const {
	// Pre: cua no buida; 
	// Post: mostra per pantalla tot el contingut de la cua actual	
	if (!buida()) {
		cout << "PETICIONS PENDENTS:" << endl;
		Node *actual = a_primer;
		while (actual != NULL) {
			actual->p->mostrar();
			actual = actual->seg;
		}
	}
	else cout << "NO HI HA PETICIONS PENDENTS" << endl;
}

// MODIFICADORS
void CuaPeticions::encua(Peticio* p) {
	// Pre: --; Post: ha afegit p al final de la cua
	// COST: O(1)
	Node* nou = new Node;
	nou->p = new Peticio(*p);;
	nou->seg = NULL;
	if (buida()) {
		a_primer = nou;
		a_darrer = nou;
	}
	else {
		a_darrer->seg = nou; 
		a_darrer = nou;
	}
}

void CuaPeticions::desencua() {
	// Pre: cua no buida; Post: ha eliminat el primer de la cua
	// COST: O(1)
	Node* aux = a_primer;
	if (a_primer == a_darrer) // nom�s hi ha un element
		a_primer = a_darrer = NULL;
	else a_primer = a_primer->seg;
	delete aux;
}

// M�TODES PRIVATS
void CuaPeticions::copia(const CuaPeticions& o) {
	// Pre: cua buida; Post: aquesta cua es copia de o
	// COST: O(n)
	Node* p = o.a_primer;
	while (p != NULL) { // recorrem cua o
		encua(p->p); 
		p = p->seg;
	}
}
void CuaPeticions::allibera() {
	// Pre: --; Post: cua buida
	// COST: O(n)
	while (a_primer != NULL) { //!buida()
		Node* aux = a_primer;
		a_primer = a_primer->seg;
		delete aux;
	}
	a_darrer = NULL;
}

// OPERADOR ASSIGNACIO
CuaPeticions& CuaPeticions::operator=(const CuaPeticions& o) {
	// Pre: -- ; Post: aquesta cua es copia de o
	// COST: O(n)
	if (this != &o) {
		allibera();
		copia(o);
	}
	return *this;
}