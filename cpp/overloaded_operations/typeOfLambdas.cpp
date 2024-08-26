#include <iostream>
#include <map>
#include <string>
int add(int left, int right) { return left + right; }
auto mod = [](int left, int right) { return left % right; };
int main() {
  std::map<std::string, int (*)(int, int)> operation;
  operation.insert({"+", add});
  operation.insert({"%", mod});

  std::function<int(int, int)> op = operation["%"];
  std::cout << op(5, 2);
  return 0;
}
