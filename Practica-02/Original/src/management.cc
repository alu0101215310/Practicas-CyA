////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 2 - Operaciones con lenguajes
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 10/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo management.cc: 
//    Fichero que contiene las definición de la clase management y sus métodos,
//    incluyendo las operaciones que se tendrán que llevar a cabo
////////////////////////////////////////////////////////////////////////////////

#include "../include/management.h"

management::management(void) {}

// Constructor que abre los ficheros
management::management(char* inputFileName1, char* inputFileName2, char* outputFileName) {
  init(inputFileName1, inputFileName2, outputFileName);
}

// Destructor
management::~management(void) {}

void management::init(char* inputFileName1, char* inputFileName2, char* outputFileName) {
  std::string line;

  inputFile1.open(inputFileName1);
  inputFile2.open(inputFileName2);
  outputFile.open(outputFileName, std::ios::trunc);

  if (!inputFile1)
    throw fileError();
  if (!inputFile2)
    throw fileError();
  if (!outputFile) {
    outputFile.open(outputFileName, std::ios::trunc);
    outputFile.close();
  }

  if (inputFile1.is_open() && inputFile2.is_open() && outputFile.is_open()) {
    while (getline(inputFile1, line)) {
      language newLanguage(line);
      languagesFile1.push_back(newLanguage);
    }
    while (getline(inputFile2, line)) {
      language newLanguage(line);
      languagesFile2.push_back(newLanguage);
    }
  }
}

void management::operation(int code, int exp) {
  language auxInvocate;
  std::vector<language> result;
  switch (code) {
    case 1:
      for (int i = 0; i < languagesFile1.size(); i++)
        result.push_back(auxInvocate.concatenate(languagesFile1[i], languagesFile2[i]));
      write(result);
      break;
    case 2:
      for (int i = 0; i <= languagesFile1.size(); i++)
        result.push_back(auxInvocate.join(languagesFile1[i], languagesFile2[i]));
      write(result);
      break;
    case 3:
      for (int i = 0; i < languagesFile1.size(); i++)
        result.push_back(auxInvocate.intersection(languagesFile1[i], languagesFile2[i]));
      write(result);
      break;
    case 4:
      for (int i = 0; i < languagesFile1.size(); i++)
        result.push_back(auxInvocate.difference(languagesFile1[i], languagesFile2[i]));
      write(result);
      break;
    case 5:
      for (int i = 0; i < languagesFile1.size(); i++)
        result.push_back(auxInvocate.reverse(languagesFile1[i]));
      write(result);
      break;
    case 6:
      for (int i = 0; i < languagesFile1.size(); i++)
        result.push_back(auxInvocate.potency(languagesFile1[i], exp));
      write(result);
      break;
    default:
      break;
  }
}

void management::write(std::vector<language> languages) {
  for (auto it : languages) {
    alphabet newAlphabet(it.getLanguage());
    outputFile << OPEN << newAlphabet << CLOSE << SPACE << OPEN << it << CLOSE << std::endl;
  }
}

/*
// Función coordinadora del programa
void management::init () {
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
    if (*symbol.c_str() == '&') {
      checkAlphabet = true;
      auxSet.erase(*symbol.c_str());
    }
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
      alphabets.push_back(newAlphabet);
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
*/