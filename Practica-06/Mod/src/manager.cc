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

manager::manager(char* faFileName, char* fa2FileName, int size) {
  // Crea el autómata y comienza el check
  fa = automaton(faFileName);
  fa2 = automaton(fa2FileName);
   
  std::bitset<4> generator;
  for (int i = 0; i < size*size; i++) {
    bool first = checkChains(generator.to_string(), fa);
    bool second = checkChains(generator.to_string(), fa2);
    if (first == second)
      std::cout << generator << " --- Iguales" << std::endl;
    else
      std::cout << generator << " --- Distintos" << std::endl;
    generator = generator.to_ullong() + 1ULL;
  }

}

manager::~manager(void) {}

bool manager::checkChains(chain tryChain, automaton fa) {
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
  
  return (check? true : false);
}
