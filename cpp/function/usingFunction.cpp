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