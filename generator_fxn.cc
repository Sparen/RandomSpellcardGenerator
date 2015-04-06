#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <fstream>
#include "generator_fxn.h"

using std::vector;
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::set;
using std::ifstream;

/*Generates: "<sign>: <noun> of <noun2>" or "<sign> Sign: <adj> <noun>"
*/

Generator::Generator(const set<string> &characters){
  //if character is DEFAULT, will use all available signs, adjectives, and nouns 
  //There MUST be at least one of each category (sign, adj, noun, noun2)
  //Any non-canon words go under fanon. 
  //Remember to cite sources for particularly interesting or creative words and phrases (see Yuuka for an example)
  /*****************************OFFICIAL ONLY*****************************/
  for (const string &character : characters) {
    load(character);
    if (character=="Daiyousei"){
      //Touhou Fanon
    }
    if (character=="Meiling"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Koakuma"){
      //Touhou Fanon
    }
    if (character=="Patchouli"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Sakuya"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Remilia"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Alice"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Lily"){
      //Touhou Fanon
    }
    if (character=="Youmu"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Yuyuko"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Yukari"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Suika"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Udonge"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Eirin"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Kaguya"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Aya"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Komachi"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Hina"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Nitori"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Sanae"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Kanako"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Suwako"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Iku"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Tenshi"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Koishi"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Ichirin"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Byakuren"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Nue"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Sunny"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Luna"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Star"){
      //Touhou Canon
    }
    if (character=="Tojiko"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Futo"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Miko"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Mamizou"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Kokoro"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Seija"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Shinmyoumaru"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Raiko"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Kasen"){
      //Touhou Canon

      //Touhou Fanon
    }
    /*****************************SPINOFF ONLY*****************************/
    if (character=="Akyuu"){
      //Touhou Fanon
    }
    if (character=="Kosuzu"){
      //Touhou Fanon
    }
    if (character=="Toyohime"){
      //Touhou Fanon
    }
    if (character=="Yorihime"){
      //Touhou Fanon
    }
    /*****************************IDO*****************************/
    /*****************************LEN'EN*****************************/
    /*****************************SEITENTOUJI*****************************/
    /*****************************NANSEI*****************************/
    /*****************************CHOUYOU*****************************/
  }
}

void Generator::load(const string &character) {
  char lineBuff[256];
  ifstream inFile("chara/" + character + ".txt");
  int mode = FR_SIGN;
  while (!inFile.eof()) {
    inFile.getline(lineBuff, 256);
    if (*lineBuff == '#') continue;
    if (*lineBuff == ':') {
      char* label = lineBuff + 1;
      if (!strcmp(label, "sign")) mode = FR_SIGN;
      else if (!strcmp(label, "adj")) mode = FR_ADJ;
      else if (!strcmp(label, "noun")) mode = FR_NOUN;
      else if (!strcmp(label, "noun2")) mode = FR_NOUN2;
      else if (!strcmp(label, "formatter")) mode = FR_FORMATTER;
      else {
        cerr << lineBuff << " is not a valid label" << endl;
        inFile.close();
        exit(EXIT_FAILURE);
      }
    } else {
      switch (mode) {
        case FR_SIGN: sign.push_back(lineBuff); break;
        case FR_ADJ: adj.push_back(lineBuff); break;
        case FR_NOUN: noun.push_back(lineBuff); break;
        case FR_NOUN2: noun2.push_back(lineBuff); break;
        case FR_FORMATTER: formatterList.push_back(lineBuff);
      }
    }
  }
  inFile.close();
}

string Generator::GenerateB1() {
  return pick(adj) + " " + pick(noun);
}

string Generator::GenerateB2() {
  return pick(noun) + " of " + pick(noun2);
}

string Generator::GenerateB3() {
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
  for (const string &s : adjs) {
    res += s + " ";
  }
  return res + pick(noun);
}

string Generator::GenerateA1(){
  return pick(sign) + ": " + GenerateB1();
}

string Generator::GenerateA2(){
  return pick(sign) + ": " + GenerateB2();
}

string Generator::GenerateA3() {
  return pick(sign) + ": " + GenerateB3();
}

string Generator::GenerateA4() {
  int r1 = rand() % 15;
  int r2 = rand() % 15;
  return (r1 == 0 ? GenerateA3() : r1 < 4 ? GenerateA2() : GenerateA1())
    + " - " + (r2 == 0 ? GenerateB3() : r2 < 4 ? GenerateB2() : GenerateB1());
}

// Name with formatter
string Generator::GenerateA5() {
  // so we don't get single word names
  if (formatterList.empty())
    return GenerateA1();
  string formatter = pick(formatterList);
  int formL = formatter.length();
  string res = pick(sign) + ": ";
  for (int i = 0; i < formL; ++i) {
    char c = formatter[i];
    if (c != '_') {
      res += c;
    } else {
      res += GenerateA5H();
    }
  }
  return res;
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

void Generator::PrintA4() {
  cout << GenerateA4() << endl;
}

void Generator::PrintA5() {
  cout << GenerateA5() << endl;
}