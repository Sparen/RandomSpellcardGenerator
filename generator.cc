#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include "generator_fxn.h"
#include "config.h"
#include "wordsep.h"

using std::vector;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::set;
using std::getline;
using std::map;
using std::ifstream;

void getNames(set<string> &names, map<string, string> &aliases);
int readConfiguration(int argc, char** argv);
int normalizeIncNameList(set<string> &includedNames, set<string> &names,
  map<string, string> &aliases, Config c);

/****************************************************
 * RANDOM SPELLCARD NAME GENERATOR by Sparen, 2015  *
 ****************************************************/

int main(int argc, char** argv) {
  Config c = readConfiguration(argc, argv);
  set<string> names;//for user input
  map<string, string> aliases;
  getNames(names, aliases);//load acceptable names and aliases

  if (HAS(c, F_HELP)) {
    cout << endl << "RANDOM SPELLCARD NAME GENERATOR BY SPAREN" << endl;
    cout << "Options:\n\
    -h (--help): displays this message\n\
    -q (--quiet): only output the resultant spell names\n\
    -v (--verbose): outputs guide text (default)\n\
    -s (--strict): does not allow default option\n\
    -l (--list-names): list all included names and exit" << endl;
    return 0;
  } else if (HAS(c, F_LIST_NAMES)) {
    for (const string &s : names) {
      cout << endl << s;
    }
    cout << endl << "* Aliases:";
    for (const auto &p : aliases) {
      cout << endl << p.first << " -> " << p.second;
    }
    cout << endl;
    return 0;
  }
  bool verbose = HAS(c, F_VERBOSE);
  /***END OF FLAGS***/

  srand(time(nullptr));
  //Obtain input from user on character
  if (verbose) {
    cout << "Please type the name of the character(s) whose cards you want to generate." << endl;
    cout << "Example: Reimu Marisa" << endl;
    cout << "You can type multiple names to mix and match signs and phrases between multiple characters." << endl;
    cout << "If you decide to use this option, please use the option -s, as if a name is not found, default will be added." << endl;
    cout << "If you want the default (everything goes) option, type literally anything that's not a name." << endl;
  }

  string input;
  getline(cin, input); //obtain line from cin
  set<string> includedNames = split(input);
  int normErr = normalizeIncNameList(includedNames, names, aliases, c);
  if (normErr != 0) return normErr;
  //Create Generator
  Generator gen(includedNames);
  
  // Flush stdin so it doesn't skip asking for spellcard count
  cout << std::flush;
  
  if (verbose) cout << "How many spellcard names do you want?" << endl;
  int num;
  cin >> num;
  for(int i = 0; i < num; i++){
    switch (rand() % 19) { // 1/18 A3, 3/18 A2, 1/18 A4, 13/18 A1
    case 0: gen.PrintA3(); break;
    case 1:
    case 2:
    case 3: gen.PrintA2(); break;
    case 4: gen.PrintA4(); break;
    case 5: gen.PrintA5(); break;
    default: gen.PrintA1();
    }
  }
}

//list of names and aliases located in chara/manifest.txt
void getNames(set<string> &names, map<string, string> &aliases) {
  char lineBuff[256];
  ifstream inFile("chara/manifest.txt");
  while (!inFile.eof()) {
    inFile.getline(lineBuff, 256);
    if (*lineBuff == '#') continue;//ignore lines starting with #
    char* curr = strtok(lineBuff, " ,");
    char* first = curr;
    names.insert(curr); //add the first name on each line to names
    while (curr != nullptr) {//for each other element on the line, map the alias to the main name
      curr = strtok(nullptr, " ,");
      if (curr != nullptr) aliases[string(curr)] = string(first);
    }
  }
}

/***START OF FLAGS. Code by Fluffy8x***/
int readConfiguration(int argc, char** argv) {
  Config c = ~(1 << F_HELP | 1 << F_LIST_NAMES);
  for (int i = 1; i < argc; ++i) {
    char* arg = argv[i];
    if (arg[0] == '-') {
      switch (arg[1]) {
        case '-': {
          char* option = arg + 2;
          if (!strcmp(option, "quiet")) RESET(c, F_VERBOSE);
          else if (!strcmp(option, "verbose")) SET(c, F_VERBOSE);
          else if (!strcmp(option, "help")) SET(c, F_HELP);
          else if (!strcmp(option, "strict")) RESET(c, F_INVALID_AS_DEFAULT);
          else if (!strcmp(option, "list-names")) SET(c, F_LIST_NAMES);
          else {
            cerr << "Unknown option " << option << endl;
            return 1;
          }
          break;
        }
        case 'q': RESET(c, F_VERBOSE); break;
        case 'v': SET(c, F_VERBOSE); break;
        case 'h': SET(c, F_HELP); break;
        case 's': RESET(c, F_INVALID_AS_DEFAULT); break;
        case 'l': SET(c, F_LIST_NAMES); break;
        default: {
          cerr << "Unknown option " << arg[1] << endl;
          return 1;
        }
      }
    }
  }
  return c;
}

// NOTE! Returns nullptr on error
int normalizeIncNameList(set<string> &includedNames, set<string> &names,
  map<string, string> &aliases, Config c) {
  bool verbose = HAS(c, F_VERBOSE);
  bool strict = !HAS(c, F_INVALID_AS_DEFAULT);
  if (includedNames.empty()) {//no names
    if (strict) {
      cerr << "No names included." << endl;
      return 1;
    } else {
      if (verbose)
        cout << "No names included. Using Default" << endl;
      includedNames = names;
      return 0;
    }
  } else {
    // no & since having it there sometimes causes segfaults
    for (const string n : includedNames) {//for every name in the input
      if (names.count(n) == 0) { // not found
        string orig;
        //  Yes, this is a single equals sign.         --v Not a derp or a typo.
        if (aliases.count(n) != 0 && names.count(orig = aliases[n]) != 0) { // search for aliases
          // Substitute the alias in the included names list with the original name
          includedNames.erase(n);
          includedNames.insert(orig);
        }
        else if (strict) {
          cerr << "Name " << n << " not in list." << endl;
          return 1;
        } else {
          if (verbose)
            cout << "Name " << n << " not in list. Using Default" << endl;
          includedNames = names; //default, everything goes
          return 0;
        }
      }
    }
  }
  return 0;
}