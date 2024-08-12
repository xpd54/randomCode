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

std::string global_str;
int global_int;

int main() {
  int local_int;
  int local;
  std::string local_str;
  std::cout << global_int << "\n";
  std::cout << global_str << "\n";
  std::cout << local_int << "\n";
  std::cout << local_str << "\n";
  std::cout << local << "\n";
  return 0;
}