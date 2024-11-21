#pragma once
#include "../../Endangered/Endangered.h"
#include "../Bear/Bear.h"
#include "../Racoon/Racoon.h"
#include <cstdint>

class Panda : public Racoon, public Bear, public Endangered {
public:
  Panda(std::string origin);
  inline bool see_and_run() { return Racoon::see_and_run(); }
  uint16_t get_max_weight() const;
};