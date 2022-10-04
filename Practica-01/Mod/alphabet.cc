////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 1 - Símbolos, alfabetos y cadenas
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 03/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo alphabet.cc: 
//    Fichero que contiene las definición de la clase alphabet y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "alphabet.h"

// Constructor que inicializa los símbolos de un alfabeto
alphabet::alphabet(std::set<char> newSymbols) {
  symbols = newSymbols;
}

// Destructor
alphabet::~alphabet() {}

// Devuelve los símbolos de un alfabeto
std::set<char> alphabet::getSymbols() {
  return symbols;
}
