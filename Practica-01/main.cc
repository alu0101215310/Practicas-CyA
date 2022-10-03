#include "operation.h"

void help();

int main(int argc, char* argv[]) {
  try {
    if (argc == 4) {
      operation op(argv);
      op.init();
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