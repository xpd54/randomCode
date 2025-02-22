#include <__algorithm/remove.h>

#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Subscriber {
 public:
  Subscriber(const string &name) : subscriber_name(name) {}

  void got_update(const std::string &msg) {
    cout << subscriber_name << ":- " << msg << '\n';
  }
  bool operator==(const Subscriber &other) {
    return subscriber_name == other.subscriber_name;
  }

 private:
  string subscriber_name;
};

class Publicer {
 public:
  void subscribe(std::weak_ptr<Subscriber> subscriber) {
    subscribers.push_back(subscriber);
  }

  void unsubscribe(std::weak_ptr<Subscriber> subscriber) {
    subscribers.erase(
        std::remove_if(subscribers.begin(), subscribers.end(),
                       [&](const weak_ptr<Subscriber> &s) {
                         if (auto shared_s = s.lock()) {
                           if (auto shared_sub = subscriber.lock()) {
                             return shared_s == shared_sub;
                           }
                         }
                         return true;
                       }),
        subscribers.end());
  }

  void notify(const std::string &msg) {
    for (auto &weak_subscriber : subscribers) {
      if (auto subscriber = weak_subscriber.lock()) {
        subscriber->got_update(msg);
      }
    }
  }

 private:
  std::vector<std::weak_ptr<Subscriber>> subscribers;
};

/*As second will go out of scope it won't console out*/
void add_second(Publicer &pub) {
  auto second = make_shared<Subscriber>("second");
  pub.subscribe(second);
  return;
}

int main() {
  Publicer pub;
  auto first = make_shared<Subscriber>("first");
  auto third = make_shared<Subscriber>("third");
  auto fourth = make_shared<Subscriber>("fourth");
  pub.subscribe(first);
  pub.subscribe(third);
  pub.subscribe(fourth);
  add_second(pub);
  pub.notify("hello my people ");
}