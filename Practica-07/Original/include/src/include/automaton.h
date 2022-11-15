////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 6 - Simulación de Autómatas Finitos
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 8/11/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo automaton.h: 
//   Fichero que contiene la declaración de la clase automaton y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "state.h"
#include "alphabet.h"

class automaton {
  private:
    int totalStates;
    std::string runState; // ID del estado de arranque
    alphabet symbols;
    std::set<state> states; // Conjunto de estados
  public:
    automaton(void);
    automaton(char*);
    ~automaton(void);

    std::string getRunState(void) const;
    alphabet getAlphabet(void) const;
    std::set<state> getStates(void) const;

    state find(std::string);
};