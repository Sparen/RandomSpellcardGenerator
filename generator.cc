#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <time.h>
#include "generator_fxn.h"

using std::list;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::find;

/****************************************************
 * RANDOM SPELLCARD NAME GENERATOR by Sparen, 2015  *
 ****************************************************/

int main(){
  srand(time(NULL));
  //Obtain input from user on character
  cout << "Please type the name of the character whose cards you want to generate." << endl << "Example: Reimu, Udonge, Rumia, Tewi, Shinmyoumaru, Minamitsu" << endl;
  string input;
  cin >> input;

  vector<string> names;
  names.push_back("Reimu");
  names.push_back("Marisa");

  vector<string>::iterator it;
  it = find(names.begin(), names.end(), input);
  if (it == names.end()) { // not found
    cout << "Name not in list. Using Default" << endl;
    input = "DEFAULT";
  }

  //Create Generator
  Generator gen(input);

  cout << "How many spellcard names do you want?" << endl;
  int num;
  cin >> num;
  for(int i = 0; i < num; i++){
    switch (rand() & 15) {
	  case 0: gen.PrintA3(); break;
	  case 1:
	  case 2:
	  case 3: gen.PrintA2(); break;
	  default: gen.PrintA1();
	}
  }
  return 0;
}
