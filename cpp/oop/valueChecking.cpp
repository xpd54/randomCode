#include <iostream>
#include <string>
class Test {
private:
  int private_value;
  std::string private_string;

public:
  Test(std::string s) : private_string(s){};
  int public_value;
  void access_private() {
    std::cout << "Default private " << private_value << " -" << private_string
              << "-" << std::endl;
  }
  void access_public() {
    std::cout << "Default public " << public_value << std::endl;
  }
};

int main() {
  std::string input = "One Name";
  Test test("Two Name");
  test.access_private();
  test.access_public();
  return 0;
}