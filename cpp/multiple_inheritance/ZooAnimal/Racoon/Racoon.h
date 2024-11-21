#pragma once
#include "../ZooAnimal.h"
class Racoon : public ZooAnimal {
public:
  Racoon(bool cute, bool origin);
  inline bool cuddle() const { return adorable; }

private:
  bool adorable;
  bool from_japan;
};