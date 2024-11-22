#include <iostream>
int main() {
  int ival;
  try {
    std::cin >> ival;
    std::cout << ival << std::endl;
  } catch (...) {
    std::cout << "Was an error" << std::endl;
  }
  return 0;
}