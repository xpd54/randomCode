#include "Panda.h"
#include <cstdint>
Panda::Panda(std::string origin)
    : ZooAnimal("Panda", origin, 500), Racoon(true, false), Bear(true, true),
      Endangered(State::Alarming, "China") {}
uint16_t Panda::get_max_weight() const { return 2000; }