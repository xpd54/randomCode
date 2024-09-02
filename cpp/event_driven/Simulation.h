#pragma once
#include "Events/Event.h"
#include <queue>
class Simulation {
public:
  Simulation() : time(0), eventQueue() {}
  void run();
  void scheduleEvent(Event *newEvent);
  size_t time;

protected:
  std::priority_queue<Event *, std::vector<Event *, std::allocator<Event *>>,
                      eventComparator>
      eventQueue;
};
