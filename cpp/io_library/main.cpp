#include <iostream>
int main() {
  int ival;
  try {
    std::cin >> ival;
    std::cout << ival << std::endl;
  } catch (...) {
    std::cout << "Was an error" << std::endl;
  }

  int val;
  // If first error get thrown in stream.
  /*Means if we put char rather than int in first input. Cause this istream had
   * error for input it will throw error for next istream as well. And because
   * of that it will print stream error rather than taking another input for
   * next value.*/
  if (std::cin >> val) {
    std::cout << "Second value:- " << val << std::endl;
  } else {
    std::cout << "Stream had an error" << '\n';
  }
  return 0;
}