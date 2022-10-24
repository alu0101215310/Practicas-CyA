#include "../include/comment.h"

comment::comment (void) {};

comment::comment (std::string rawComment, int line, bool newType) {
  type = newType;
  pos.push_back(line);
  var.push_back(rawComment);
};

comment::~comment (void) {};

void comment::addLine (std::string newComment, int line) {
  pos.push_back(line);
  var.push_back(newComment);
}