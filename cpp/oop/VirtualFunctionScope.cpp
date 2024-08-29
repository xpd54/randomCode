#include <iostream>

class Base {
public:
  virtual int fcn() { return 10; }
};

class D1 : public Base {
public:
  int fcn(int value) {
    std::cout << value << std::endl;
    return 5;
  }
  virtual void f2() { std::cout << "nothng" << std::endl; }
};

class D2 : public D1 {

public:
  int fcn(int value) { return 6; }
  int fcn() override {
    std::cout << "returning from non base" << std::endl;
    return 0;
  }
  void f2() override { std::cout << "nothing from D2" << std::endl; }
};

int main() {
  Base base;
  D1 d1;
  D2 d2;

  std::cout << base.fcn() << std::endl;
  // d1 hides the fcn();
  std::cout << d1.fcn(1) << std::endl;
  // can access hidden one
  std::cout << d1.Base::fcn() << std::endl;

  std::cout << d2.fcn() << std::endl;
  std::cout << d2.fcn(1) << std::endl;
  std::cout << d2.D1::fcn(1) << std::endl;
  d2.f2();

  return 0;
}