////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 6 - Simulación de Autómatas Finitos
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 8/11/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo state.cc: 
//   Fichero que contiene las definición de la clase state y sus métodos,
//    incluyendo las operaciones que se tendrán que llevar a cabo
////////////////////////////////////////////////////////////////////////////////

#include "../include/state.h"

state::state(void) {}

state::state(std::string newId) : id(newId) {}

state::~state(void) {}

std::string state::getId(void) const {
  return id;
}

std::vector<std::pair<std::string, std::string>> state::getTransitions(void) const {
  return transitions;
}

int state::getTotalTransition(void) const {
  return totalTransitions;
}

bool state::getAccept(void) const {
  return accept;
}

void state::addTransition(std::pair<std::string, std::string> newTransition) {
  transitions.push_back(newTransition);
}


void state::setTotalTransition(int total) {
  totalTransitions = total;
}


void state::setAccept(std::string type) {
  if (atoi(type.c_str()) == 1)
    accept = true;
  else
    accept = false;
}

// Copia un estado con sus atributos
void state::copy(state origin) {
  id = origin.id;
  transitions = origin.transitions;
  totalTransitions = origin.totalTransitions;
  accept = origin.accept;
}

bool state::operator<(const state& compareState) const {
  if (id < compareState.getId()) 
    return true;
  else 
    return false;
}