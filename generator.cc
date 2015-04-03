#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
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
  /*Please push back in order of game # shown. See generator_fxn.cc for order*/
  names.push_back("Reimu");
  names.push_back("Rumia");
  names.push_back("Letty");
  names.push_back("Kisume");
  names.push_back("Kogasa");
  names.push_back("Wakasagihime");

  vector<string>::iterator it;
  it = find(names.begin(), names.end(), input);
  if(it == names.end()){//not found
    cout << "Name not in list. Using Default" << endl;
    input = "DEFAULT";
  }

  //Create Generator
  Generator gen(input);

  cout << "How many spellcard names do you want?" << endl;
  int num;
  cin >> num;
  for(int i = 0; i < num; i++){
    if(rand()%4!=0){
      gen.GenerateA1();
    }else{
      gen.GenerateA2();
    }
  }
  return 0;
}
