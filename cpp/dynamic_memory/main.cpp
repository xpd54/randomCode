#include "StrBlob.h"
#include <cstddef>
#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<StrBlob> p_blob = std::make_shared<StrBlob>();
  p_blob->push_back("value");
  StrBlob blob;
  {
    StrBlob b2 = {"a", "an", "the"};
    blob = b2;
    b2.push_back("about");
  }
  std::cout << blob.size() << " " << std::endl;

  int const *pci = new const int(2021);
  int const *copypci;
  copypci = pci;
  pci = new const int(23);
  // delete pci;
  std::cout << &(*copypci) << std::endl;
  std::cout << &pci << std::endl;
  std::cout << &(*pci) << std::endl;
  std::cout << pci << std::endl;
  return 0;
}