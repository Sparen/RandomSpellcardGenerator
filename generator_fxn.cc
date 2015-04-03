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
  //There MUST be at least one of each category (sign, adj, noun, noun2)
  //Any non-canon words go under fanon. 
  /*****************************OFFICIAL ONLY*****************************/
  if(character=="Reimu" || character=="DEFAULT"){
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
  if(character=="Marisa" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Rumia" || character=="DEFAULT"){
    //Touhou Canon
    sign.push_back("Moon Sign");
    sign.push_back("Night Sign");
    sign.push_back("Darkness Sign");
    adj.push_back("Moonlight");
    adj.push_back("Night");
    adj.push_back("Midnight");
    noun.push_back("Ray");
    noun.push_back("Bird");
    noun.push_back("Demarcation");
    noun.push_back("Dark Side");
    noun2.push_back("the Moon");
    //Touhou Fanon
  }
  if(character=="Daiyousei" || character=="DEFAULT"){
    //Touhou Fanon
  }
  if(character=="Cirno" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Meiling" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Koakuma" || character=="DEFAULT"){
    //Touhou Fanon
  }
  if(character=="Patchouli" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Sakuya" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Remilia" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Flandre" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Letty" || character=="DEFAULT"){
    //Touhou Canon
    sign.push_back("Cold Sign");
    sign.push_back("Winter Sign");
    sign.push_back("White Sign");
    sign.push_back("Mystic Sign");
    adj.push_back("Lingering");
    adj.push_back("Flower");
    adj.push_back("Undulation");
    adj.push_back("Cold");
    adj.push_back("Northern");
    noun.push_back("Cold");
    noun.push_back("Wither Away");
    noun.push_back("Ray");
    noun.push_back("Snap");
    noun.push_back("Winter");
    //Touhou Fanon
    noun2.push_back("Frost");
  }
  if(character=="Chen" || character=="DEFAULT"){
    //Touhou Canon
    sign.push_back("Hermit Sign");
    sign.push_back("Shikigami Sign");
    sign.push_back("Child Sign");
    sign.push_back("Flight Sign");
    sign.push_back("Heaven Sign");
    sign.push_back("Oni Sign");
    sign.push_back("Direction Sign");
    sign.push_back("Star Sign");
    sign.push_back("Yin Yang");
    sign.push_back("Cat Monster");
    sign.push_back("Oni God");
    adj.push_back("Phoenix");
    adj.push_back("Pentagram");
    adj.push_back("Large Pentagram");
    adj.push_back("Immortal Sage's");
    adj.push_back("Incarnate");
    adj.push_back("Soaring");
    adj.push_back("Jumping Crossing");
    adj.push_back("Rumbling");
    noun.push_back("Egg");
    noun.push_back("Spread Wings");
    noun.push_back("Flight");
    noun.push_back("Crest");
    noun.push_back("Rumbling");
    noun.push_back("Sage");
    noun.push_back("Rampage");
    noun.push_back("Konjin");
    noun.push_back("Bishamonten");
    noun.push_back("Scale");
    noun.push_back("Jikoku-ten");
    noun2.push_back("Idaten");
    noun2.push_back("the Demon's Gate");
    //Touhou Fanon
  }
  if(character=="Alice" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Lily" || character=="DEFAULT"){
    //Touhou Fanon
  }
  if(character=="Merlin" || character=="DEFAULT"){
    //Touhou Canon
    sign.push_back("Trumpet Spirit");
    sign.push_back("Nether Trumpet");
    sign.push_back("Noise Sign");
    adj.push_back("Hino");
    adj.push_back("Ghost");
    adj.push_back("Merlin Happy");
    noun.push_back("Phantasm");
    noun.push_back("Clifford");
    //Touhou Fanon
  }
  if(character=="Lyrica" || character=="DEFAULT"){
    //Touhou Canon
    sign.push_back("Nether Keys");
    sign.push_back("Key Spirit");
    sign.push_back("Noise Sign");
    adj.push_back("Fazioli");
    adj.push_back("Bosendorfer");
    adj.push_back("Soul Noise");
    noun.push_back("Nether Performance");
    noun.push_back("Divine Performance");
    noun.push_back("Flow");
    //Touhou Fanon
  }
  if(character=="Lunasa" || character=="DEFAULT"){
    //Touhou Canon
    sign.push_back("String Performance");
    sign.push_back("Divine Strings");
    sign.push_back("Fake Strings");
    sign.push_back("Noise Sign");
    adj.push_back("Pseudo");
    adj.push_back("Noise");
    noun.push_back("Stradivarius");
    noun.push_back("Melancholy");
    //Touhou Fanon
  }
  if(character=="Merlin" || character=="Lyrica" || character=="Lunasa" || character=="DEFAULT"){
    //Touhou Canon
    sign.push_back("Noise Sign");
    sign.push_back("Funeral Concert");
    sign.push_back("Noisy Funeral");
    sign.push_back("Great Funeral Concert");
    adj.push_back("Phantom");
    adj.push_back("Live");
    adj.push_back("Prism");
    adj.push_back("Stygian");
    adj.push_back("Ghostly Wheel");
    noun.push_back("Dinning");
    noun.push_back("Poltergeist");
    noun.push_back("Concerto");
    noun.push_back("Riverside");
    noun.push_back("Concerto Grosso");
    //Touhou Fanon
    noun2.push_back("Melody");
    noun2.push_back("Harmony");
  }
  if(character=="Youmu" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Yuyuko" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Ran" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Yukari" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Suika" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Wriggle" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Mystia" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Keine" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Tewi" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Udonge" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Eirin" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Kaguya" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Mokou" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Aya" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Medicine" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Yuuka" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Komachi" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Shikieiki" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Shizuha" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Minoriko" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Hina" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Nitori" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Momiji" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Sanae" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Kanako" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Suwako" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Iku" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Tenshi" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Kisume" || character=="DEFAULT"){
    //Touhou Canon
    sign.push_back("Horror");
    sign.push_back("Well Bucket");
    adj.push_back("Tsurube-Otoshi");
    adj.push_back("Well");
    noun.push_back("Apparition");
    noun.push_back("Destructor");
    //Touhou Fanon
    noun2.push_back("Fire");
  }
  if(character=="Yamame" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Parsee" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Yuugi" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Satori" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Orin" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Utsuho" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Koishi" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Nazrin" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Kogasa" || character=="DEFAULT"){
    //Touhou Canon
    sign.push_back("Large Ring");
    sign.push_back("Umbrella Sign");
    sign.push_back("Rain Sign");
    sign.push_back("Umbrella");
    sign.push_back("Monster Sign");
    sign.push_back("Monster Train");
    sign.push_back("Surprising Rain");
    sign.push_back("Halo");
    sign.push_back("Rainbow Sign");
    adj.push_back("Umbrella");
    adj.push_back("Hello Forgotten");
    adj.push_back("Parasol Star");
    adj.push_back("A Rainy Night's");
    adj.push_back("Super Water-Repelling Bone-Dry");
    adj.push_back("A Forgotten Umbrella's");
    adj.push_back("Spare Umbrella Express");
    adj.push_back("Lightly Falling Large");
    adj.push_back("Guerilla");
    adj.push_back("Karakasa Surprising");
    adj.push_back("Flurry");
    adj.push_back("One-Legged");
    noun.push_back("World");
    noun.push_back("Halo");
    noun.push_back("Ghost Story");
    noun.push_back("Memories");
    noun.push_back("Symphony");
    noun.push_back("Night Train");
    noun.push_back("Night Carnival");
    noun.push_back("Typhoon");
    noun.push_back("Raindrops");
    noun.push_back("Rainbow");
    noun.push_back("Traveler");
    noun.push_back("Cyclone");
    noun.push_back("Flash");
    //Touhou Fanon
    noun2.push_back("Light");
    noun2.push_back("Rain");
  }
  if(character=="Ichirin" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Minamitsu" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Shou" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Byakuren" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Nue" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Hatate" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Sunny" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Luna" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Star" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Kyouko" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Yoshika" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Seiga" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Tojiko" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Futo" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Miko" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Mamizou" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Kokoro" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Wakasagihime" || character=="DEFAULT"){
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
  if(character=="Sekibanki" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Kagerou" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Benben" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Yatsuhashi" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Seija" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Shinmyoumaru" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Raiko" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  if(character=="Kasen" || character=="DEFAULT"){
    //Touhou Canon

    //Touhou Fanon
  }
  /*****************************SPINOFF ONLY*****************************/
  if(character=="Akyuu" || character=="DEFAULT"){
    //Touhou Fanon
  }
  if(character=="Kosuzu" || character=="DEFAULT"){
    //Touhou Fanon
  }
  if(character=="Toyohime" || character=="DEFAULT"){
    //Touhou Fanon
  }
  if(character=="Yorihime" || character=="DEFAULT"){
    //Touhou Fanon
  }
  /*****************************IDO*****************************/
  /*****************************LEN'EN*****************************/
  /*****************************SEITENTOUJI*****************************/
  /*****************************NANSEI*****************************/
  /*****************************CHOUYOU*****************************/
  
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

