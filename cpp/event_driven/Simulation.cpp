#include "Simulation.h"
void Simulation::run() {
  while (!eventQueue.empty()) {
    Event *nextEvent = eventQueue.top();
    eventQueue.pop();
    time = nextEvent->time;
    nextEvent->processEvent();
    delete nextEvent;
  }
}

void Simulation::scheduleEvent(Event *newEvent) { eventQueue.push(newEvent); }
