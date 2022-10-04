////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 1 - Símbolos, alfabetos y cadenas
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 03/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo alphabet.h: 
//    Fichero que contiene la declaración de la clase alphabet y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "chain.h"

class alphabet {
  private:
    std::set<char> symbols; // Conjuntos de símbolos de un alfabeto

  public:
    alphabet(std::set<char>);
    ~alphabet();

    std::set<char> getSymbols();
};
