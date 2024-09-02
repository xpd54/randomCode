#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
class Event {
public:
  Event(const std::string &_message) : message(_message) {}
  std::string getMessage() const { return message; };

private:
  std::string message;
};

// observer interface
class Observer {
public:
  virtual void onEvent(const Event &event) = 0;
};

// Concrete observer
class ConcreteObserver : public Observer {
public:
  void onEvent(const Event &event) override {
    std::cout << "Received event: " << event.getMessage() << std::endl;
  }
};

class EventManager {
public:
  void subscribe(Observer *observer) { observers.push_back(observer); }
  void unsubscribe(Observer *observer) {
    auto it = std::find(observers.begin(), observers.end(), observer);
    observers.erase(it);
  }

  void notify(const Event &event) {
    for (auto &observer : observers) {
      observer->onEvent(event);
    }
  }

private:
  std::vector<Observer *> observers;
};

int main() {
  EventManager eventManager;

  ConcreteObserver observer1;
  ConcreteObserver observer2;

  // Subscribe observers
  /* dynamic binding of Observer where concrete Observer can be passed in
   * Observer parameter */
  eventManager.subscribe(&observer1);
  eventManager.subscribe(&observer2);

  // Emit an event
  Event event("Hello, World!");
  eventManager.notify(event);

  // Unsubscribe observer1
  eventManager.unsubscribe(&observer1);

  // Emit another event
  Event event2("Goodbye, World!");
  eventManager.notify(event2);

  return 0;
}
