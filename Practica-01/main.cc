////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 1 - Símbolos, alfabetos y cadenas
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 03/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo main.cc: 
//    Fichero que contiene la función main del programa, esta se encargará de 
//    hacer la primera llamada a funciones, además de procesar la línea de
//    comando. También incluye una función help() que servirá de guía de 
//    utilización del programa
////////////////////////////////////////////////////////////////////////////////

#include "operation.h"

void help();

int main(int argc, char* argv[]) {
  if (argc == 4) {
    operation op(argv);
    op.init();
  } else {
    help();
  }
  return 0;
}

void help () {
  std::cout << "---------------------------------------------------------" << std::endl;
  std::cout << "Formato del Programa: ./Prog Entrada Salida Codigo"        << std::endl;
  std::cout << "---------------------------------------------------------" << std::endl;
  std::cout << "Prog: Nombre del Programa"                                 << std::endl;
  std::cout << "Entrada: Fichero con el texto de entrada"                  << std::endl;
  std::cout << "Salida: Fichero con el texto de salida"                    << std::endl;
  std::cout << "Codigo: Clave de la operacion a realizar"                  << std::endl;
  std::cout << "   1.  Longitud"                                           << std::endl;
  std::cout << "   2.  Inversa"                                            << std::endl;
  std::cout << "   3.  Prefijos"                                           << std::endl;
  std::cout << "   4.  Sufijos"                                            << std::endl;
  std::cout << "   5.  Subcadenas"                                         << std::endl;
  std::cout << "---------------------------------------------------------" << std::endl;
}