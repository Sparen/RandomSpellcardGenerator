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
    if (character=="Wakasagihime"){
      //Touhou Canon
      sign.push_back("Water Sign");
      sign.push_back("Scale Sign");
      sign.push_back("Tide Sign");
      sign.push_back("Fish Sign");
      adj.push_back("Tail Fin");
      adj.push_back("Scale");
      adj.push_back("Lunatic Red");
      noun.push_back("Slap");
      noun.push_back("Wave");
      noun.push_back("Raging Waves");
      noun.push_back("Great Raging Waves");
      noun.push_back("Tidal Wave");
      noun.push_back("School");
      noun2.push_back("the Reversed Scale");
      noun2.push_back("the Lake");
      noun2.push_back("Fish");
      //Touhou Fanon
    }
    if (character=="Sekibanki"){
      //Touhou Canon
      sign.push_back("Flight Sign");
      sign.push_back("Neck Sign");
      sign.push_back("Flying Head");
      sign.push_back("Glinting Eyes");
      sign.push_back("Flying Neck");
      adj.push_back("Flying");
      adj.push_back("Close-Eye");
      adj.push_back("Rokurokubi");
      adj.push_back("Multiplicative");
      adj.push_back("Dullahan");
      adj.push_back("Extreme");
      adj.push_back("Hell's");
      adj.push_back("Twin Rokuro");
      noun.push_back("Head");
      noun.push_back("Shot");
      noun.push_back("Flight");
      noun.push_back("Night");
      noun.push_back("Long Neck");
      noun.push_back("Ray");
      //Touhou Fanon
      noun2.push_back("the Dullahan");
    }
    if (character=="Kagerou"){
      //Touhou Canon
      sign.push_back("Fang Sign");
      sign.push_back("Transformation");
      sign.push_back("Roar");
      sign.push_back("Wolf Sign");
      sign.push_back("Sirius");
      sign.push_back("Full Moon");
      sign.push_back("Wolf Fang");
      adj.push_back("Canine");
      adj.push_back("Triangle");
      adj.push_back("Star");
      adj.push_back("Strange");
      adj.push_back("Star Ring");
      adj.push_back("High-Speed");
      adj.push_back("Bloodthirsty Wolf");
      adj.push_back("Full Moon");
      noun.push_back("Teeth");
      noun.push_back("Fang");
      noun.push_back("Roar");
      noun.push_back("Howling");
      noun.push_back("Pounce");
      noun2.push_back("the Full Moon");
      //Touhou Fanon
      noun2.push_back("the Werewolf");
    }
    if (character=="Benben"){
      //Touhou Canon
      sign.push_back("Heikyoku");
      sign.push_back("Vengeful Spirit");
      sign.push_back("Music Sign");
      sign.push_back("Noise Sign");
      sign.push_back("Score");
      adj.push_back("Earless");
      adj.push_back("Taira's Great");
      adj.push_back("Wicked");
      adj.push_back("Malicious");
      adj.push_back("Double");
      adj.push_back("Score");
      adj.push_back("Earless");
      noun.push_back("Sounds");
      noun.push_back("Hoichi");
      noun.push_back("Vengeful Spirit");
      noun.push_back("Musical Score");
      noun.push_back("Score");
      noun.push_back("Biwa");
      noun.push_back("Web");
      noun2.push_back("Jetavana's Bell");
      //Touhou Fanon
    }
    if (character=="Yatsuhashi"){
      //Touhou Canon
      sign.push_back("Koto Sign");
      sign.push_back("Echo Sign");
      sign.push_back("Koto Music");
      sign.push_back("Elegy");
      adj.push_back("Heian's");
      adj.push_back("Echo");
      adj.push_back("Social Upheaval");
      noun.push_back("Norigoto");
      noun.push_back("Sounds");
      noun.push_back("Reverberation");
      noun.push_back("Chamber");
      noun.push_back("Koto Music Complement");
      noun.push_back("Requiem");
      noun2.push_back("Heaven");
      noun2.push_back("Anicca's Koto");
      //Touhou Fanon
    }
    if (character=="Benben" || character=="Yatsuhashi"){
      //Touhou Canon
      sign.push_back("String Music");
      sign.push_back("Double Chant");
      adj.push_back("Storm");
      adj.push_back("Joruri");
      noun.push_back("Ensemble");
      noun.push_back("World");
      noun.push_back("Song");
      noun2.push_back("Falling Stars");
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
    if (character == "Rencron" || character == "Reiri") {
      // TODO add more stuff
      sign.push_back("Leaf Sign");
      sign.push_back("Earth Sign");
      sign.push_back("Wind Sign");
      sign.push_back("Tree Sign");
      adj.push_back("Leaf-Ejecting");
      adj.push_back("Unknown");
      adj.push_back("Wily");
      adj.push_back("Silver");
      noun.push_back("Salamander");
      noun.push_back("Wind");
      noun.push_back("Sword");
      noun.push_back("Bow");
      noun.push_back("Guard");
      noun.push_back("Arrows");
      noun.push_back("Sunrise");
      noun2.push_back("the Deep Forest");
      noun2.push_back("the Horizon");
    }
    if (character == "Rygen" || character == "Nikou") {
      sign.push_back("Light Sign");
      sign.push_back("Rainbow Sign");
      sign.push_back("Red Sign");
      sign.push_back("Green Sign");
      sign.push_back("Blue Sign");
      sign.push_back("Cyan Sign");
      sign.push_back("Magenta Sign");
      sign.push_back("Yellow Sign");
      sign.push_back("Nine Colors");
      adj.push_back("Superluminal");
      adj.push_back("Mystic");
      adj.push_back("Spectrum");
      adj.push_back("Impulse");
      adj.push_back("Experimental");
      adj.push_back("Fox's");
      adj.push_back("Stygian");
      adj.push_back("Mirror");
      adj.push_back("Spherical");
      adj.push_back("Great");
      adj.push_back("Sinusoidal");
      adj.push_back("First");
      adj.push_back("Second");
      adj.push_back("Spiral");
      adj.push_back("Cumulonimbus-Ascending");
      noun.push_back("Beam");
      noun.push_back("Quake");
      noun.push_back("Expansion");
      noun.push_back("Laser");
      noun.push_back("Familiar");
      noun.push_back("Wall");
      noun.push_back("Cave-Searching");
      noun.push_back("Blue");
      noun.push_back("Mirror");
      noun.push_back("Reflection");
      noun.push_back("Optics");
      noun.push_back("Paddle");
      noun.push_back("Clock");
      noun.push_back("Ladder");
      noun2.push_back("Nine Colors");
      noun2.push_back("the Rainbow");
    }
    if (character == "Mernen") {
      sign.push_back("Grass Sign");
      sign.push_back("Starry Sky");
      sign.push_back("Short Grass");
      sign.push_back("Flower Sign");
      sign.push_back("Grass's Anger");
      adj.push_back("Resting");
      adj.push_back("Starlight");
      adj.push_back("Grass");
      adj.push_back("Little");
      adj.push_back("Sleeping");
      adj.push_back("Pure");
      adj.push_back("Corrupted");
      adj.push_back("Golden");
      noun.push_back("Butterfly");
      noun.push_back("Wave");
      noun.push_back("Grass");
      noun.push_back("Flower");
      noun.push_back("Pollen-Scattering");
      noun.push_back("Buds");
      noun.push_back("Leaves");
      noun.push_back("Shooting");
      noun.push_back("Darkness");
      noun.push_back("Forest");
      formatterList.push_back("Near the _");
      formatterList.push_back("The _ Below Us");
      formatterList.push_back("_ in the _");
      noun2.push_back("the Wind");
      noun2.push_back("the Trees");
    }
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