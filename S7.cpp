#include <iostream>
#include <iomanip>
#include <string>

#include "Hora.h"
#include "CuaPeticions.h"
#include "Peticio.h"

using namespace std;

void entrar_dades(int &unitats_disponibles, int &venda_maxima, Hora &hora_inici) {
    // Pre: --
    // Post: retorna la dades demanades entrades per teclat
    cout << "COMPRAVENDA DEL VIDEOJOC" << endl;

    cout << "UNITATS DISPONIBLES A LA BOTIGA:" << endl;
    cin >> unitats_disponibles;
    while (unitats_disponibles < 0) {
        cin >> unitats_disponibles;
    }

    cout << "VENDA MAXIMA PER OPERACIO:" << endl;
    cin >> venda_maxima;
    while (venda_maxima <= 0) {
        cin >> venda_maxima;
    }

    cout << "HORA D'INICI DE LES OPERACIONS:" << endl;
    hora_inici.llegir_hora();
}
void mostrar_menu() {
    // Pre: --
    // Post: mostra per pantalla el menu d'opcions
    cout << "OPCIONS:" << endl;
    cout << "1: AFEGIR UNA PETICIO" << endl;
    cout << "2: PROCESSAR SEGUENT PETICIO" << endl;
    cout << "3: MOSTRAR PETICIONS PENDENTS" << endl;
    cout << "4: MOSTRAR EL MENU D'OPCIONS" << endl;
    cout << "0: FINALITZAR" << endl;
}
int entrar_opcio() {
    // Pre: --
    // Post: retorna opcio entrada per teclat
    int opcio;
    cout << "OPCIO:" << endl;
    cin >> opcio;
    return opcio;
}
void entrar_peticio(CuaPeticions& cua, Hora hora_inici) {
    // Pre: --
    // Post: afegir peticio entrada pel teclat a la cua si es correcta
    Peticio p;
    if (p.llegir_peticio(hora_inici)) {
        cua.encua(&p);
        cout << "PETICIO ENREGISTRADA CORRECTAMENT" << endl;
    }
    else cout << "PETICIO FETA ABANS D'HORA, TORNEU MES TARD" << endl;
}
void processar_peticio(CuaPeticions &peticions_pendents, int& unitats_disponibles, const int venda_maxima, const  Hora& hora_inici) {
    // Pre: --
    // Post: si la cua no esta buida processar una petició de compravenda i mostra per pantalla les unitats disponibles
    if (!peticions_pendents.buida()) {
        cout << "PROCESSANT PETICIO" << endl;
        
        int unitats_processades = 0; 
        peticions_pendents.primer()->mostrar();
        if (peticions_pendents.primer()->processar(unitats_processades, unitats_disponibles, venda_maxima, hora_inici)) {
            Peticio p(*(peticions_pendents.primer()));
            peticions_pendents.encua(&p);
        }
        peticions_pendents.desencua();

        cout << "UNITATS DEL VIDEOJOC PROCESSADES: " << unitats_processades << endl;
        cout << "UNITATS DEL VIDEOJOC DISPONIBLES ACTUALMENT A LA BOTIGA: " << unitats_disponibles << endl;
    }
    else cout << "NO HI HA PETICIONS PENDENTS" << endl;
}
void mostrar_peticions_pendents(const CuaPeticions& peticions_pendents) {
    // Pre: --
    // Post: mostrar per pantalla les peticions_pendents 
    peticions_pendents.mostrar();
}
void mostra_info_final(const int unitats_disponibles) {
    // Pre: --
    // Post: mostra per pnatalla que s'ha tancat el marcat i les unitats disponibles
    cout << "MERCAT TANCAT" << endl;
    cout << "UNITATS DEL VIDEOJOC DISPONIBLES ACTUALMENT A LA BOTIGA: " << unitats_disponibles << endl; 
}

int main() {
    int unitats_disponibles, venda_maxima;
    Hora hora_inici;
    entrar_dades(unitats_disponibles, venda_maxima, hora_inici);
    CuaPeticions peticions;

    mostrar_menu();
    int opcio = entrar_opcio();
    while (opcio != 0) { //Finalitzar
        if (opcio == 1) entrar_peticio(peticions, hora_inici); // Entrar una petició de compravenda
        else if (opcio == 2) processar_peticio(peticions, unitats_disponibles, venda_maxima, hora_inici); // Processar una petició de compravenda
        else if (opcio == 3) mostrar_peticions_pendents(peticions); // Mostrar peticions pendents
        else if (opcio == 4) mostrar_menu(); // Mostrar el menú
        else cout << "OPCIO INCORRECTA" << endl; // Opcio incorrecta
        
        opcio = entrar_opcio();
    }

    while (!peticions.buida()) 
        processar_peticio(peticions, unitats_disponibles, venda_maxima, hora_inici);
    mostra_info_final(unitats_disponibles);
}