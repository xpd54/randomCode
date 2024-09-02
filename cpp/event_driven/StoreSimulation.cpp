#include "StoreSimulation.h"
#include <iostream>
bool StoreSimulation::canSeat(size_t numberOfPeople) {
  std::cout << "Time: " << time;
  std::cout << " group of " << numberOfPeople << " customers arrives";

  if (numberOfPeople < freeChairs) {
    std::cout << " is seated \n";
    freeChairs -= numberOfPeople;
    return true;
  } else {
    std::cout << " no room, they leave\n";
    return false;
  }
}

void StoreSimulation::order(size_t numberOfScoops) {
  std::cout << "Time: " << time << " serviced order for " << numberOfScoops
            << "\n";
  profit += 0.35 * numberOfScoops;
}

void StoreSimulation::leave(size_t numberOfPeople) {
  std::cout << "Time: " << time << " group of size" << numberOfPeople
            << " leaves"
            << "\n";
  freeChairs += numberOfPeople;
}
