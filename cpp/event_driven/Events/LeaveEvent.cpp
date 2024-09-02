#include "LeaveEvent.h"
#include "../StoreSimulation.h"
void LeaveEvent::processEvent() { StoreSimulation::get_instance().leave(size); }
