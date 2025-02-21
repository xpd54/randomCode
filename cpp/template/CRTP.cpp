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

void simulate_dynamic() {
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
  return;
}

// how we do static Polymorphism
/*
1.relationship between base and derived class
2.Base class defines and algo which get used by derived
3.Generic algo get costomize by derived calss
*/
struct Pure_Base {
  virtual ~Pure_Base(){};
  virtual void on_console() = 0;
};

template <typename T>
class Base : public Pure_Base {
 public:
  void on_console() { static_cast<T *>(this)->on_console(); }
};

class Base_Level_one : public Base<Base_Level_one> {
 public:
  Base_Level_one(string msg) : message(msg) {}
  void on_console() { std::cout << "bl " << message << '\n'; }

 private:
  string message;
};

class Derived : public Base<Derived> {
 public:
  Derived(int val) : m_holding_up(val * val) {}
  void on_console() { std::cout << "in " << m_holding_up << '\n'; }

 private:
  int m_holding_up;
};

void simulate_static() {
  std::vector<std::unique_ptr<Pure_Base>> holding;
  for (size_t i = 0; i < 10; ++i) {
    if (i % 2) {
      holding.emplace_back(
          std::make_unique<Base_Level_one>("This is a message"));
    } else {
      holding.emplace_back(std::make_unique<Derived>(i));
    }
  }

  std::for_each(holding.begin(), holding.end(),
                [](std::unique_ptr<Pure_Base> &val) { val->on_console(); });
  return;
}

int main() {
  simulate_dynamic();
  cout << "-----------------------------" << '\n';
  simulate_static();
  return 0;
}