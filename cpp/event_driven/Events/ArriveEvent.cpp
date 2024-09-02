#include "ArriveEvent.h"
#include "../StoreSimulation.h"
#include "OrderEvent.h"

void ArriveEvent::processEvent() {
  if (StoreSimulation::get_instance().canSeat(size))
    StoreSimulation::get_instance().scheduleEvent(
        new OrderEvent(time + 1 + 3, size));
}
