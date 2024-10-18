#include "header.h"

template <typename It> auto fcn(It beg, It end) -> decltype(*beg) {
  ++beg;
  return *beg;
}

template <typename It>
auto fcn_copy(It beg, It end) ->
    typename std::remove_reference<decltype(*beg)>::type {
  ++beg;
  return *beg;
}

template <typename It> auto fcn_legal(It beg, It end) -> decltype(*beg + 0) {
  return *beg;
}

int main() {
  std::vector<int> list = {1, 2, 3, 4};
  auto &second_it = fcn(list.begin(), list.end());
  std::cout << second_it << std::endl;
  std::vector<std::string> list_string = {"hello", "hi", "ni hao", "jaushan",
                                          "namaste"};
  auto &second_greeting = fcn(list_string.begin(), list_string.end());
  std::cout << second_greeting << std::endl;
  second_greeting = "konichiwa";
  // this is a reference return which will change the value of list member;
  auto &second_greeting_changed = fcn(list_string.begin(), list_string.end());
  std::cout << second_greeting_changed << std::endl;

  auto second_greeting_copy = fcn_copy(list_string.begin(), list_string.end());
  std::cout << second_greeting_copy << std::endl;
  // as it was a copy we can't change the value from greeting copy
  second_greeting_copy = "tu da lu";

  auto &second_greeting_copy_changed =
      fcn(list_string.begin(), list_string.end());
  std::cout << second_greeting_copy_changed << std::endl;

  // Test Legal template
  // It's legal but only for Int we can't hold string in this case cause operator+ is not valid;
  auto second = fcn_legal(list.begin(), list.end());
  std::cout << second << std::endl;

  return 0;
}
