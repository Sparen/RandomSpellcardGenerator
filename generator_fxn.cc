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

/*Generates: "<sign>: <noun> of <noun2>" or "<sign> Sign: <adj> <noun>"                 
*/

Generator::Generator(string character){
  //if character is DEFAULT, will use all available signs, adjectives, and nouns 
  if(character=="Reimu" || character=="DEFAULT"){//Covering:
    sign.push_back("Spirit Sign");
    sign.push_back("Dream Sign");
    sign.push_back("Divine Spirit");
    adj.push_back("Fantasy");
    adj.push_back("Omnidirectional");
    adj.push_back("Demon-Binding");
    adj.push_back("Dragon-Slaying");
    noun.push_back("Seal");
    noun.push_back("Circle");
    noun2.push_back("Exorcism");
  }
  
}

Generator::Generator(Generator& old){
  sign = old.sign;
  adj = old.adj;
  noun = old.noun;
  noun2 = old.noun2;
}

Generator::~Generator(){

}

void Generator::GenerateA1(){
  string toprint = sign.at(rand()%sign.size()) + ": " + adj.at(rand()%adj.size()) + " " + noun.at(rand()%noun.size());
  cout << toprint << endl;
}

void Generator::GenerateA2(){
  string toprint = sign.at(rand()%sign.size()) + ": "+ noun.at(rand()%noun.size()) + " of " + noun2.at(rand()%noun2.size());
  cout << toprint << endl;
}

