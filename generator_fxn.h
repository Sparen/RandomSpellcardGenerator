#ifndef GENERATOR_FXN_H
#define GENERATOR_FXN_H

#include <vector>
#include <string>
#include <cstdlib>

class Generator{
 private:
  template<typename T>
  T pick(const std::vector<T> &v) {
    return v[rand() % v.size()];
  }
  std::string GenerateA5H() {
    int roll = rand() & 7;
    return
      (roll < 3) ? pick(noun) :
      (roll < 5) ? GenerateB1() :
      (roll < 7) ? GenerateB2() :
      GenerateB3();
  }
 public:
  std::vector<std::string> sign;//includes the word "Sign" in it.
  std::vector<std::string> adj;
  std::vector<std::string> noun;
  std::vector<std::string> noun2;
  std::vector<std::string> formatterList;

  Generator(const std::set<std::string> &characters);
  std::string GenerateB1();
  std::string GenerateB2();
  std::string GenerateB3();
  std::string GenerateA1();
  std::string GenerateA2();
  std::string GenerateA3();
  std::string GenerateA4();
  std::string GenerateA5();
  void PrintA1();
  void PrintA2();
  void PrintA3();
  void PrintA4();
  void PrintA5();
};

#endif // GENERATOR_FXN_H