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

void pointer_is_an_object() {
  int ivalue = 42;
  int *pvalue = &ivalue;
  /*As pointer itself is a object we can take reference of that pointer
  And we can also have another pointer pointing to that ponter itself. It can
  keep going to as many level as possible.*/
  int **ppvalue = &pvalue;
  int ***pppvalue = &ppvalue;
  std::cout << pvalue << "\n";
  std::cout << *pvalue << "\n";
  std::cout << &pvalue << "\n";
  std::cout << ppvalue << "\n";
  std::cout << *ppvalue << "\n";
  std::cout << **ppvalue << "\n";
  /*3 Level pointer */
  std::cout << ***pppvalue << "\n";
  // we can also take a reference of a pointer cause it's also an object
  std::cout << &pppvalue << "\n";
}
int main() {
  pointer_is_an_object();
  return 0;
}