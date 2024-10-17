#include "header.h"

template <typename T> T fobj(T val1, T val2) { return val1; };
template <typename T> T fref(const T &val1, const T &val2) { return val1; };

// normal conversion for ordinary argument
template <typename T> std::ostream &print(std::ostream &os, const T &obj) {
  return os << obj << std::endl;
}

int main() {
  std::string s1("a value");
  const std::string s2("another value");
  fobj(s1, s2);

  // instantiates print(ostream&, int)
  print(std::cout, 32);
  // uses print(ostream &, int); converts f to ostream
  std::ofstream f("output");
  // looks like
  // print(static_cast<std::basic_ostream<char>&>(f), 10);
  print(f, 10);
  return 0;
}
