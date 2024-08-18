#include "usingFunction.h"
#include <iostream>
/* using reference of value makes argument to accpet only lvalue. Which mean
 * passing rvalue or literal here will throw error.
 */
int printFactorial(int &value) {
  int rnt = 1;
  while (value > 1) {
    // postfix returns original value but do increment/decrement
    rnt *= value--;
  }
  return rnt;
}

int count_calling() {
  static int value = 0;
  /* it returns 0 for first call because postfix operator allows to returns
  original value than apply increment;
 */
  return value++;
}

void printing_with_two_pointer() {
  int i = 10;
  int *p, *q;
  p = &i;
  q = p;
  std::cout << i << " " << *p << " " << *q << std::endl;
  *q = 20;
  std::cout << i << " " << *p << " " << *q << std::endl;
}

void sum_of_value(const int &left, const int &right, int &sum) {
  sum = left + right;
}

void print_c_style_char_array(const char *char_array) {
  if (char_array) {
    while (*char_array)
      std::cout << *char_array++;
    std::cout << std::endl;
  }
}

void print_array_with_iterator(const int *begin, const int *end) {
  while (begin != end)
    std::cout << *begin++ << std::endl;
}

void error_msg(std::initializer_list<std::string> il) {
  for (auto beg = il.begin(); beg != il.end(); ++beg) {
    std::cout << *beg << " ";
  }
  std::cout << std::endl;
}

std::string &shorter_string(std::string &s1, std::string &s2) {
  return s1.size() <= s2.size() ? s1 : s2;
}

char &get_val(std::string &str, std::string::size_type ix) { return str[ix]; }

int factorial(int val) {
  if (val > 1)
    return factorial(val - 1) * val;
  return 1;
}

void print_vector(const std::vector<int> &input, size_t size) {
  if (size >= input.size()) {
    return;
  }
  std::cout << input[size] << " ";
  print_vector(input, size + 1);
}