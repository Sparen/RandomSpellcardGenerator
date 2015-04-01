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
    if(character=="Reimu" || character=="DEFAULT"){
      
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
};

int main(){
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

  //Obtain num of spell names wanted
  //Spit out the spell names
  return 0;
}
