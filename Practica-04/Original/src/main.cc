////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 4 - Expresiones regulares
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 25/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo main.cc: 
//    Fichero que contiene la función main del programa, esta se encargará de 
//    hacer la primera llamada a funciones, además de procesar la línea de
//    comando. También incluye una función help() que servirá de guía de 
//    utilización del programa
////////////////////////////////////////////////////////////////////////////////

#include "../include/regex.h"

const unsigned int ARGUMENTS = 3;

bool arguments(int argc, char* argv[]);

void help(void);

int main(int argc, char* argv[]) {
  try {
    if (arguments(argc, argv))
      regex rgx(argv[1], argv[2]);
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
    std::cout << "Formato del Programa: ./Prog Entrada Salida              " << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Prog: Nombre del Programa"                                 << std::endl;
    std::cout << "Entrada: Fichero con el código a analizar"                 << std::endl;
    std::cout << "Salida: Fichero donde se escribirán los resultados"        << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
}