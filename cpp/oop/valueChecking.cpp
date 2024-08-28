#include <iostream>
class Test {
private:
  int private_value;

public:
  int public_value;
  void access_private() {
    std::cout << "Default private " << private_value << std::endl;
  }
  void access_public() {
    std::cout << "Default public " << public_value << std::endl;
  }
};

int main() {
  Test test = Test();
  test.access_private();
  test.access_public();
  return 0;
}