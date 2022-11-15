////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 7 - Gramática Regular a partir de un DFA
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 15/11/2022
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

void automaton::checkChains(chain tryChain) {
  bool check = false;  
  actualStates.clear();
  actualStates.insert(find(getRunState()));
  visitedStates.clear();

  // Registra los estados visitados
  for (auto sym : tryChain.getChain()) {
    if (sym == EMPTY) visitedStates = actualStates;
    for (auto st : actualStates) {
      for (auto tr : st.getTransitions()) {
        if (*tr.first.c_str() == sym) {
          visitedStates.insert(find(tr.second));
        }
      }
    }
    actualStates = visitedStates; // Cambia los estados a analizar
    visitedStates.clear();
  }

  for (auto it : actualStates) 
    if (it.getAccept() == true) check = true; // Compueba si hay un estado de aceptación
  std::cout << tryChain << " --- " << (check? "Accepted" : "Rejected")  << std::endl; 
}

// Genera una gramática a partir de un dfa
grammar automaton::generateGrammar(void) {
  grammar result;
  result.setAlphabet(symbols); // Comparten alfabeto
  std::string nt;
  std::string auxnt;
  for (auto st : states){
    nt = "Q" + st.getId(); 
    result.addNT(nt); // Se añade no terminal
    for (auto tr : st.getTransitions()) {
      auxnt = "Q" + tr.second;
      if(find(tr.second).getAccept()) // Comprueba si es un estado de aceptación
        result.addProduction(auxnt, EMPTYS, SPACES); // Se añade producción
      result.addNT(auxnt); // Se añade no terminal
      result.addProduction(nt, tr.first, auxnt); // Se añade producción
    }
  }
  return result;
}