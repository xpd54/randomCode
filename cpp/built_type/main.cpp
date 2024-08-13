#include <iostream>
#include <string>
void typeConversion() {
  bool b = 42;
  int i = 42;
  i = 3;
  double pi = i;
  unsigned char c = -1;
  signed char c2 = ' ';

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

void const_reference() {
  int i = 42;
  const int &r1 = i;
  const int &r2 = 42;
  const int *r3 = &i;
  std::cout << r1 << "\n";
  std::cout << &r2 << "\n";
  std::cout << r3 << "\n";
  std::cout << *r3++ << "\n";
}

inline int get_size() { return 10; }

void const_qualifier() {
  // initialized at run time bu do have compiler optimization
  const int i = get_size();
  const int j = 42;
  int change_able = 30;
  // can use non const to change the underlining value which reference refers;
  int &r_change_able = change_able;
  std::cout << change_able << "\n";
  r_change_able = 90;
  const int &r_nonChangeable = j;
  const int &ref = r_nonChangeable + 1;
  std::cout << ref << "\n";
  std::cout << change_able << "\n";
  std::cout << i << "\n";
}

int main() {
  const_qualifier();
  return 0;
}