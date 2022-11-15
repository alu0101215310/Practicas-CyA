////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 7 - Gramática Regular a partir de un DFA
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 15/11/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo automaton.h: 
//   Fichero que contiene la declaración de la clase automaton y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "state.h"
#include "grammar.h"

class automaton {
  private:
    int totalStates;
    std::string runState; // ID del estado de arranque
    alphabet symbols;
    std::set<state> states; // Conjunto de estados

    std::set<state> visitedStates; // Estados que fueron visitados
    std::set<state> actualStates; // Estados que se están evaluando
  public:
    automaton(void);
    automaton(char*);
    ~automaton(void);

    std::string getRunState(void) const;
    alphabet getAlphabet(void) const;
    std::set<state> getStates(void) const;

    state find(std::string);
    void checkChains(chain);

    grammar generateGrammar(void);
};