////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 3 - Calculadora de lenguajes formales
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 10/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo main.cc: 
//    Fichero que contiene la función main del programa, esta se encargará de 
//    hacer la primera llamada a funciones, además de procesar la línea de
//    comando. También incluye una función help() que servirá de guía de 
//    utilización del programa
////////////////////////////////////////////////////////////////////////////////

#include "../include/management.h"

const unsigned int ARGUMENTS = 2;  

bool arguments(int argc, char* argv[]);

void run(char* argv[]);

void help(void);

int main(int argc, char* argv[]) {
  try {
    if (arguments(argc, argv)) {
      run(argv);
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

void run(char* argv[]) {
  management mng(argv[1]);
}

void help (void) {
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Formato del Programa: ./Prog Entrada                     " << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Prog: Nombre del Programa"                                 << std::endl;
    std::cout << "Entrada: Fichero con el texto a analizar"                  << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
}