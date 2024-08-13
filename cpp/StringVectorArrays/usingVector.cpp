#include <iostream>
#include <string>
#include <vector>

void print_string_vector(std::vector<std::string> &input) {
  for (auto &str : input) {
    std::cout << str << std::endl;
  }
}

void vector_of_vector() {
  std::vector<std::vector<std::string>> holding;
  std::vector<std::string> first = {"Hello", "World"};

  std::vector<std::string> second;
  second.push_back("Second");
  second.push_back("Hand");
  holding = {first, second};

  for (auto &vec : holding) {
    print_string_vector(vec);
  }
}

void value_initialize() {
  std::vector<int> ivec(10, 89);
  std::vector<std::string> svec(20, "Pedro");
  for (auto &ref : svec) {
    std::cout << ref << std::endl;
  }
  for (auto &ref : ivec) {
    std::cout << ref << std::endl;
  }
}

int main() {
  value_initialize();
  return 0;
}