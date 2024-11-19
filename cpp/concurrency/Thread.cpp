#include <iostream>
#include <thread>

void test(int x) {
  std::cout << "hello from thread" << '\n';
  std::cout << "Argument passed in: " << x << '\n';
}

int main() {
  std::thread myThread(&test, 100);
  std::cout << "hello from my main thread" << '\n';

  // main thread might finish it's work before test and whole program will get
  // terminated in that case it's core dump
  myThread.join();
  return 0;
}