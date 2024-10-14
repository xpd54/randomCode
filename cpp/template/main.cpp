#include "Data.cpp"
#include "utility.cpp"
#include <iostream>
int main() {
  const Data data;
  const Data holding(5, 10);
  std::cout << "---> " << compare(data, holding) << "\n";
  return 0;
}
