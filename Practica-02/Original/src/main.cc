////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 2 - Operaciones con lenguajes
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

const unsigned int MIN = 1;
const unsigned int MAX = 6;
const unsigned int UNIT = 4;
const unsigned int ARGUMENTS = 5;  
const unsigned int POTENCY = 6;
const unsigned int ZERO = 0;

bool arguments(int argc, char* argv[], int& code);

bool argPotency(int argc, char* argv[], int& code, int& exp);

void run(char* argv[], int& code);

void runPotency(char* argv[], int& code, int& exp);

void help(void);

int main(int argc, char* argv[]) {
  try {
    int code;
    int exp;
    if (arguments(argc, argv, code)) {
      run(argv, code);
    }
    else if (argPotency(argc, argv, code, exp)) {
      runPotency(argv, code, exp);
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


bool arguments(int argc, char* argv[], int& code) {
  if (argc == ARGUMENTS) {
    code = atoi(argv[4]);
    if (code >= MIN && code < MAX) {
      return true;
    }
  }
  return false;
}

bool argPotency(int argc, char* argv[], int& code, int& exp) {
  if (argc == POTENCY) {
    code = atoi(argv[4]);
    exp = atoi(argv[5]);
    if (code >= MIN && code <= MAX && exp != ZERO) {
      return true;
    }
  }
  return false;
}

void run(char* argv[], int& code) {
  management mng(argv[1], argv[2], argv[3]);
  mng.operation(code, ZERO);
}

void runPotency(char* argv[], int& code, int& exp) {
  management mng(argv[1], argv[2], argv[3]);
  mng.operation(code, exp);
}

void help (void) {
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Formato del Programa: ./Prog Entrada Salida Codigo Exp?"   << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Prog: Nombre del Programa"                                 << std::endl;
    std::cout << "Entrada: Fichero con el texto a analizar"                  << std::endl;
    std::cout << "Salida: Fichero con el texto analizado"                    << std::endl;
    std::cout << "Codigo: Clave de la operacion a realizar"                  << std::endl;
    std::cout << "   1.  Concatenacion"                                      << std::endl;
    std::cout << "   2.  Union"                                              << std::endl;
    std::cout << "   3.  Interseccion"                                       << std::endl;
    std::cout << "   4.  Diferencia"                                         << std::endl;
    std::cout << "   5.  Inversa"                                            << std::endl;
    std::cout << "   6.  Potencia"                                           << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "El fichero de salida sera creado en el caso"               << std::endl; 
    std::cout << "de que no exista"                                          << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
}