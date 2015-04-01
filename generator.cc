#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <list>
#include <algorithm>

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

/*Generates: "<sign>: <noun2> of <noun>" or "<sign> Sign: <adj> <noun>"
 */
class Generator{
private:
public:
  vector<string> sign;//includes the word "Sign" in it.
  vector<string> adj;
  vector<string> noun;
  vector<string> noun2;

  Generator(string character){
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

  Generator(Generator& old){
    sign = old.sign;
    adj = old.adj;
    noun = old.noun;
    noun2 = old.noun2;
  }

  ~Generator(){

  }

  void GenerateA1(){
    string toprint = sign.at(rand()%sign.size()) + ": " + adj.at(rand()%adj.size()) + " " + noun.at(rand()%noun.size());
    cout << toprint << endl;
  }

  void GenerateA2(){
    string toprint = sign.at(rand()%sign.size()) + ": "+ noun2.at(rand()%noun2.size()) + " of " + noun.at(rand()%noun.size());
    cout << toprint << endl;
  }

};

int main(){
  srand(time(NULL));
  //Obtain input from user on character
  cout << "Please type the name of the character whose cards you want to generate." << endl << "Example: Reimu, Udonge, Rumia, Tewi, Shinmyoumaru, Minamitsu" << endl;
  string input;
  cin >> input;

  vector<string> names;
  names.push_back("Reimu");

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
    if(rand()%2==0){
      gen.GenerateA1();
    }else{
      gen.GenerateA2();
    }
  }
  return 0;
}
