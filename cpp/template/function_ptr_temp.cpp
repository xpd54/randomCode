#include "header.h"
template <typename T> int compare(const T &left, const T &right) {
  return left > right ? 1 : -1;
}

int main() {
  int (*pf)(const int &, const int &) = compare;
  std::cout << pf(10, 20) << std::endl;

  int (*pf_string)(const std::string &, const std::string &) = compare;
  std::cout << pf_string("nihao", "hello") << std::endl;
  return 0;
}
