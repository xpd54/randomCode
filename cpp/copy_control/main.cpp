#include <iostream>
#include <set>
#include <string>

class Holding {
private:
  std::set<std::string> packet;
  std::string name;

public:
  Holding(std::string _name_) : name(_name_) {}
  void save(const std::string &value) { packet.insert(value); }

  void print() {
    std::cout << name << " ";
    for (auto &value : packet)
      std::cout << value << " ";
    std::cout << std::endl;
  }
};

void add_and_print_holding() {
  Holding holding("Hello");
  const std::string message("World");
  const std::string address("Hong Kong");
  holding.save(message);
  holding.save(address);
  holding.print();
}

int main() {
  add_and_print_holding();
  return 0;
}