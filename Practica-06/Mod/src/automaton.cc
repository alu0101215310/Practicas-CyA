////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 6 - Simulación de Autómatas Finitos
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 8/11/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo automaton.cc: 
//   Fichero que contiene las definición de la clase automaton y sus métodos,
//    incluyendo las operaciones que se tendrán que llevar a cabo
////////////////////////////////////////////////////////////////////////////////

#include "../include/automaton.h"

automaton::automaton(void) {}

automaton::automaton(char* faFileName) {
  std::string line;
  std::ifstream automatonFile;
  automatonFile.open(faFileName);
  
  if (!automatonFile)
    throw fileError();
  // Asignación de los primeros valores
  getline(automatonFile, line);
    symbols = alphabet(line); // alfabéto
  getline(automatonFile, line);
    totalStates = atoi(line.c_str()); // total de estados
  getline(automatonFile, line);
    runState = line; // estado de arranque

  // Declaración de estados
  while (getline(automatonFile, line)) {
    std::stringstream word(line);
    getline(word, line, SPACE);
      state auxState(line); 
    getline(word, line, SPACE);
      auxState.setAccept(line); 
    getline(word, line, SPACE);
      auxState.setTotalTransition(atoi(line.c_str()));

    // Declaración de las transiciones
    for (int i = 0; i < auxState.getTotalTransition(); i++) {
      std::string auxId, auxDest;
      getline(word, auxId, SPACE);
      getline(word, auxDest, SPACE);
      std::pair<std::string, std::string> newTransition (auxId, auxDest);
      auxState.addTransition(newTransition);       
    }
    states.insert(auxState);
  }
}

automaton::~automaton(void) {}

std::string automaton::getRunState(void) const {
  return runState;
}

alphabet automaton::getAlphabet(void) const {
  return symbols;
}

std::set<state> automaton::getStates(void) const {
  return states;
}

// Devuelve un estado buscándolo por su id
state automaton::find(std::string stateId) {
  state result;
  for (auto it : states) {
    if (it.getId() == stateId)      
      result.copy(it);
  }
  return result;
}