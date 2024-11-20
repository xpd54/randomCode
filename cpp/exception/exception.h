#pragma once
#include "Base.h"
#include <iostream>

inline void print_pattern(Derived *derived) noexcept(false) {
  std::cout << derived->get_pattern() << '\n';
  if (!(derived->get_value() % 2)) {
    Base *pointer = derived;
    throw pointer;
  }
}
