#include "StrBlob.h"
#include <cstddef>
#include <iostream>

int main() {
  StrBlob blob;
  blob.push_back("hello");
  blob.push_back("world");

  std::cout << blob.size() << std::endl;
  std::cout << blob.front() << std::endl;
  std::cout << blob.back() << std::endl;
  return 0;
}