#include <iostream>
#include <string>
#include <vector>
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
  void operator()(const std::string &s) const { os << s << sep; }
  // overloading an operator override and use another to complete
  /*void operator()(const std::string &s, int count = 5) {
    while (--count) {
      operator()(s);
    }
  }*/

private:
  std::ostream &os; // stream on which to write
  char sep;         // character to print after each output;
};

void PrintStringExample() {
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

  std::string oneValue("x");
  // printer(oneValue, 4);
}

class ReadString {
public:
  ReadString(std::istream &in = std::cin) : input(in) {}
  std::string operator()(std::istream &in) {
    std::string value;
    // reading a line which have default delimator as "\n";
    if (getline(in, value)) {
      return value;
    } else
      return value;
  }

  std::vector<std::string> &operator()(std::istream &in,
                                       std::vector<std::string> &contents) {
    std::string value;
    /* let's use eof() which indecate input stream has been ended by end of
  file. to semulate this from terminal we can press Ctrl+D on mac os
*/
    while (std::getline(in, value, '.') && !in.eof()) {
      contents.push_back(value);
    }
    return contents;
  }

private:
  std::istream &input;
};

void readStringExample() {
  ReadString reading;
  std::string value = reading(std::cin);
  std::cout << value << "\n";
  std::vector<std::string> contents;
  reading(std::cin, contents);

  for (auto &value : contents)
    std::cout << value << std::endl;
}

/*
Lambdas are function object
*/
class ShorterString {
public:
  bool operator()(const std::string &s1, const std::string &s2) const {
    return s1.size() < s2.size();
  }
};

void usePrintObjectInForEach() {
  std::vector<std::string> input{"one", "two", "three", "four", "five"};

  /* Using a funciton object to pass function object. Lambdas are unnamed object
   * of unnamed class, Here as well rvalue and calling the constructor which is
   * synthesized constructor*/
  std::stable_sort(input.begin(), input.end(), ShorterString());
  /* Here the function is a rvalue which we are creating by calling
   * constructor*/
  std::for_each(input.begin(), input.end(), PrintString(std::cout, '\n'));
}

int main() {
  usePrintObjectInForEach();
  return 0;
}