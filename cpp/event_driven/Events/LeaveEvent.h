#pragma once
#include "Event.h"
class LeaveEvent : public Event {
public:
  LeaveEvent(size_t time, size_t groupSize) : Event(time), size(groupSize) {}
  virtual void processEvent() override;

private:
  size_t size;
};
