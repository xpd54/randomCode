#include <iostream>
template <typename T> inline T min(const T &left, const T &right) {
  return left > right ? right : left;
}

int main() {
  int value = min(40, 34);
  std::cout << "min value:- " << value << std::endl;
  return 0;
}
