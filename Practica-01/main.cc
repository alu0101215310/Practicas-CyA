#include <iostream>

void help();

int main(int argc, char* argv[]) {
  try {
    if (argc == 4) {
      




    } else {
      help();
    }
  }
  catch (...) {
    std::cout << "Error" << std::endl;
  } 

  return 0;
}

void help () {}