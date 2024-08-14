#include "usingFunction.h"

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

