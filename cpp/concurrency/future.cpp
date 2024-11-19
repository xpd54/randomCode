#include <future>
#include <iostream>

int square(int value) { return value * value; }

int main() {
  std::future<int> asyncFunction = std::async(&square, 12);
  for (int i = 0; i < 10; ++i) {
    std::cout << square(i) << '\n';
  }

  int result = asyncFunction.get();
  std::cout << "result is:- " << result << '\n';

  return 0;
}