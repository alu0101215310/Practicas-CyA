////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 7 - Gramática Regular a partir de un DFA
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 15/11/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo production.cc: 
//   Fichero que contiene las definición de la clase production y sus métodos,
//    incluyendo las operaciones que se tendrán que llevar a cabo
////////////////////////////////////////////////////////////////////////////////

#include "../include/production.h"

production::production(void) {}

production::production(std::string t, std::string nt) {
  pr[t] = nt;
}

production::~production(void) {}

// Actualiza un valor del map
void production::update(std::string t, std::string nt) {
  pr[t] = nt;
}

std::map<std::string, std::string> production::getProduction(void) const {
  return pr;
}

std::ostream& operator<<(std::ostream& os, production& pr) {
  std::string result;
  for (auto it : pr.getProduction()) {
    result += it.first + it.second + " | ";
  }
  result.erase(result.find_last_of("|") - 1);
  return os << result;
}