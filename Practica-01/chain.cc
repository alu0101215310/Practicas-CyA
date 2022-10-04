////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 1 - Símbolos, alfabetos y cadenas
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 03/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo chain.cc: 
//    Fichero que contiene las definición de la clase chain y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "chain.h"

// Constructor que transforma un string en vector de caracteres
chain::chain(std::string newInfo) {
  for (auto it : newInfo) {
    info.push_back(it);
  }
}

// Destructor
chain::~chain() {}

// Devuelve el vector de la cadena
std::vector<char> chain::getChain() {
  return info;
}
