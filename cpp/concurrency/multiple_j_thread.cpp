// well clang haven't implemented jthread for c++20 good bye
#include <iostream>
#include <thread>
#include <vector>
int main() {
  auto lambda_exicution = [](int value) {
    std::cout << "Hello from thread:- " << std::this_thread::get_id() << '\n';
    std::cout << "Argument:- " << value << '\n';
  };

  std::vector<std::jthread> threads;
  threads.reserve(10);
  for (int i = 0; i < 10; ++i) {
    threads.push_back(std::jthread(lambda_exicution, i));
  }

  return 0;
}