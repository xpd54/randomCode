#include <iostream>
#include <string>
class BaseTest {
public:
  int value;
};
class Test {
private:
  int private_value;
  BaseTest test;
  std::string private_string;

public:
  Test(std::string s) : private_string(s){};
  int public_value;
  void access_private() {
    // Here test.value would have default 0 value
    std::cout << "Default private " << private_value << " -" << private_string
              << "-"
              << " " << test.value << std::endl;
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

  // Here value would have garbage value 
  BaseTest base_test;
  std::cout << base_test.value << std::endl;
  return 0;
}