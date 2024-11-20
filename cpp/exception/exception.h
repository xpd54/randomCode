#pragma once
#include "Base.h"
#include <iostream>
#include <memory>

inline void print_pattern(std::shared_ptr<Derived> derived) noexcept(false) {
  Derived something(3, "something");
  std::cout << "Shared count " << derived.use_count() << '\n';
  if (!(derived->get_value() % 2)) {
    Derived pointer = *derived;
    throw pointer;
  } else {
    Base pointer = *derived;
    throw pointer;
  }
}
