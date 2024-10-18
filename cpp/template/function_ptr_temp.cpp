#include "header.h"
template <typename T> int compare(const T &left, const T &right) {
  return left > right ? 1 : -1;
}

void func(int (*pf)(const std::string &, const std::string &)) {
  std::cout << "Inside a string compare";
  std::cout << " " << pf("left", "right") << std::endl;
}

void func(int (*pf)(const int &, const int &)) {
  std::cout << "Inside a int compare";
  std::cout << " " << pf(1, 0) << std::endl;
}
int main() {
  int (*pf)(const int &, const int &) = compare;
  std::cout << pf(10, 20) << std::endl;

  int (*pf_string)(const std::string &, const std::string &) = compare;
  std::cout << pf_string("nihao", "hello") << std::endl;

  func(compare<std::string>);
  return 0;
}
