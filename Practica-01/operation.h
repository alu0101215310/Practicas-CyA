#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "alphabet.h"

class operation{
  private:
    int code;
    std::ifstream input;
    std::ofstream output;
    std::vector<chain> language;

  public:
    operation(char*[]);
    ~operation();

    void init();

    void lenght();
    void reverse();
    void preffix();
    void suffix();
    void subchain();
};