#pragma once
#include "../ZooAnimal.h"
class Bear : public ZooAnimal {
  Bear(bool cute, bool origin);
  inline std::string get_color() { return color; };

private:
  bool adorable;
  bool should_run;
  std::string color;
};