#pragma once
#include "Event.h"

class ArriveEvent: public Event {
  public:
  ArriveEvent(size_t time, size_t groupSize): Event(time), size(groupSize) {}
  virtual void processEvent() override;
  private:
    size_t size;
};
