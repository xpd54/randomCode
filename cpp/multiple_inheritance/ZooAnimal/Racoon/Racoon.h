#pragma once
#include "../ZooAnimal.h"
class Racoon : virtual public ZooAnimal {
public:
  Racoon(bool cute, bool origin);
  inline bool cuddle() const { return adorable; }
  inline bool see_and_run() { return adorable; }

private:
  bool adorable;
  bool from_japan;
};