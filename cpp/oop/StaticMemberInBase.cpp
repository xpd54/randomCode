#include <iostream>
class Base {
public:
  static void statmem();
};

void Base::statmem() { std::cout << "Statmem was called in Base" << std::endl; }

class Derived : public Base {
  void f(const Derived &);
};

void Derived::f(const Derived &derived_obj) {
  Base::statmem();    // That's ok Base defines Statmem()
  Derived::statmem(); // Derived inherits statmem();

  derived_obj.statmem(); // access through object
  statmem();             // access through this object
}

void createObjAndCallMethod() {
  Base base;
  Derived derived;
  base.statmem();
  derived.statmem();
}

int main() {
  createObjAndCallMethod();
  return 0;
}