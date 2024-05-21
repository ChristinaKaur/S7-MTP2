#ifndef CUAPETICIONS_H
#define CUAPETICIONS_H

#include <string>
#include "Peticio.h"

class CuaPeticions { // Descripci�: una cua de peticions
public:
	// CONSTRUCTORS I DESTRUCTOR 
	CuaPeticions();
	// Pre: --; Post: cua buida
	CuaPeticions(const CuaPeticions& o); // const. de c�pia
	// Pre: --; Post: aquesta cua es copia de la Cua o
	// Pre: --; Post: mem�ria alliberada
	~CuaPeticions();
	// Pre: --; Post: mem�ria alliberada
	// COST: O(n)

	// CONSULTORS 
	bool buida() const;
	// Pre: -- ; Post: retorna cert si la cua �s buida; fals en c.c.
	Peticio* primer();
	// Pre: cua no buida; 
	// Post: retorna copia del primer string de la cua
	void mostrar() const;
	// Pre: cua no buida; 
	// Post: mostra per pantalla tot el contingut de la cua actual	
	
	// MODIFICADORS 
	void encua(Peticio* p);
	// Pre: --; Post: ha afegit p al final de la cua
	void desencua();
	// Pre: cua no buida; Post: ha eliminat el primer element de la cua

	// OPERADORS REDEFINITS 
	CuaPeticions& operator=(const CuaPeticions& o);
	// Pre: -- ; Post: aquesta cua �s c�pia de o

private:
	struct Node {
		Peticio* p;
		Node* seg;
	};
	
	// ATRIBUTS
	Node* a_primer; // punter al primer de la cua
	Node* a_darrer; // punter al darrer de la cua
	void copia(const CuaPeticions& o);
	// Pre: Cua buida; Post: aquesta cua es copia de o
	void allibera();
	// Pre: --; Post: cua buida
};
#endif // CUAPETICIONS_H
