////////////////////////////////////////////////////////////////////////////////
// Universidad de La Laguna
// Asignatura: Computabilidad y Algoritmia (CyA)
// Práctica 2 - Operaciones con lenguajes
////////////////////////////////////////////////////////////////////////////////
// Autor: Alejandro Pérez Álvarez
// Correo: alu0101215310@ull.edu.es
// Fecha: 10/10/2022
////////////////////////////////////////////////////////////////////////////////
// Archivo operation.h: 
//    Fichero que contiene la declaración de la clase operation y sus métodos
////////////////////////////////////////////////////////////////////////////////

#include "language.h"

// Representa una calculadora que se hará cargo del análisis
// y representación de los datos pasados al programa
class management{
  private:
    std::ifstream inputFile1; // Fichero de entrada
    std::ifstream inputFile2; // Fichero de entrada
    std::ofstream outputFile; // Fichero de salida
    std::vector<language> languagesFile1; // Conjunto de cadenas
    std::vector<language> languagesFile2; // Conjunto de cadenas

  public:
    management(void);
    management(char*, char*, char*);
    ~management(void);

    void init(char*, char*, char*);
    void operation(int, int); 
    void write(std::vector<language>);
};