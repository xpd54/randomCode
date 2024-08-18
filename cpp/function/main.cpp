#include "usingFunction.h"
#include <iostream>
#include <vector>
int main() {
  std::string s1("Hello World");
  get_val(s1, 0) = 'A';
  std::cout << s1 << std::endl;

  std::cout << factorial(5) << std::endl;

  std::vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 89};
  print_vector(input);
  return 0;
}