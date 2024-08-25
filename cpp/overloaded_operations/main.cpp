#include <iostream>
#include <string>
class absInt {
public:
  int operator()(int val) { return val < 0 ? -val : val; }
};

class PrintString {
public:
  PrintString(std::ostream &o = std::cout, char c = ' ') : os(o), sep(c) {}
  PrintString(char c) : PrintString(std::cout, c) {}
  /* doesn't return anythign but have input string and print the string with
   * seperator which was defined */
  void operator()(const std::string &s) const { os << s << sep << " "; }

private:
  std::ostream &os; // stream on which to write
  char sep;         // character to print after each output;
};

int main() {
  int i = -42;
  absInt absObj;
  std::cout << absObj(i) << std::endl;
  std::string input("The date is 25th Aug");
  std::string follow_input("And current week is last");
  // default printer will print in std::cout and with space char
  PrintString printer('.');
  printer(input);
  printer(follow_input);
  // error printer have std::cerr and '-' as seperator
  PrintString error_printer(std::cerr, '|');
  error_printer(input);
  error_printer(follow_input);
  return 0;
}