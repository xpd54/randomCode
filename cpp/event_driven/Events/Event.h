#pragma once
#include <iostream>
class Event {
public:
  Event(size_t t) : time(t) {}
  virtual void processEvent() = 0;
  size_t time;
};

struct eventComparator {
  bool operator()(const Event *left, const Event *right) const {
    return left->time > right->time;
  }
};
