#include <iostream>
class absInt {
public:
  int operator()(int val) { return val < 0 ? -val : val; }
};

int main() {
  int i = -42;
  absInt absObj;
  std::cout << absObj(i) << std::endl;
  return 0;
}