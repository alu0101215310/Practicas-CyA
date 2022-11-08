////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 6 - Simulación de Autómatas Finitos
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 8/11/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo manager.cc: 
//   Fichero que contiene las definición de la clase manager y sus métodos,
//    incluyendo las operaciones que se tendrán que llevar a cabo
////////////////////////////////////////////////////////////////////////////////

#include "../include/manager.h"

manager::manager(void) {}

manager::manager(char* faFileName, char* chainsFileName) {
  std::string line;
  std::ifstream chainsFile;
  chainsFile.open(chainsFileName);

  if (!chainsFileName)
    throw fileError();
  // Crea el autómata y comienza el check
  fa = automaton(faFileName);
  while (getline(chainsFile, line))
    checkChains(chain(line));
}

manager::~manager(void) {}

void manager::checkChains(chain tryChain) {
  bool check = false;  
  actualStates.clear();
  actualStates.insert(fa.find(fa.getRunState()));
  visitedStates.clear();

  // Registra los estados visitados
  for (auto sym : tryChain.getChain()) {
    if (sym == EMPTY) visitedStates = actualStates;
    for (auto st : actualStates) {
      for (auto tr : st.getTransitions()) {
        if (*tr.first.c_str() == sym) {
          visitedStates.insert(fa.find(tr.second));
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