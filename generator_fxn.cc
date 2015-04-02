#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
#include <set>
#include "generator_fxn.h"

using std::list;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::set;

/*Generates: "<sign>: <noun> of <noun2>" or "<sign> Sign: <adj> <noun>"
*/

Generator::Generator(string character){
  // if character is DEFAULT, will use all available signs, adjectives, and nouns 
  if (character == "Reimu" || character == "DEFAULT"){
    //Touhou Canon
    sign.push_back("Spirit Sign");
    sign.push_back("Dream Sign");
    sign.push_back("Divine Spirit");
    sign.push_back("Divine Arts");
    sign.push_back("Scattered Spirit");
    sign.push_back("Migrating Spirit");
    sign.push_back("Dream Land");
    sign.push_back("Treasure Sign");
    sign.push_back("Holy Relic");
    sign.push_back("Power Sign");
    sign.push_back("Dream Battle");
    sign.push_back("Jewel Sign");
    sign.push_back("Prayer");
    sign.push_back("Light Spirit");
    sign.push_back("Barrier");
    sign.push_back("Treasure");
    sign.push_back("Charm");
    sign.push_back("Talisman");
    sign.push_back("Amulet");
    sign.push_back("Omikuji");
    adj.push_back("Fantasy");
    adj.push_back("Omnidirectional");
    adj.push_back("Demon-Binding");
    adj.push_back("Dragon-Slaying");
    adj.push_back("Duplex");
    adj.push_back("Hakurei");
    adj.push_back("Yin-Yang");
    adj.push_back("Sky-Conquering");
    adj.push_back("Disaster-Dispelling");
    adj.push_back("Dancing");
    adj.push_back("Wild Exorcising");
    adj.push_back("Expanding");
    adj.push_back("Youkai-Repelling");
    adj.push_back("Shrine Prosperity");
    adj.push_back("Anti-Youkai");
    noun.push_back("Seal");
    noun.push_back("Sign");
    noun.push_back("Circle");
    noun.push_back("Orb");
    noun.push_back("Treasured Orb");
    noun.push_back("Moon");
    noun.push_back("Orb String");
    noun.push_back("Demon God Orb");
    noun.push_back("Barrier");
    noun.push_back("Danmaku Barrier");
    noun.push_back("Illusion");
    noun.push_back("Wind-God Kick");
    noun.push_back("Dimensional Kick");
    noun.push_back("Scattering");
    noun2.push_back("Exorcism");
    noun2.push_back("Light");
    noun2.push_back("Sealing");
    //Touhou Fanon 

  }
  if (character == "Marisa" || character == "DEFAULT") {
    sign.push_back("Light Sign");
    sign.push_back("Love Sign");
    sign.push_back("Star Sign");
    sign.push_back("Magicannon");
    sign.push_back("Light Dance");
    sign.push_back("Reflection");
    sign.push_back("Refraction");
    adj.push_back("Bright");
    adj.push_back("Dark");
    adj.push_back("Master");
    adj.push_back("Blazing");
    adj.push_back("Reflective");
    adj.push_back("Refractive");
    adj.push_back("Astral");
    noun.push_back("Spark");
    noun.push_back("Beam");
    noun.push_back("Laser");
    noun.push_back("Light");
    noun.push_back("Ray");
    noun.push_back("Flashlight");
    noun.push_back("Meteor");
    noun.push_back("Comet");
    noun.push_back("Star");
    noun.push_back("Asteroid");
    noun.push_back("Horizon");
    noun2.push_back("Earth");
    noun2.push_back("Sky");
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

template<typename T>
T Generator::pick(vector<T> v) {
  return v.at(rand() % v.size());
}

string Generator::GenerateA1(){
  return pick(sign) + ": " + pick(adj) + " " + pick(noun);
}

string Generator::GenerateA2(){
  return pick(sign) + ": "+ pick(noun) + " of " + pick(noun2);
}

string Generator::GenerateA3() {
  int roll = rand() & 15;
  int adjCount =
    roll < 8 ? 1 :
    roll < 12 ? 2 :
    roll < 14 ? 3 : 4;
  string res = "";
  set<string> adjs;
  for (int i = 0; i < adjCount; ++i) {
    adjs.insert(pick(adj));
  }
  for (string s : adjs) {
    res = res + s + " ";
  }
  return pick(sign) + ": " + res + pick(noun);
}

void Generator::PrintA1() {
  cout << GenerateA1() << endl;
}

void Generator::PrintA2() {
  cout << GenerateA2() << endl;
}

void Generator::PrintA3() {
  cout << GenerateA3() << endl;
}