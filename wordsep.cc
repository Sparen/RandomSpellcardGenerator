#include "wordsep.h"

#include <iostream>
using std::cout;

// SO http://stackoverflow.com/questions/5607589/right-way-to-split-an-stdstring-into-a-vectorstring
// Given a space-separated string, returns the individual words
set<string> split(string s) {
  set<string> res;
  // Cast to char* to avoid a warning
  char* cs = (char*) s.c_str();
  char* curr = strtok(cs, " ,");
  while (curr != NULL) {
    res.insert(curr);
    curr = strtok(NULL, " ,");
  }
  return res;
}