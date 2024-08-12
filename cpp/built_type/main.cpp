#include <iostream>
#include <string>
void typeConversion() {
  bool b = 42;
  int i = 42;
  i = 3.14;
  double pi = i;
  unsigned char c = -1;
  signed char c2 = 256;

  std::cout << "boolean " << b << "\n";
  std::cout << "int " << i << "\n";
  std::cout << "double " << pi << "\n";
  std::cout << "unsigned " << c << "\n";
  std::cout << "char " << c2 << "\n";
}

void literal() {
  int a = 20;
  int octal = 024;
  int hexdecimal = 0x14;

  std::cout << a << " " << octal << " " << hexdecimal << "\n";
}

void stringLiteral() {
  std::cout << "A"
            << "\n";
  std::cout << 'A' << "\n";
  std::cout << "a really,really long string literal "
            << "that spans two lines" << std::endl;
}

int global_int = 42;

int main() {
  int global_int = 100;
  int j = global_int;
  std::cout << j << std::endl;
  return 0;
}