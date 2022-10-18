////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 3 - Calculadora de lenguajes formales
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
management::management(char* inputFileName) {
  init(inputFileName);
}

// Destructor
management::~management(void) {}

void management::init(char* inputFileName) {
  std::string line;

  inputFile.open(inputFileName);

  if (!inputFile)
    throw fileError();

  if (inputFile.is_open()) {
    while (getline(inputFile, line)) {
      if (line.find(EQUAL) != std::string::npos) {
        language newLanguage(line);
        languagesFile.push_back(newLanguage);
      }
      else 
        algorithm(line);
    }
  }
}

void management::algorithm(std::string opt) {
  int exp;
  language result;
  std::string operand;
  std::stack<language> stk;
  std::stringstream operation(opt);

  while(getline(operation, operand, SPACE)) {
    if (checkOperand(operand)) {
      switch (*operand.c_str()) {
      case '+':
        result = stk.top();
        stk.pop();
        stk.push(result + stk.top());
        break;
      case '|':
        result = stk.top();
        stk.pop();
        stk.push(result | stk.top());
        break;
      case '^':
        result = stk.top();
        stk.pop();
        stk.push(result ^ stk.top());
        break;
      case '-':
        result = stk.top();
        stk.pop();
        stk.push(result - stk.top());
        break;
      case '!':
        result = stk.top();
        stk.pop();
        stk.push(result.reverse());
        break;
      case '*':
        result = stk.top();
        stk.pop();
        std::cout << "Introduzca el exponente de la potencia: ";
        std::cin >> exp;
        stk.push(result * exp);
        break;
      default:
        throw operandError();
        break;
      }
    }
    else  
      stk.push(findLanguage(operand));
  }
  write(opt, stk.top());
  stk.pop();
}

bool management::checkOperand(std::string checkOperand) {
  for ( auto it : languagesFile) {
    if (it.getName() == checkOperand)
      return false;
  }
  return true;
}

language management::findLanguage(std::string findName) {
  language result;
  for ( auto it : languagesFile) {
    if (it.getName() == findName)
      result = it;
  }
  return result;
}

void management::write(std::string operation, language printLanguage) {
  alphabet newAlphabet(printLanguage.getLanguage());
  std::cout << operation << SPACE << EQUAL << SPACE << OPEN << SPACE << 
    newAlphabet << CLOSE << SPACE << OPEN << SPACE << printLanguage << CLOSE << std::endl;
}
