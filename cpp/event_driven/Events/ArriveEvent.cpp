#include "ArriveEvent.h"
#include "../StoreSimulation.h"
#include "OrderEvent.h"

void ArriveEvent::processEvent() {
  if (theSimulation.canSeat(size))
    theSimulation.scheduleEvent(new OrderEvent(time + 1 + 3, size));
}
