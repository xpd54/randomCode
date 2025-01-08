#include <iostream>
extern int x;
static int a = x + 10;
void printA() { std::cout << "a = " << a << std::endl; }