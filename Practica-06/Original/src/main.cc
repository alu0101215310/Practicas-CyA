////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 6 - Simulación de Autómatas Finitos
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 8/11/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo main.cc: 
//    Fichero que contiene la función main del programa, esta se encargará de 
//    hacer la primera llamada a funciones, además de procesar la línea de
//    comando. También incluye una función help() que servirá de guía de 
//    utilización del programa
////////////////////////////////////////////////////////////////////////////////

#include "../include/manager.h"

const unsigned int ARGUMENTS = 3;

bool arguments(int argc, char* argv[]);

void help(void);

int main(int argc, char* argv[]) {
  try {
    if (arguments(argc, argv)) {
      manager(argv[1], argv[2]);
    }
    else 
      help();
  } 
  catch (std::exception& e) {
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << e.what()                                                    << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
  }
  return 0;
}

bool arguments(int argc, char* argv[]) {
  if (argc == ARGUMENTS)
    return true;
  else
    return false;
}

void help (void) {
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Formato del Programa: ./Prog Autómata Cadenas            " << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Prog: Nombre del Programa"                                 << std::endl;
    std::cout << "Autómata: Fichero con el atómata a crear"                  << std::endl;
    std::cout << "Cadenas: Fichero cons las cadenas a comprobar"             << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
}