#include "../include/regex.h"

void help(void);

int main(int argc, char* argv[]) {
  try {
    
    regex rgx(argv[1], argv[2]);


  } 
  catch (std::exception& e) {
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << e.what()                                                    << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
  }
  return 0;
}

void help (void) {
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Formato del Programa: ./Prog Entrada                     " << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    std::cout << "Prog: Nombre del Programa"                                 << std::endl;
    std::cout << "Entrada: Fichero con el texto a analizar"                  << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
}