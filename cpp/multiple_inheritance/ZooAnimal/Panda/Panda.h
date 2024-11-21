#pragma once
#include "../../Endangered/Endangered.h"
#include "../Bear/Bear.h"
#include "../Racoon/Racoon.h"
#include <cstdint>

class Panda : public Bear, public Racoon, public Endangered {
public:
  Panda(std::string origin);
  uint16_t get_max_weight() const;
};