#include <iostream>
#include <string>
template <typename T> using twin = std::pair<T, T>;
template <typename T> using kids = std::pair<T, unsigned>;
int main() {
  twin<std::string> authors;
  authors = {"hello", "world"};
  std::cout << authors.first << " " << authors.second << std::endl;
  kids<std::string> kid = {"gungun", 10};
  std::cout << kid.first << " " << kid.second << std::endl;
  return 0;
}
