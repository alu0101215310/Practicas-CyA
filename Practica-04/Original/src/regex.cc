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
  write(outputFileName);
} 

regex::~regex (void) {};

void regex::build (void) {
  std::string line;
  int counter = 1;
  mainEx = false;
  bool checkDesc = false;
  
  while (getline(inputFile, line)) {
    if (std::regex_match(line, std::regex(COMMEXOP))) {
      comment comm(line, counter);
      if (counter == 1) checkDesc = true;
      while (!std::regex_match(line, std::regex(COMMEXCL))) {
        getline(inputFile,line);
        comm.addLine(line);
        counter++;
      } 
      if (checkDesc) {
        desc = comm;
        checkDesc = false;
      }
      comm.addLastPos(counter);
      comments.push_back(comm);
    }
    else if (std::regex_match(line, std::regex(COMMEX))) {
      comment comm(line, counter);
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

void regex::write (std::string program) {
  outputFile << "PROGRAM: " << program << std::endl;
  outputFile << "DESCRIPTION:" << std::endl;
  for (auto it : desc.getVar()) 
    outputFile << it << std::endl;
  outputFile << std::endl << "VARIABLES:" << std::endl;
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
  outputFile << std::endl << "COMMENTS:" << std::endl;
  for (auto it : comments)
    outputFile << it << std::endl;
}