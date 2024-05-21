#ifndef HORA_H
#define HORA_H

#include <string>

class Hora { // Descripci�: una hora
public:
  // CONSTRUCTORS
  Hora();
  // Pre: --
  // Post: Hora inicialitzat

  Hora(int hora);
  // Pre: --
  // Post: Hora inicialitzat amb dades passades per funcio

  // CONSULTORS
  void mostrar() const;
  // Pre: --
  // Post: mostrar per pantalla l'hora actual

  bool es_valida(int hora, int i) const;
  // Pre: --
  // Post: retorna cert si hora actual es valida si i es 1, si i es 0 retorna cert si hora es valida

  // MODIFICADORS
  void llegir_hora();
  // Pre: --
  // Post: llegir hora per teclat

  void supar_hores();
  // Pre: --
  // Post: sumar 2 hores a hora actual

  // OPERADORS REDEFINITS
  bool operator==(const Hora &h) const;
  // Pre: --
  // Post: retorna cert si hora actual es igual a h

  bool operator>(const Hora &h) const;
  // Pre: --
  // Post: retorna cert si hora actual es major a h

private:
  int a_hora;
  int a_minut;
};
#endif // HORA_H
