class Generator{
 private:
 public:
  std::vector<std::string> sign;//includes the word "Sign" in it.
  std::vector<std::string> adj;
  std::vector<std::string> noun;
  std::vector<std::string> action;

  Generator(std::string character);
  Generator(Generator& old);
  ~Generator();
  void GenerateA1();
  void GenerateA2();
};
