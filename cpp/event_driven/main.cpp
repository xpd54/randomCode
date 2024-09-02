#include <iostream>
#include <queue>

#include "Events/ArriveEvent.h"
#include "Events/LeaveEvent.h"
#include "Events/OrderEvent.h"
#include "StoreSimulation.h"

int main() {
  std::cout << "Ice Cream Store simulation"
            << "\n";
  for (size_t t = 0; t < 20; ++t) {
    std::cout << "pumping queue with event" << t << "\n";
    theSimulation.scheduleEvent(new ArriveEvent(t, 1 + 3));
  }

  theSimulation.run();

  std::cout << "Total Profits" << theSimulation.profit << "\n"
            << "Enf of ice create store"
            << "\n";
  return 0;
}
