#include <iostream>
#include <map>
#include <string>
int add(int i, int j) { return i + j; }
// global variable not ideal but it's for learning
auto mod = [](int i, int j) { return i % j; };
//
struct divide {
  int operator()(int denominator, int divisor) { return denominator / divisor; }
};

// let's make a map for arthemetic function
void makingMapAndUsing() {
  std::map<std::string, int (*)(int, int)> binops;
  binops.insert({"+", add}); // can insert as call signature match
  binops.insert({"%", mod});
  auto op = binops["%"];
  std::cout << op(5, 2) << "\n";
}

int main() {
  makingMapAndUsing();
  return 0;
}