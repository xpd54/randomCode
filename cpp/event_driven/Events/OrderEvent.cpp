#include "OrderEvent.h"
#include "../StoreSimulation.h"
#include "LeaveEvent.h"
void OrderEvent::processEvent() {
  for (size_t i = 0; i < size; ++i) {
    // each person order some number of scoops
    theSimulation.order(3);
  }
  // Then we scheduel the leave event
  theSimulation.scheduleEvent(new LeaveEvent(time + 1 + 5, size));
}
