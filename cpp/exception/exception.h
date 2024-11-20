#pragma once
#include "Base.h"
#include <iostream>

inline void print_pattern(Derived *derived) noexcept(false) {
  if (!(derived->get_value() % 2)) {
    Derived pointer = *derived;
    throw pointer;
  } else {
    Base pointer = *derived;
    throw pointer;
  }
}
