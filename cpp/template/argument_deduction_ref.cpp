#include "header.h"

// template can take only lvalue as & is part of function
template <typename T> void func(T &value) { std::cout << value << std::endl; }
// here value can be lvalue or rvalue both as const is part for function it self
// T can be T& which will make value as const int &&;
template <typename T> void func_const(const T &value) {
  std::cout << value << std::endl;
}
int main() {
  int i = 10;
  std::string value("value");
  const int ci = 20;
  func(i);
  func(ci);
  func(value);
  // func(3); //it would be an error as 3 is not a lvalue;
  func_const(i); // we can pass non
  func_const(ci);
  func_const(value);
  func_const(3);// it won't be an error as 3 is a rvalue;
  return 0;
}
