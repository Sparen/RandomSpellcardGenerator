#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <set>
#include "generator_fxn.h"
#include "config.h"
#include "wordsep.h"

using std::list;
using std::vector;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::find;
using std::set;
using std::getline;

/****************************************************
 * RANDOM SPELLCARD NAME GENERATOR by Sparen, 2015  *
 ****************************************************/

int main(int argc, char** argv) {
  /***START OF FLAGS. Code by Fluffy8x***/
  Config c = ~(1 << F_HELP);
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
          else {
            cerr << "Unknown option " << option << endl;
            exit(EXIT_FAILURE);
          }
          break;
        }
        case 'q': RESET(c, F_VERBOSE); break;
        case 'v': SET(c, F_VERBOSE); break;
        case 'h': SET(c, F_HELP); break;
        case 's': RESET(c, F_INVALID_AS_DEFAULT); break;
        default: {
          cerr << "Unknown option " << arg[1] << endl;
          exit(EXIT_FAILURE);
        }
      }
    }
  }
  if (HAS(c, F_HELP)) {
    cout << endl << "RANDOM SPELLCARD NAME GENERATOR BY SPAREN" << endl;
    cout << "Options:\n\
    -h (--help): displays this message\n\
    -q (--quiet): only output the resultant spell names\n\
    -v (--verbose): outputs guide text (default)\n\
    -s (--strict): does not allow default option" << endl;
    return 0;
  }
  bool verbose = HAS(c, F_VERBOSE);
  bool strict = !HAS(c, F_INVALID_AS_DEFAULT);
  /***END OF FLAGS***/

  srand(time(NULL));
  //Obtain input from user on character
  if (verbose) cout << "Please type the name of the character whose cards you want to generate." << endl;
  if (verbose) cout << "Example: Reimu, Udonge, Rumia, Tewi, Shinmyoumaru, Minamitsu" << endl;
  if (verbose) cout << "You can type multiple names to mix and match signs and phrases between multiple characters." << endl;
  if (verbose) cout << "If you decide to use this option, please use the option -s, as if a name is not found, default will be added." << endl;
  string input;
  getline(cin, input);

  set<string> names;
  /*Please push back in order of game # shown. See generator_fxn.cc for order*/
  /*****************************OFFICIAL ONLY*****************************/
  names.insert("Reimu");
  names.insert("Marisa");
  names.insert("Rumia");
  names.insert("Letty");
  names.insert("Chen");
  names.insert("Lyrica"); names.insert("Lunasa"); names.insert("Merlin");
  names.insert("Ran");
  names.insert("Wriggle");
  names.insert("Mystia");
  names.insert("Tewi");
  names.insert("Medicine");
  names.insert("Yuuka");
  names.insert("Shikieiki");
  names.insert("Shizuha");
  names.insert("Minoriko");
  names.insert("Momiji");
  names.insert("Kisume");
  names.insert("Yamame");
  names.insert("Parsee");
  names.insert("Yuugi");
  names.insert("Satori");
  names.insert("Orin");
  names.insert("Utsuho");
  names.insert("Nazrin");
  names.insert("Kogasa");
  names.insert("Minamitsu");
  names.insert("Shou");
  names.insert("Hatate");
  names.insert("Kyouko");
  names.insert("Yoshika");
  names.insert("Seiga");
  names.insert("Wakasagihime");
  names.insert("Sekibanki");
  /*****************************SPINOFF ONLY*****************************/
  /*****************************IDO*****************************/
  /*****************************LEN'EN*****************************/
  /*****************************SEITENTOUJI*****************************/
  /*****************************NANSEI*****************************/
  /*****************************CHOUYOU*****************************/
  names.insert("Rencron");
  names.insert("Reiri");
  names.insert("Rygen");
  names.insert("Nikou");
  
  set<string> includedNames;
  includedNames = split(input);
  for (string n : includedNames) {
    if (names.count(n) == 0) { // not found
      if (strict) {
        cerr << "Name " << n << " not in list." << endl;
        exit(EXIT_FAILURE);
      } else {
        if (verbose) cout << "Name " << n << " not in list. Using Default" << endl;
        includedNames = names;
        break;
      }
    }
  }
  
  //Create Generator
  Generator gen(includedNames);
  
  // Flush stdin so it doesn't skip asking for spellcard count
  fflush(stdin);
  
  if (verbose) cout << "How many spellcard names do you want?" << endl;
  int num;
  cin >> num;
  for(int i = 0; i < num; i++){
    switch (rand() & 17) {//rand % 18 - 1/18 A3, 3/18 A2, 1/18 A4, 13/18 A1
    case 0: gen.PrintA3(); break;
    case 1:
    case 2:
    case 3: gen.PrintA2(); break;
    case 4: gen.PrintA4(); break;
    default: gen.PrintA1();
    }
  }
  return 0;
}
