#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <memory>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// how we do dynamic polymorphism
class Base_Dynamic {
 public:
  virtual void on_console() {}
};

class Base_Level : public Base_Dynamic {
 public:
  Base_Level(string msg = "hello world") : message(msg) {}
  void on_console() override { std::cout << "bl " << message << '\n'; }

 private:
  string message;
};

class Inherit : public Base_Level {
 public:
  Inherit(int val) : m_holding_up(val * val) {}
  void on_console() override { std::cout << "in " << m_holding_up << '\n'; }

 private:
  int m_holding_up;
};

int main() {
  std::vector<std::unique_ptr<Base_Dynamic>> holding;
  for (size_t i = 0; i < 10; ++i) {
    if (i % 2) {
      holding.emplace_back(std::make_unique<Base_Level>("This is a message"));
    } else {
      holding.emplace_back(std::make_unique<Inherit>(i));
    }
  }

  std::for_each(holding.begin(), holding.end(),
                [](std::unique_ptr<Base_Dynamic> &val) { val->on_console(); });
  return 0;
}