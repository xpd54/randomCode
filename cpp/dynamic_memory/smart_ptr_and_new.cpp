#include <iostream>
#include <memory>

int main() {
  auto deleting_lambda = [&]() { std::cout << "Deleteing as been called out"; };

  std::shared_ptr<int> value(new int(10));
  std::cout << *value << std::endl;
}