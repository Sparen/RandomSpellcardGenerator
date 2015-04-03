class Generator{
 private:
  template<typename T>
  T pick(std::vector<T> v);
 public:
  std::vector<std::string> sign;//includes the word "Sign" in it.
  std::vector<std::string> adj;
  std::vector<std::string> noun;
  std::vector<std::string> noun2;

  Generator(std::string character);
  Generator(Generator& old);
  ~Generator();
  std::string GenerateA1();
  std::string GenerateA2();
  std::string GenerateA3();
  void PrintA1();
  void PrintA2();
  void PrintA3();
};
