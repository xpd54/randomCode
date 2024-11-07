#include "Blob.cpp"
#include "compare.cpp"
#include <iostream>
#include <string>

extern template class Blob<std::string>;
template int compare(const int &, const int &);

int main() {
  // as it's extern instantiation will appear elsewhere
  Blob<std::string> sa1, sa2;
  Blob<int> a1 = 12;
  Blob<int> a2(a1);
  return 0;
}
