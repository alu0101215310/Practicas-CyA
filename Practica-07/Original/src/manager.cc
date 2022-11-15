////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 7 - Gramática Regular a partir de un DFA
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 15/11/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo manager.cc: 
//   Fichero que contiene las definición de la clase manager y sus métodos,
//    incluyendo las operaciones que se tendrán que llevar a cabo
////////////////////////////////////////////////////////////////////////////////

#include "../include/manager.h"

manager::manager(void) {}

manager::manager(char* faFileName, char* outputFileName) {
  std::string line;
  // Crea el autómata y comienza el check
  fa = automaton(faFileName);
  gra = fa.generateGrammar();
  write(outputFileName);
}

manager::~manager(void) {}

void manager::write(char* outputFileName) {
  std::ofstream grammarFile;
  grammarFile.open(outputFileName);
  if (!grammarFile)
    throw fileError();
  grammarFile << gra.getAlphabet().getAlphabet().size() << std::endl;
    for (auto it : gra.getAlphabet().getAlphabet())
      grammarFile << it << std::endl;
  grammarFile << gra.getNTS().size() << std::endl;
    for (auto it : gra.getNTS())
      grammarFile << it << std::endl;
  grammarFile << gra.getProductions().size() << std::endl;
    for (auto it : gra.getProductions())
      grammarFile << it.first << " -> " << it.second << std::endl;
}