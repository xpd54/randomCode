#include <iostream>
#include <vector>
void using_postfix() {
  int i = 0;
  int j = 0;
  // prefix return incremented value without making a copy.
  std::cout << ++i << "\n";
  // post fix returns previous value and it's make a copy of incremented value
  std::cout << j++ << "\n";

  /*reccomendation is to use prefix all the time. */
  std::cout << i << " " << j << "\n";
}

void using_prefix_postfix_in_vector() {
  std::vector<int> input = {1, 2, 3, 4, 5, 6, 7};
  std::vector<int>::iterator it = input.begin();
  std::vector<int>::iterator copy_it = input.begin();
  std::cout << *(it++) << std::endl;
  std::cout << *copy_it << std::endl;
}

void using_type_cast() {
  int i = 10, j = 3;
  double div = static_cast<float>(i) / j;
  std::cout << div << std::endl;
}
int main() {
  using_type_cast();
  return 0;
}