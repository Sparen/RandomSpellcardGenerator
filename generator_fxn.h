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
 public:
  std::vector<std::string> sign;//includes the word "Sign" in it.
  std::vector<std::string> adj;
  std::vector<std::string> noun;
  std::vector<std::string> noun2;

  Generator(const std::set<std::string> &characters);
  std::string GenerateB1();
  std::string GenerateB2();
  std::string GenerateB3();
  std::string GenerateA1();
  std::string GenerateA2();
  std::string GenerateA3();
  std::string GenerateA4();
  void PrintA1();
  void PrintA2();
  void PrintA3();
  void PrintA4();
};

#endif // GENERATOR_FXN_H