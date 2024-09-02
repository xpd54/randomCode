#pragma once
#include "Simulation.h"

class StoreSimulation : public Simulation {
private:
protected:
  StoreSimulation() : Simulation(), freeChairs(35), profit(0.0) {}

public:
  static StoreSimulation &get_instance() {
    static StoreSimulation instance;
    return instance;
  }
  // Copy constructor
  StoreSimulation(const StoreSimulation &) = delete;
  // Copy assignment
  void operator=(const StoreSimulation &) = delete;
  // move constructor
  StoreSimulation(StoreSimulation &&) = delete;
  // move assignment
  void operator=(StoreSimulation &&) = delete;

  bool canSeat(size_t numberOfPeople);
  void order(size_t numberOfScoops);
  void leave(size_t numberOfPeople);
  size_t freeChairs;
  double profit;
};

