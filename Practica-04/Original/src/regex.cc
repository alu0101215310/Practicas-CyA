#include "../include/regex.h"

regex::regex(void) {};

regex::regex(char* inputFileName, char* outputFileName) {
  inputFile.open(inputFileName);
  outputFile.open(outputFileName);

  if (!inputFile) 
    throw fileError();
  if (!outputFile) {
    outputFile.open(outputFileName, std::ios::trunc);
    outputFile.close();
  }

  build();
  write();
} 

regex::~regex (void) {};

void regex::build (void) {
  std::string line;
  int counter = 1;
  mainEx = false;
  
  while (getline(inputFile, line)) {
    if (std::regex_match(line, std::regex(COMMEXOP))) {
      comment comm(line, counter, true);
      while (!std::regex_match(line, std::regex(COMMEXCL))) {
        counter++;
        getline(inputFile,line);
        comm.addLine(line,counter);
      } 
      comments.push_back(comm);
    }
    else if (std::regex_match(line, std::regex(COMMEX))) {
      comment comm(line, counter, false);
      comments.push_back(comm);
    }
    else if (std::regex_match(line, std::regex(LOOPEX))) {
      loop lp(line, counter);
      loops.push_back(lp);
    }
    else if (std::regex_match(line, std::regex(VAREX))) {
      variable var(line, counter);
      variables.push_back(var);
    }
    else if (std::regex_match(line, std::regex(MAINEX))) {
      mainEx = true;
    }
    counter++;
  }
}

void regex::write (void) {
  outputFile << "VARIABLES:" << std::endl;
  for (auto it : variables) 
    outputFile << it << std::endl;
  outputFile << std::endl << "STATEMENTS:" << std::endl;
  for (auto it : loops) 
    outputFile << it << std::endl;
  outputFile << std::endl << "MAIN:" << std::endl;
  if (mainEx)
    outputFile << "true" << std::endl;
  else 
    outputFile << "false" << std::endl;
}