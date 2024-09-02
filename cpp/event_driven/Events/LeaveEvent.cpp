#include "LeaveEvent.h"
#include "../StoreSimulation.h"
void LeaveEvent::processEvent() { theSimulation.leave(size); }
