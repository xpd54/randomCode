#pragma once
#include <string>
class Base {
public:
  Base(int val) : value(val) {}
  int get_value() { return value; }

private:
  int value;
};

class Derived : public Base {
public:
  Derived(int val, std::string pat) : Base(val), pattern(pat) {}
  std::string get_pattern() { return pattern; }

private:
  std::string pattern;
};
