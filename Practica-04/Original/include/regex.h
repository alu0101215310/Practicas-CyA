#include "variable.h"
#include "comment.h"
#include "loop.h"

const std::string VAREX = "[[:s:]]*(int|double)[[:s:]]+[[:w:]]+([[:s:]]*=[[:s:]]*[[:d:]]+)[[:s:]]*;";
const std::string LOOPEX = "[[:s:]]*(for|while)[[:s:]]*[(].*[)][[:s:]]*[{]";
const std::string MAINEX = "int[[:s:]]main[[:s:]]*[(][[:print:]]*[)][[:s:]]*[{]"; 
const std::string COMMEX = "//[[:print:]]*";
const std::string COMMEXOP = "/[*][[:print:]]*";
const std::string COMMEXCL = "[[:print:]]*[*]/";

class regex {
  private:
    std::vector<variable> variables;
    std::vector<loop> loops;
    std::vector<comment> comments;
    bool mainEx;

    std::ifstream inputFile;
    std::ofstream outputFile;

  public:
    regex(void);
    regex(char*,char*);
    ~regex(void);
  
    void build(void);
    void write(void);
};