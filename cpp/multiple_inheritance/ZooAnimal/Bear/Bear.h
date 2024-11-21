#pragma once
#include "../ZooAnimal.h"
class Bear : public virtual ZooAnimal {
public:
  Bear(bool cute, bool is_black);
  inline std::string get_color() { return color; };

private:
  bool adorable;
  bool should_run;
  std::string color;
};