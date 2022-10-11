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
    case 7:
      for (int i = 0; i < languagesFile1.size(); i++) {
        if (auxInvocate.equal(languagesFile1[i], languagesFile2[i]))
          outputFile << "Está incluido" << std::endl;
        else 
          outputFile << "No está incluido" << std::endl;
      }
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
