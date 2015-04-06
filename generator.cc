#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <set>
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

/****************************************************
 * RANDOM SPELLCARD NAME GENERATOR by Sparen, 2015  *
 ****************************************************/

int main(int argc, char** argv) {
  /***START OF FLAGS. Code by Fluffy8x***/
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
  // Moved the name declaration here so we can list all the names if the user prompts to do so.
  /*Please add in order of game # shown. See generator_fxn.cc for order*/
  /*****************************OFFICIAL ONLY*****************************/
  set<string> names = {
    "Reimu",
    "Marisa",
    "Rumia",
    "Cirno",
    "Flandre",
    "Letty",
    "Chen",
    "Lyrica", "Lunasa", "Merlin",
    "Ran",
    "Wriggle",
    "Mystia",
    "Keine",
    "Tewi",
    "Mokou",
    "Medicine",
    "Yuuka",
    "Shikieiki",
    "Shizuha",
    "Minoriko",
    "Momiji",
    "Kisume",
    "Yamame",
    "Parsee",
    "Yuugi",
    "Satori",
    "Orin",
    "Utsuho",
    "Nazrin",
    "Kogasa",
    "Minamitsu",
    "Shou",
    "Hatate",
    "Kyouko",
    "Yoshika",
    "Seiga",
    "Wakasagihime",
    "Sekibanki",
    "Kagerou",
    "Benben",
    "Yatsuhashi",
    /*****************************SPINOFF ONLY*****************************/
    /*****************************IDO*****************************/
    /*****************************LEN'EN*****************************/
    /*****************************SEITENTOUJI*****************************/
    /*****************************NANSEI*****************************/
    /*****************************CHOUYOU*****************************/
    "Rencron",
    //"Reiri",
    "Rygen",
    //"Nikou",
    "Mernen",
  };
  
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
    cout << endl;
    return 0;
  }
  bool verbose = HAS(c, F_VERBOSE);
  bool strict = !HAS(c, F_INVALID_AS_DEFAULT);
  /***END OF FLAGS***/

  srand(time(nullptr));
  //Obtain input from user on character
  if (verbose) {
    cout << "Please type the name of the character whose cards you want to generate." << endl;
    cout << "Example: Reimu, Udonge, Rumia, Tewi, Shinmyoumaru, Minamitsu" << endl;
    cout << "You can type multiple names to mix and match signs and phrases between multiple characters." << endl;
    cout << "If you decide to use this option, please use the option -s, as if a name is not found, default will be added." << endl;
  }
  string input;
  getline(cin, input);
  set<string> includedNames = split(input);
  if (includedNames.empty()) {
    if (strict) {
      cerr << "No names included." << endl;
      return 1;
    } else {
      if (verbose)
        cout << "No names included. Using Default" << endl;
      includedNames = names;
    }
  } else {
    for (const string &n : includedNames) {
      if (names.count(n) == 0) { // not found
        if (strict) {
          cerr << "Name " << n << " not in list." << endl;
          exit(EXIT_FAILURE);
        } else {
          if (verbose)
            cout << "Name " << n << " not in list. Using Default" << endl;
          includedNames = names; //default, everything goes
          break;
        }
      }
    }
  }
  
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
