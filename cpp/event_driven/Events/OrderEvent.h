#pragma once
#include "Events/Event.h"
class OrderEvent : public Event {
public:
  OrderEvent(size_t time, size_t groupSize) : Event(time), size(groupSize) {}
  virtual void processEvent() override;

private:
  size_t size;
};
