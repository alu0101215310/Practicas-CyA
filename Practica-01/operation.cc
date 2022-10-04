////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 1 - Símbolos, alfabetos y cadenas
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 03/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo operation.cc: 
//    Fichero que contiene las definición de la clase operation y sus métodos,
//    incluyendo las operaciones que se tendrán que llevar a cabo con las cadenas
////////////////////////////////////////////////////////////////////////////////

#include "operation.h"

// Constructor que abre los ficheros y guarda el código de operación
operation::operation(char* argv[]) {
  input.open(argv[1]);
  output.open(argv[2]);
  code = atoi(argv[3]);
}
// Destructor
operation::~operation() {}

// Función coordinadora del programa
void operation::init () {
  std::string line;
  std::string symbol;
  bool checkChain = true;
  bool checkAlphabet = true;
  // Análisis edl ficher de entrada y creación de las diferentes estructuras
  // de datos a partir del mismo, sean estas caddenas y alfabetos válidos
  while (getline(input, line)) {
    std::stringstream auxLine(line);
    std::set<char> auxSet;
    while (getline(auxLine, symbol, ' ')) {
      auxSet.insert(*symbol.c_str());
      if (*symbol.c_str() == '&') checkAlphabet = false;
    }
    if (*symbol.c_str() == '&') checkAlphabet = true;
    if (auxSet.size() == 1) {
      for (auto it : symbol) {
        auxSet.insert(it);
      }
    }
    alphabet newAlphabet = alphabet(auxSet);
    chain newChain = chain(symbol);
    if (newChain.getChain()[0] != '&') {
      for (auto it : newChain.getChain()) {
        auto pos = newAlphabet.getSymbols().find(it);
        if (pos == newAlphabet.getSymbols().end() && it != '&') checkChain = false;
      }
    }
    // Comprobación de a validez de las cadenas y los alfabetos
    if (checkChain && checkAlphabet) {
      language.push_back(newChain);
      checkChain = true;
      checkAlphabet = true;
    }
    if (!checkAlphabet) {
      std::cout << "Error en el alfabeto asociado a la cadena: " << symbol << std::endl;
      checkAlphabet = true;
    }
    if (!checkChain) {
      std::cout << "Error en la cadena: " << symbol << std::endl;
      checkChain = true;
    }
  }
  // Ejecución de la función adecuada según el código
  switch (code) {
    case 1:
      lenght();
      break;
    case 2:
      reverse();
      break;
    case 3:
      preffix();
      break;
    case 4:
      suffix();
      break;
    case 5:
      subchain();
      break;
    default:
      break;
  }
}

// Genera la longitud de cada cadena válida leídas del
// fichero de entrada
void operation::lenght() {
  for (auto it : language) {
    output << it.getChain().size() << std::endl;
  }
}

// Genera la cadena inversa de cada cadena válida leídas del
// fichero de entrada
void operation::reverse() {
  for (auto it : language) {
    for (int i = it.getChain().size() - 1; i >= 0; i--) {
      output << it.getChain()[i];
    }
    output << std::endl;
  }
}

// Genera los prefijos de cada cadena válida leídas del
// fichero de entrada
void operation::preffix() {
  int counter = 0;
  for (auto it : language) {
    if (it.getChain()[0] != '&') output << "& ";
    while (counter < it.getChain().size()) {
      for (int i = 0; i <= counter; i++) {
        output << it.getChain()[i];
      }
      output << " ";
      counter++;
    }
    output << std::endl;
    counter = 0;
  }
}

// Genera los sufijos de cada cadena válida leídas del
// fichero de entrada
void operation::suffix() {
  int counter;
  for (auto it : language) {
    if (it.getChain()[0] != '&') output << "& ";
    counter = it.getChain().size() - 1;
    while (counter >= 0) {
      for (int i = counter; i < it.getChain().size(); i++) {
        output << it.getChain()[i];
      }
      output << " ";
      counter--;
    }
    output << std::endl;
  }
}

// Genera las subcadenas de cada cadena válida leídas del
// fichero de entrada
void operation::subchain() {
  for (auto it : language) {
    for (int i = 0; i < it.getChain().size(); i++) {
      int counter = i;
      while (counter < it.getChain().size()) {
        for (int j = i; j <= counter; j++) {
          output << it.getChain()[j];
        }
        output << " ";
        counter++;
      }
    }
    output << std::endl; 
  }  
}
