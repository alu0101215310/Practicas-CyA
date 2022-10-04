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

// Representa una calculadora que se hará cargo del análisis
// y representación de los datos pasados al programa
class operation{
  private:
    int code; // Código de operación
    std::ifstream input; // Fichero de entrada
    std::ofstream output; // Fichero de salida
    std::vector<chain> language; // Conjunto de cadenas
    std::vector<alphabet> alphabets; // Conjunto de alfabetos

  public:
    operation(char*[]);
    ~operation();

    void init();

    void lenght();
    void reverse();
    void preffix();
    void suffix();
    void subchain();
    void difSymbols();
};