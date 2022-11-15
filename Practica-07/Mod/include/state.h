////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 7 - Gramática Regular a partir de un DFA
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 15/11/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo state.h: 
//   Fichero que contiene la declaración de la clase state y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "exception.h"

class state {
  private:
    std::string id;
    // Vector de pares con el valor de la trasición y el id de destino
    std::vector<std::pair<std::string, std::string>> transitions;
    int totalTransitions;
    bool accept; // Si es un estado de aceptación
  public:
    state(void);
    state(std::string);
    ~state(void);

    std::string getId(void) const;
    std::vector<std::pair<std::string, std::string>> getTransitions(void) const;
    int getTotalTransition(void) const;
    bool getAccept(void) const;

    void addTransition(std::pair<std::string, std::string>);
    void setAccept(std::string);
    void setTotalTransition(int);
    void copy(state);

    bool operator<(const state&) const;
};