#pragma once
#include "../ZooAnimal.h"
class Bear : public virtual ZooAnimal {
public:
  Bear(bool cute, bool is_black);
  inline std::string get_color() { return color; };
  inline bool see_and_run() { return should_run; }
  inline virtual ~Bear() {}

private:
  bool adorable;
  bool should_run;
  std::string color;
};