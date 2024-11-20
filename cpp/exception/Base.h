#pragma once
#include <iostream>
#include <string>
class Base {
public:
  Base(int val) : value(val) {}
  int get_value() { return value; }
  ~Base() { std::cout << "Base Destructor " << value << " " << &value << '\n'; }

private:
  int value;
};

class Derived : public Base {
public:
  Derived(int val, std::string pat) : Base(val), pattern(pat) {}
  std::string get_pattern() { return pattern; }
  ~Derived() {
    std::cout << "Derived Destructor " << pattern << " " << &pattern << '\n';
  }

private:
  std::string pattern;
};
