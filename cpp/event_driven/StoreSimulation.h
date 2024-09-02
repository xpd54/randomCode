#pragma once
#include "Simulation.h"

class StoreSimulation : public Simulation {
public:
  StoreSimulation() : Simulation(), freeChairs(35), profit(0.0) {}

  bool canSeat(size_t numberOfPeople);
  void order(size_t numberOfScoops);
  void leave(size_t numberOfPeople);
  size_t freeChairs;
  double profit;
};
