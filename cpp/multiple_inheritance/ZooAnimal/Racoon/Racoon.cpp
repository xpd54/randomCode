#include "Racoon.h"

Racoon::Racoon(bool cute, bool origin)
    : ZooAnimal("Racoon", (origin ? ("Japan") : "US"), 10), adorable(cute),
      from_japan(origin){};