#include <iostream>
#include <memory>
#include <vector>

std::vector<int> *vector_factory() { return new std::vector<int>(); }

template <typename T> void set_value(T factory) {
  int value;
  while (std::cin >> value) {
    factory->push_back(value);
  }
}

template <typename T> void print_value(T input) {
  for (auto value : *input) {
    std::cout << value << std::endl;
  }
}

std::shared_ptr<std::vector<int>> vector_factory_smart() {
  return std::make_shared<std::vector<int>>();
}

int main() {
  std::vector<int> *input = vector_factory();
  set_value(input);
  print_value(input);
  delete input;
  std::shared_ptr<std::vector<int>> smart_intput = vector_factory_smart();
  set_value(smart_intput);
  print_value(smart_intput);
  return 0;
}