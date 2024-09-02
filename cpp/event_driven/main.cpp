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
    StoreSimulation::get_instance().scheduleEvent(new ArriveEvent(t, 1 + 3));
  }

  StoreSimulation::get_instance().run();

  std::cout << "Total Profits" << StoreSimulation::get_instance().profit << "\n"
            << "Enf of ice create store"
            << "\n";
  return 0;
}
