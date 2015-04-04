#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <time.h>
#include <string.h>
#include "generator_fxn.h"
#include "config.h"

using std::list;
using std::vector;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::find;

/****************************************************
 * RANDOM SPELLCARD NAME GENERATOR by Sparen, 2015  *
 ****************************************************/

int main(int argc, char** argv) {
  /***START OF FLAGS. Code by Fluffy8x***/
  Config c = ~(1 << F_EIRIN);
  for (int i = 1; i < argc; ++i) {
    char* arg = argv[i];
    if (arg[0] == '-') {
      switch (arg[1]) {
        case '-': {
          char* option = arg + 2;
          if (!strcmp(option, "quiet")) RESET(c, F_VERBOSE);
          else if (!strcmp(option, "verbose")) SET(c, F_VERBOSE);
          else if (!strcmp(option, "help")) SET(c, F_EIRIN);
          else {
            cerr << "Unknown option " << option << endl;
            exit(EXIT_FAILURE);
          }
          break;
        }
        case 'q': RESET(c, F_VERBOSE); break;
        case 'v': SET(c, F_VERBOSE); break;
        case 'h': SET(c, F_EIRIN); break;
        default: {
          cerr << "Unknown option " << arg[1] << endl;
          exit(EXIT_FAILURE);
        }
      }
    }
  }
  if (HAS(c, F_EIRIN)) {
    cout << endl << "RANDOM SPELLCARD NAME GENERATOR BY SPAREN" << endl;
    cout << "Options:\n\
    -h (--help): displays this message\n\
    -q (--quiet): only output the resultant spell names\n\
    -v (--verbose): outputs guide text (default)" << endl;
    return 0;
  }
  bool verbose = HAS(c, F_VERBOSE);
  /***END OF FLAGS***/

  srand(time(NULL));
  //Obtain input from user on character
  if (verbose) cout << "Please type the name of the character whose cards you want to generate.\nExample: Reimu, Udonge, Rumia, Tewi, Shinmyoumaru, Minamitsu\n";
  string input;
  cin >> input;

  vector<string> names;
  /*Please push back in order of game # shown. See generator_fxn.cc for order*/
  /*****************************OFFICIAL ONLY*****************************/
  names.push_back("Reimu");
  names.push_back("Marisa");
  names.push_back("Rumia");
  names.push_back("Letty");
  names.push_back("Chen");
  names.push_back("Lyrica"); names.push_back("Lunasa"); names.push_back("Merlin");
  names.push_back("Ran");
  names.push_back("Wriggle");
  names.push_back("Mystia");
  names.push_back("Tewi");
  names.push_back("Medicine");
  names.push_back("Yuuka");
  names.push_back("Shikieiki");
  names.push_back("Shizuha");
  names.push_back("Minoriko");
  names.push_back("Momiji");
  names.push_back("Kisume");
  names.push_back("Yamame");
  names.push_back("Parsee");
  names.push_back("Yuugi");
  names.push_back("Satori");
  names.push_back("Kogasa");
  names.push_back("Kyouko");
  names.push_back("Wakasagihime");
  names.push_back("Sekibanki");
  /*****************************SPINOFF ONLY*****************************/
  /*****************************IDO*****************************/
  /*****************************LEN'EN*****************************/
  /*****************************SEITENTOUJI*****************************/
  /*****************************NANSEI*****************************/
  /*****************************CHOUYOU*****************************/
  names.push_back("Rencron");
  names.push_back("Reiri");

  vector<string>::iterator it;
  it = find(names.begin(), names.end(), input);
  if (it == names.end()) { // not found
    if (verbose) cout << "Name not in list. Using Default" << endl;
    input = "DEFAULT";
  }
  
  //Create Generator
  Generator gen(input);
  
  if (verbose) cout << "How many spellcard names do you want?" << endl;
  int num;
  cin >> num;
  for(int i = 0; i < num; i++){
    switch (rand() & 15) {//rand % 16 - 1/16 A3, 3/16 A2, 12/16 A1
    case 0: gen.PrintA3(); break;
    case 1:
    case 2:
    case 3: gen.PrintA2(); break;
    default: gen.PrintA1();
    }
  }
  return 0;
}
