#include "OrderEvent.h"
#include "../StoreSimulation.h"
#include "LeaveEvent.h"
void OrderEvent::processEvent() {
  for (size_t i = 0; i < size; ++i) {
    // each person order some number of scoops
    StoreSimulation::get_instance().order(3);
  }
  // Then we scheduel the leave event
  StoreSimulation::get_instance().scheduleEvent(
      new LeaveEvent(time + 1 + 5, size));
}
