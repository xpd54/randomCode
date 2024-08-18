#include "usingFunction.h"
#include <iostream>
#include <vector>
int main() {
  std::string s1("Hello World");
  get_val(s1, 0) = 'A';
  std::cout << s1 << std::endl;

  std::cout << factorial(5) << std::endl;
  return 0;
}