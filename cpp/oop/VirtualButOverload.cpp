#include <iostream>

struct B {
  virtual void f1(int value) const;
  virtual void f2();
  void f3();
};

void B::f1(int value) const {
  std::cout << "f1 of Base has been called " << value << std::endl;
}

void B::f2() { std::cout << "f2 of Base has been called" << std::endl; }
void B::f3() { std::cout << "f3 of Base has been called" << std::endl; }

struct D1 : B {
  void f1(int) const override;
  void f2() override;
  void f2(int value_f2);
  void f3();
  void f4();
};

void D1::f1(int value) const {
  std::cout << "f1 is getting called from Derived " << value << std::endl;
}

void D1::f2() {
  std::cout << "f2 is getting called from Derived but no virtual" << std::endl;
}

void D1::f2(int value_f2) {
  std::cout << "f2 which is no virtual but pure overloaded function "
            << value_f2 << std::endl;
};

void D1::f3() { std::cout << "Just f3 getting called " << std::endl; };

void D1::f4() {
  std::cout << "No overrid here just plan old method for D1" << std::endl;
}

int main() {
  D1 d;
  d.f1(10);
  d.f2(10);
  d.f3();
  d.f4();

  B b;
  b.f1(5);
  b.f2();
  b.f3();

  b = d;
  b.f1(3);
  return 0;
}