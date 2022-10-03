////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 1 - Símbolos, alfabetos y cadenas
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 03/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo operation.h: 
//    Fichero que contiene la declaración de la clase operation y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "alphabet.h"

class operation{
  private:
    int code;
    std::ifstream input;
    std::ofstream output;
    std::vector<chain> language;

  public:
    operation(char*[]);
    ~operation();

    void init();

    void lenght();
    void reverse();
    void preffix();
    void suffix();
    void subchain();
};