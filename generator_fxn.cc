#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include "generator_fxn.h"

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::set;

/*Generates: "<sign>: <noun> of <noun2>" or "<sign> Sign: <adj> <noun>"
*/

Generator::Generator(const set<string> &characters){
  //if character is DEFAULT, will use all available signs, adjectives, and nouns 
  //There MUST be at least one of each category (sign, adj, noun, noun2)
  //Any non-canon words go under fanon. 
  //Remember to cite sources for particularly interesting or creative words and phrases (see Yuuka for an example)
  /*****************************OFFICIAL ONLY*****************************/
  for (const string &character : characters) {
    if (character=="Reimu"){
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
      // Touhou Canon
      sign.push_back("Light Sign");
      sign.push_back("Light Blast");
      sign.push_back("Love Sign");
      sign.push_back("Love Storm");
      sign.push_back("Star Sign");
      sign.push_back("Ritual Sign");
      sign.push_back("Ritualic Space");
      sign.push_back("Magic Space");
      sign.push_back("Magic Waste");
      sign.push_back("Black Magic");
      sign.push_back("Astronomical Instrument");
      sign.push_back("Magicannon");
      sign.push_back("Loving Heart");
      sign.push_back("Comet");
      sign.push_back("Armillary");
      sign.push_back("Light Flow");
      sign.push_back("Magic Bullet");
      sign.push_back("Closure Sign");
      sign.push_back("Unsealed Magic");
      sign.push_back("Magic Cross");
      sign.push_back("Shooting Star");
      adj.push_back("Earth");
      adj.push_back("Earthlight");
      adj.push_back("Dark");
      adj.push_back("Master");
      adj.push_back("Dragon");
      adj.push_back("Blazing");
      adj.push_back("Asteroid");
      adj.push_back("Milky");
      adj.push_back("Final");
      adj.push_back("Double");
      adj.push_back("Event");
      adj.push_back("Light");
      adj.push_back("Non-Directional");
      adj.push_back("Stardust");
      adj.push_back("Starlight");
      adj.push_back("Illusion");
      adj.push_back("Orreries");
      adj.push_back("Escape");
      adj.push_back("Meteonic");
      adj.push_back("Luminous");
      adj.push_back("Ultimate");
      adj.push_back("Gravity");
      adj.push_back("Ecological");
      adj.push_back("Eccentric");
      adj.push_back("Shooting");
      adj.push_back("Magical");
      adj.push_back("Mysterious");
      adj.push_back("Grand");
      adj.push_back("Super");
      adj.push_back("Satellite");
      noun.push_back("Spark");
      noun.push_back("Laser");
      noun.push_back("Light");
      noun.push_back("Star");
      noun.push_back("Sun");
      noun.push_back("Belt");
      noun.push_back("Solar System");
      noun.push_back("Ray");
      noun.push_back("Reverie");
      noun.push_back("Way");
      noun.push_back("Flashlight");
      noun.push_back("Horizon");
      noun.push_back("Typhoon");
      noun.push_back("Meteor");
      noun.push_back("Velocity");
      noun.push_back("Shower");
      noun.push_back("Strike");
      noun.push_back("Universe");
      noun.push_back("Shortwave");
      noun.push_back("Bomb");
      noun.push_back("Beam");
      noun.push_back("Asteroid");
      noun.push_back("Echo");
      noun.push_back("Moon");
      noun.push_back("Flashlight");
      noun.push_back("Cross");
      noun.push_back("Perseid");
      noun.push_back("Illusion");
      noun.push_back("Pulsar");
      // Touhou Fanon
      sign.push_back("Light Dance");
      sign.push_back("Reflection");
      sign.push_back("Refraction");
      adj.push_back("Bright");
      adj.push_back("Reflective");
      adj.push_back("Refractive");
      adj.push_back("Astral");
      noun.push_back("Comet");
      noun2.push_back("the Stars");
      noun2.push_back("the Sky");
    }
    if (character=="Rumia"){
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
    if (character=="Daiyousei"){
      //Touhou Fanon
    }
    if (character=="Cirno"){
      //Touhou Canon
      sign.push_back("Ice Sign");
      sign.push_back("Hail Sign");
      sign.push_back("Freeze Sign");
      sign.push_back("Snow Sign");
      sign.push_back("Frost Sign");
      sign.push_back("Ice Clump");
      sign.push_back("Cold Body");
      sign.push_back("Cold Sign");
      sign.push_back("Blowing Ice");
      sign.push_back("Ice King");
      adj.push_back("Icicle");
      adj.push_back("Hail");
      adj.push_back("Perfect");
      adj.push_back("Diamond");
      adj.push_back("Frost");
      adj.push_back("Cold");
      adj.push_back("Minus");
      adj.push_back("Fairy");
      adj.push_back("Sword");
      adj.push_back("Insta-Freeze");
      adj.push_back("Ultimate");
      noun.push_back("Fall");
      noun.push_back("Storm");
      noun.push_back("Freeze");
      noun.push_back("Blizzard");
      noun.push_back("Columns");
      noun.push_back("Divinity");
      noun.push_back("K");
      noun.push_back("Machine Gun");
      noun.push_back("Fairy");
      noun.push_back("Sprinkler");
      noun.push_back("Freezer");
      noun.push_back("Atmosphere");
      noun.push_back("Beam");
      noun.push_back("Tornado");
      noun.push_back("Crusher");
      noun.push_back("Glacialist");
      noun.push_back("King");
      //Touhou Fanon
      noun2.push_back("Absolute Zero");
      noun2.push_back("Permafrost");
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
    if (character=="Flandre"){
      //Touhou Canon
      sign.push_back("Taboo");
      sign.push_back("Forbidden Barrage");
      sign.push_back("Secret Barrage");
      sign.push_back("Q.E.D.");
      adj.push_back("Cranberry");
      adj.push_back("Starbow");
      adj.push_back("Forbidden");
      noun.push_back("Trap");
      noun.push_back("Maze");
      noun.push_back("Catadioptric");
      noun.push_back("Clock");
      noun.push_back("Ripples");
      noun.push_back("Fruit");
      noun.push_back("Games");
      noun2.push_back("Love");
      noun2.push_back("495 Years");
      //Touhou Fanon
    }
    if (character=="Letty"){
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
    if (character=="Chen"){
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
    if (character=="Alice"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Lily"){
      //Touhou Fanon
    }
    if (character=="Merlin"){
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
    if (character=="Lyrica"){
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
    if (character=="Lunasa"){
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
    if (character=="Merlin" || character=="Lyrica" || character=="Lunasa"){
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
    if (character=="Youmu"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Yuyuko"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Ran"){
      //Touhou Canon
      sign.push_back("Shikigami");
      sign.push_back("Shikigami's Radiance");
      sign.push_back("Shikigami's Shot");
      sign.push_back("Illusion God");
      sign.push_back("Secret Sign");
      sign.push_back("Austerity Sign");
      sign.push_back("Superman");
      adj.push_back("Hermit Fox");
      adj.push_back("Fox-Tanuki Youkai");
      adj.push_back("Charming");
      adj.push_back("Princess");
      adj.push_back("Ultimate");
      adj.push_back("Unilateral");
      adj.push_back("Kokkuri-san's");
      adj.push_back("Heavenly");
      adj.push_back("O-Daishi-sama's");
      adj.push_back("Eighty Million");
      adj.push_back("Soaring");
      noun.push_back("Thoughts");
      noun.push_back("Banquet");
      noun.push_back("Laser");
      noun.push_back("Seige");
      noun.push_back("Tenko");
      noun.push_back("Buddhist");
      noun.push_back("Contact");
      noun.push_back("Descent");
      noun.push_back("Protection");
      noun.push_back("Possession");
      noun.push_back("Arcanum");
      noun.push_back("Holy Boards");
      noun.push_back("En no Ozuno");
      noun2.push_back("Twelve General Gods");
      noun2.push_back("Izuna Gongen");
      noun2.push_back("Zenki and Goki");
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
    if (character=="Wriggle"){
      //Touhou Canon
      sign.push_back("Firefly Sign");
      sign.push_back("Lamp Sign");
      sign.push_back("Wriggle Sign");
      sign.push_back("Butterfly Sign");
      sign.push_back("Hidden Bug");
      adj.push_back("Firefly");
      adj.push_back("Little");
      adj.push_back("Night");
      adj.push_back("Nightbug");
      adj.push_back("Endless Night");
      adj.push_back("Fixed");
      adj.push_back("Butterfly");
      adj.push_back("Unseasonal");
      noun.push_back("Bug");
      noun.push_back("Phenomenon");
      noun.push_back("Bug Storm");
      noun.push_back("Tornado");
      noun.push_back("Seclusion");
      noun.push_back("Storm");
      noun.push_back("Star");
      //Touhou Fanon
      noun2.push_back("Insects");
    }
    if (character=="Mystia"){
      //Touhou Canon
      sign.push_back("Vocal Sign");
      sign.push_back("Moth Sign");
      sign.push_back("Toxin Sign");
      sign.push_back("Deadly Toxin");
      sign.push_back("Hawk Sign");
      sign.push_back("Night-Blindness");
      sign.push_back("Night Sparrow");
      sign.push_back("Bird Sign");
      adj.push_back("Sphingid's");
      adj.push_back("Poisonous Moth's");
      adj.push_back("Ill-Starred");
      adj.push_back("Midnight");
      adj.push_back("Blind");
      adj.push_back("Human");
      adj.push_back("Mysterious");
      noun.push_back("Hooting");
      noun.push_back("Howl");
      noun.push_back("Wingbeats");
      noun.push_back("Scales");
      noun.push_back("Dance in the Dark");
      noun.push_back("Drive");
      noun.push_back("Song");
      noun.push_back("Chorus Master");
      noun.push_back("Nightbird");
      noun.push_back("Cage");
      noun2.push_back("the Horned Owl");
      noun2.push_back("the Night Sparrow");
      //Touhou Fanon
    }
    if (character=="Keine"){
      //Touhou Canon
      sign.push_back("Spiritual Birth");
      sign.push_back("Origin Sign");
      sign.push_back("Ambition Sign");
      sign.push_back("Land Sign");
      sign.push_back("Land Scheme");
      sign.push_back("Ending Sign");
      sign.push_back("Pseudo-History");
      sign.push_back("Future");
      sign.push_back("Past");
      sign.push_back("Reincarnation");
      sign.push_back("Light Sign");
      sign.push_back("Shroud Sign");
      sign.push_back("Japan Sign");
      sign.push_back("Hollyhock Sign");
      sign.push_back("20XX");
      sign.push_back("Great Fire");
      adj.push_back("First");
      adj.push_back("Buretsu");
      adj.push_back("Masakado");
      adj.push_back("Yoshimitsu");
      adj.push_back("General Headquarters");
      adj.push_back("Three Sacred");
      adj.push_back("Phantasmal");
      adj.push_back("God's");
      adj.push_back("Ancient");
      adj.push_back("Returning-Bridge");
      adj.push_back("Total");
      adj.push_back("Yamato");
      noun.push_back("Pyramid");
      noun.push_back("Ephemerality");
      noun.push_back("Crisis");
      noun.push_back("Treasures");
      noun.push_back("Emperor");
      noun.push_back("Legend");
      noun.push_back("Realm");
      noun.push_back("History");
      noun.push_back("Ichijo");
      noun.push_back("New History");
      noun.push_back("Purification");
      noun.push_back("Amaterasu");
      noun.push_back("Kindgdom");
      noun.push_back("Odyssey");
      noun.push_back("Flower");
      noun2.push_back("Gensokyo");
      noun2.push_back("Phantasm");
      noun2.push_back("the East");
      noun2.push_back("Edo");
      //Touhou Fanon
    }
    if (character=="Tewi"){
      //Touhou Canon
      sign.push_back("Rabbit Sign");
      sign.push_back("Owing Sign");
      sign.push_back("Runaway Rabbit");
      adj.push_back("Great Fortune");
      adj.push_back("Fluster");
      noun.push_back("Crest");
      noun.push_back("Escape");
      noun.push_back("Bare White Rabbit");
      noun.push_back("Vulnerary");
      noun2.push_back("Inaba");
      noun2.push_back("Ohnamuji-sama");
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
    if (character=="Mokou"){
      //Touhou Canon
      sign.push_back("Limiting Edict");
      sign.push_back("Immortal");
      sign.push_back("Fujiwara");
      sign.push_back("Deathless");
      sign.push_back("Forgiveness");
      sign.push_back("Hollow Giant");
      sign.push_back("Everlasting");
      sign.push_back("Hourai");
      sign.push_back("Exalted Personage");
      sign.push_back("Regretful Life");
      adj.push_back("Fire");
      adj.push_back("Flying");
      adj.push_back("Xu Fu's");
      adj.push_back("Honest Man's");
      adj.push_back("Phoenix's");
      adj.push_back("Fujiyama");
      adj.push_back("Hourai");
      adj.push_back("Imperishable");
      adj.push_back("Phoenix");
      adj.push_back("Immortality's");
      noun.push_back("Curse");
      noun.push_back("Bird");
      noun.push_back("Phoenix");
      noun.push_back("Flaw");
      noun.push_back("Dimension");
      noun.push_back("Death");
      noun.push_back("Tail");
      noun.push_back("Volcano");
      noun.push_back("Doll");
      noun.push_back("Shooting");
      noun.push_back("Rebirth");
      noun.push_back("Forewarning");
      noun.push_back("Reckless Sacrifice");
      noun.push_back("Legend");
      noun2.push_back("Tsuki-no-Iwasaka");
      noun2.push_back("Forgiving Shrine");
      noun2.push_back("St. Germain");
      //Touhou Fanon
      noun2.push_back("the Phoenix");
    }
    if (character=="Aya"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Medicine"){
      //Touhou Canon
      sign.push_back("Poison Sign");
      sign.push_back("Fog Sign");
      sign.push_back("Delusion");
      adj.push_back("Nerve");
      adj.push_back("Melancholy");
      adj.push_back("Gassing");
      adj.push_back("Poison");
      noun.push_back("Poison");
      noun.push_back("Garden");
      noun.push_back("Breath");
      noun.push_back("Delirium");
      //Touhou Fanon
      adj.push_back("Toxic");
      noun.push_back("Neurotoxin");
      noun2.push_back("Toxicity");
    }
    if (character=="Yuuka"){
      //Touhou Canon
      sign.push_back("Flower Sign");
      sign.push_back("Fantasy");
      noun.push_back("Reflowering");
      noun.push_back("Spark");
      noun.push_back("Beauty");
      noun2.push_back("Gensokyo");
      noun2.push_back("Nature");
      //Touhou Fanon
      sign.push_back("Nature Sign");
      sign.push_back("Magic Growth");//Darkness1 Yuuka
      sign.push_back("Reawakening");//Darkness1 Yuuka
      sign.push_back("Phantasm");
      sign.push_back("Ultimate Magic");//Darkness1 Yuuka
      adj.push_back("Dual");
      adj.push_back("Netherworld");//Darkness1 Yuuka
      adj.push_back("Infinite");
      adj.push_back("Grasping");//Darkness1 Yuuka
      adj.push_back("Energy");
      adj.push_back("Floral");
      noun.push_back("Blossom");
      noun.push_back("Blooming");
      noun.push_back("Thicket");//Darkness1 Yuuka
      noun.push_back("Devourer");
      noun.push_back("Illusion");//Darkness1 Yuuka
      noun.push_back("Petals");
      noun2.push_back("the Ageless FLower");//Darkness1 Yuuka
    }
    if (character=="Komachi"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Shikieiki"){
      //Touhou Canon
      sign.push_back("Guilt Sign");
      sign.push_back("Judgement");
      sign.push_back("Lie");
      adj.push_back("Wandering");
      adj.push_back("Last");
      adj.push_back("Cleansed Crystal");
      noun.push_back("Sin");
      noun.push_back("Judgement");
      noun.push_back("Tongue");
      noun.push_back("Trial");
      noun.push_back("Guilt");
      noun2.push_back("Wolf");
      noun2.push_back("the Ten Kings");
      //Touhou Fanon
    }
    if (character=="Shizuha"){
      //Touhou Canon
      sign.push_back("Leaf Sign");
      sign.push_back("Autumn Sign");
      sign.push_back("Wilted Path");
      adj.push_back("Falling");
      adj.push_back("Lost");
      noun.push_back("Falling Leaves");
      noun.push_back("Blast");
      noun.push_back("Windrow");
      noun2.push_back("Madness");
      //Touhou Fanon
    }
    if (character=="Minoriko"){
      //Touhou Canon
      sign.push_back("Autumn Sign");
      sign.push_back("Plenty Sign");
      sign.push_back("Fruit Sign");
      sign.push_back("Bumper Crop");
      sign.push_back("Baked Sweet Potato");
      adj.push_back("Autumn");
      adj.push_back("Owotoshi");
      adj.push_back("Warm Color");
      adj.push_back("Sweet Potato");
      noun.push_back("Sky");
      noun.push_back("Heart");
      noun.push_back("Promise");
      noun.push_back("Harvest");
      noun.push_back("Room");
      noun2.push_back("the Wheat God");
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
    if (character=="Momiji"){
      //Touhou Canon
      sign.push_back("Dog Sign");
      sign.push_back("Mountain Nomad");
      sign.push_back("Fang Sign");
      adj.push_back("Rabies");
      adj.push_back("Expelee's");
      adj.push_back("Chewing");
      noun.push_back("Bite");
      noun.push_back("Canaan");
      noun.push_back("Satisfaction");
      //Touhou Fanon
      sign.push_back("Wolf Tengu");
      sign.push_back("Wolf Fang");
      noun.push_back("Crunch");
      noun2.push_back("the Wolf Tengu");
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
    if (character=="Kisume"){
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
    if (character=="Yamame"){
      //Touhou Canon
      sign.push_back("Trap Sign");
      sign.push_back("Spider");
      sign.push_back("Miasma Sign");
      sign.push_back("Miasma");
      sign.push_back("Small Thread");
      sign.push_back("Poison Sign");
      adj.push_back("Capture");
      adj.push_back("Cave Spider's");
      adj.push_back("Filled");
      adj.push_back("Unexplained");
      adj.push_back("Kandata's");
      adj.push_back("Japanese Foliage");
      noun.push_back("Web");
      noun.push_back("Nest");
      noun.push_back("Miasma");
      noun.push_back("Fever");
      noun.push_back("Rope");
      noun.push_back("Spider");
      //Touhou Fanon
      noun2.push_back("the Earth Spider");
    }
    if (character=="Parsee"){
      //Touhou Canon
      sign.push_back("Jealousy Sign");
      sign.push_back("Malice Sign");
      sign.push_back("Jealousy");
      sign.push_back("Resentment Art");
      sign.push_back("Envy");
      sign.push_back("Grandpa Hanasaka");
      sign.push_back("Tongue-Cut Sparrow");
      adj.push_back("Green-Eyed");
      adj.push_back("Invisible");
      adj.push_back("Shiro's");
      adj.push_back("Jealousy");
      adj.push_back("Grudge");
      noun.push_back("Monster");
      noun.push_back("Jealousy");
      noun.push_back("Ashes");
      noun.push_back("Bomber");
      noun.push_back("Returning");
      noun.push_back("Hate");
      noun2.push_back("the Kind and Lovely");
      noun2.push_back("the Humble and Rich");
      //Touhou Fanon
    }
    if (character=="Yuugi"){
      //Touhou Canon
      sign.push_back("Oni Sign");
      sign.push_back("Shackles Sign");
      sign.push_back("Mysterious Ring");
      sign.push_back("Feat of Strength");
      sign.push_back("Big Four Arcanum");
      sign.push_back("Light Oni");
      sign.push_back("Oni's Voice");
      adj.push_back("Adamant");
      adj.push_back("Dreadful Raging");
      adj.push_back("Annihilating");
      noun.push_back("Strength");
      noun.push_back("Disorder");
      noun.push_back("Hell's Wheel");
      noun.push_back("Shackles");
      noun.push_back("Storm");
      noun.push_back("Knock Out");
      noun.push_back("Helix");
      noun.push_back("Waves");
      noun.push_back("Roar");
      noun2.push_back("Pain");
      noun2.push_back("Mt. Ooe");
      //Touhou Fanon
    }
    if (character=="Satori"){
      //Touhou Canon
      sign.push_back("Recollection");
      sign.push_back("Vague Recollection");
      sign.push_back("Brain Sign");
      sign.push_back("Heart Flower");
      adj.push_back("Terrible");
      adj.push_back("Terrifying");
      adj.push_back("Brain");
      adj.push_back("Camera-Shy");
      noun.push_back("Souvenir");
      noun.push_back("Hypnotism");
      noun.push_back("Fingerprint");
      noun.push_back("Rose");
      //Touhou Fanon
      noun2.push_back("the Mind Reader");
    }
    if (character=="Orin"){
      //Touhou Canon
      sign.push_back("Cat Sign");
      sign.push_back("Cursed Sprite");
      sign.push_back("Malicious Spirit");
      sign.push_back("Corpse Spirit");
      sign.push_back("Atonement");
      sign.push_back("Youkai");
      sign.push_back("Death Sign");
      sign.push_back("Drunkard's Walk");
      adj.push_back("Cat's");
      adj.push_back("Vengeful Cat Spirit's");
      adj.push_back("Erratic");
      adj.push_back("Zombie");
      adj.push_back("Vengeful");
      adj.push_back("Possessed");
      adj.push_back("Spleen");
      adj.push_back("Vengeful Cannibal");
      adj.push_back("Small Demon's");
      adj.push_back("Blazing");
      adj.push_back("Ghost");
      adj.push_back("Corpse");
      noun.push_back("Walk");
      noun.push_back("Erratic Step");
      noun.push_back("Fairy");
      noun.push_back("Spirit");
      noun.push_back("Eater");
      noun.push_back("Needle Mountain");
      noun.push_back("Needles");
      noun.push_back("Pain");
      noun.push_back("Rekindling");
      noun.push_back("Revival");
      noun.push_back("Wheel");
      noun.push_back("Town");
      noun.push_back("Shopping District");
      noun.push_back("Random Walk");
      noun2.push_back("a Former Hell");
      noun2.push_back("Yore");
      noun2.push_back("Dead Ashes");
      //Touhou Fanon
      noun2.push_back("the Kasha");
    }
    if (character=="Utsuho"){
      //Touhou Canon
      sign.push_back("Atomic Fire");
      sign.push_back("Explosion Sign");
      sign.push_back("Blazing Star");
      sign.push_back("Control");
      sign.push_back("Light Cover");
      sign.push_back("Nuclear Sign");
      sign.push_back("Light Energy");
      sign.push_back("Geothermal");
      sign.push_back("Crow Sign");
      sign.push_back("Heat Sign");
      sign.push_back("Star Sign");
      sign.push_back("Seven Stars");
      sign.push_back("Giant Star");
      sign.push_back("Fusion");
      adj.push_back("Nuclear");
      adj.push_back("Uncontainable");
      adj.push_back("Petit");
      adj.push_back("Mega");
      adj.push_back("Giga");
      adj.push_back("Peta");
      adj.push_back("Fixed");
      adj.push_back("Planetary");
      adj.push_back("Evil");
      adj.push_back("Heaven and Hell");
      adj.push_back("Hell's");
      adj.push_back("Subterranean");
      adj.push_back("Self");
      adj.push_back("Creeping");
      adj.push_back("High-Tension");
      adj.push_back("Nuclear Blaze");
      adj.push_back("Yatagarasu");
      adj.push_back("Abyss");
      adj.push_back("Break");
      adj.push_back("Hot Jupiter Descent");
      adj.push_back("Artificial Sun's");
      adj.push_back("Melting");
      adj.push_back("Red");
      noun.push_back("Fusion");
      noun.push_back("Excursion");
      noun.push_back("Nuclear Reaction");
      noun.push_back("Flare");
      noun.push_back("Star");
      noun.push_back("Revolution");
      noun.push_back("Meltdown");
      noun.push_back("Tokamak");
      noun.push_back("Artificial Sun");
      noun.push_back("Sun");
      noun.push_back("Heat Visor");
      noun.push_back("Blade");
      noun.push_back("Geyser");
      noun.push_back("Dive");
      noun.push_back("Reaction Dive");
      noun.push_back("Nova");
      noun.push_back("Prominence");
      noun.push_back("Model");
      noun.push_back("Spot");
      noun.push_back("White");
      noun.push_back("Giant");
      noun.push_back("Fall");
      noun2.push_back("Septentrion");
      noun2.push_back("Great Stars");
      //Touhou Fanon
      noun2.push_back("the Yatagarasu");
    }
    if (character=="Koishi"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Nazrin"){
      //Touhou Canon
      sign.push_back("Rod Sign");
      sign.push_back("Search Sign");
      sign.push_back("Vision Sign");
      sign.push_back("Defense Sign");
      sign.push_back("Jeweled Pagoda");
      sign.push_back("Treasure");
      adj.push_back("Busy");
      adj.push_back("Rare Metal");
      adj.push_back("Gold");
      adj.push_back("High Sensitivity");
      adj.push_back("Nazrin");
      adj.push_back("Pendulum");
      adj.push_back("Greatest");
      noun.push_back("Rod");
      noun.push_back("Detector");
      noun.push_back("Pendulum");
      noun.push_back("Guard");
      noun.push_back("Treasure");
      noun.push_back("Rush");
      //Touhou Fanon
      sign.push_back("Dowsing");
      sign.push_back("Treasure Sign");
      noun2.push_back("the Treasure Hunter");
      noun2.push_back("the Dowser");
    }
    if (character=="Kogasa"){
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
    if (character=="Ichirin"){
      //Touhou Canon

      //Touhou Fanon
    }
    if (character=="Minamitsu"){
      //Touhou Canon
      sign.push_back("Capsize");
      sign.push_back("Drowning Sign");
      sign.push_back("Harbor Sign");
      sign.push_back("Ghost");
      sign.push_back("Anchor Sign");
      sign.push_back("Flood");
      adj.push_back("Dragging");
      adj.push_back("Foundering");
      adj.push_back("Sinking");
      adj.push_back("Deep");
      adj.push_back("Sinkable");
      adj.push_back("Phantom Ship");
      adj.push_back("Ghost Ship's");
      adj.push_back("Eternally Anchored");
      adj.push_back("Sinker");
      noun.push_back("Anchor");
      noun.push_back("Vortex");
      noun.push_back("Harbor");
      noun.push_back("Port");
      noun.push_back("Ghost Ship");
      noun.push_back("Ghost");
      noun.push_back("Dipper");
      noun.push_back("Long Moorings");
      noun.push_back("Venus");
      noun.push_back("Sinker");
      noun2.push_back("the Bilge");
      //Touhou Fanon
      sign.push_back("Shipwreck");
      noun2.push_back("the Phantom Ship");
    }
    if (character=="Shou"){
      //Touhou Canon
      sign.push_back("Jeweled Pagoda");
      sign.push_back("Light Sign");
      sign.push_back("Buddhist Art");
      sign.push_back("Buddha's Light");
      sign.push_back("Tiger Sign");
      sign.push_back("Heaven Sign");
      sign.push_back("Treasure Sign");
      adj.push_back("Radiant");
      adj.push_back("Absolute");
      adj.push_back("Most Valuable");
      adj.push_back("Complete");
      adj.push_back("Hungry");
      adj.push_back("Scorched Earth");
      adj.push_back("Dazzling");
      noun.push_back("Treasure");
      noun.push_back("Treasure Gun");
      noun.push_back("Justice");
      noun.push_back("Aura");
      noun.push_back("Vajra");
      noun.push_back("Demon");
      noun.push_back("Clarification");
      noun.push_back("Tiger");
      noun.push_back("Mandala");
      noun.push_back("Gold");
      noun2.push_back("Perfect Buddhism");
      noun2.push_back("Justice");
      noun2.push_back("Purification");
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
    if (character=="Hatate"){
      //Touhou Canon
      sign.push_back("Reporting");
      sign.push_back("Continuous Shooting");
      sign.push_back("Far-sightedness");
      sign.push_back("Photography");
      adj.push_back("Reporting");
      adj.push_back("Rapid");
      adj.push_back("Tengu");
      adj.push_back("Full Panoramic");
      adj.push_back("Secluded");
      noun.push_back("Training");
      noun.push_back("Shot");
      noun.push_back("Psychography");
      noun.push_back("Paparazzi");
      //Touhou Fanon
      noun2.push_back("the Crow Tengu");
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
    if (character=="Kyouko"){
      //Touhou Canon
      sign.push_back("Echo Sign");
      sign.push_back("Mountain Echo");
      sign.push_back("Great Voice");
      sign.push_back("Scream");
      sign.push_back("Piercing Sound");
      sign.push_back("Sutra");
      adj.push_back("Mountain");
      adj.push_back("Power");
      adj.push_back("Long-Range");
      adj.push_back("Amplify");
      adj.push_back("Charged");
      adj.push_back("Primal");
      adj.push_back("Piercing");
      adj.push_back("Infinite");
      noun.push_back("Echo");
      noun.push_back("Echo Scramble");
      noun.push_back("Resonance");
      noun.push_back("Cry");
      noun.push_back("Yahoo!");
      noun.push_back("Demonstration");
      noun.push_back("Scream");
      noun.push_back("Circle");
      noun.push_back("Nianfo");
      //Touhou Fanon
      noun2.push_back("the Yamabiko");
    }
    if (character=="Yoshika"){
      //Touhou Canon
      sign.push_back("Recovery");
      sign.push_back("Poison Nail");
      sign.push_back("Desire Sign");
      adj.push_back("Poison");
      adj.push_back("Desire Spirit's");
      adj.push_back("Score Desire");
      adj.push_back("Undead");
      adj.push_back("Zombie");
      noun.push_back("Raze");
      noun.push_back("Murder");
      noun.push_back("Invitation");
      noun.push_back("Eater");
      noun.push_back("Murderer");
      noun.push_back("Claw");
      //Touhou Fanon
      sign.push_back("Consumption");//PhantomSong Seiga
      adj.push_back("Spirit");
      noun.push_back("Miasma");//PhantomSong Seiga
      noun.push_back("Feast");//PhantomSong Seiga
      noun2.push_back("the Jiangshi");
    }
    if (character=="Seiga"){
      //Touhou Canon
      sign.push_back("Evil Sign");
      sign.push_back("Demonify");
      sign.push_back("Necromancy");
      sign.push_back("Spirit Link");
      sign.push_back("Path Sign");
      sign.push_back("Hermit Arts");
      adj.push_back("Yang");
      adj.push_back("Guhun");
      adj.push_back("Zuohuo");
      adj.push_back("Tongling");
      adj.push_back("Corpse");
      adj.push_back("Fetal");
      adj.push_back("Excessive");
      adj.push_back("Wall");
      adj.push_back("Wall-Phasing");
      noun.push_back("Xiaogui");
      noun.push_back("Yegui");
      noun.push_back("Rumo");
      noun.push_back("Tongji");
      noun.push_back("Yoshika");
      noun.push_back("Movement");
      noun.push_back("Runner");
      noun.push_back("Wormhole");
      //Touhou Fanon
      sign.push_back("Corruption");//PhantomSong Seiga
      sign.push_back("Hermit Sign");
      adj.push_back("Wicked");//PhantomSong Seiga
      adj.push_back("Divine");//PhantomSong Seiga
      noun.push_back("Spirit");//PhantomSong Seiga
      noun2.push_back("the Evil Hermit");
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
  }
  
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
