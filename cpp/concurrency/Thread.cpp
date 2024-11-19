#include <iostream>
#include <thread>

void test(int x) {
  std::cout << "hello from thread" << '\n';
  std::cout << "Argument passed in: " << x << '\n';
}

int main() {
  std::thread myThread(&test, 100);

  auto lambda = [](int x) {
    std::cout << "Hello from lambda" << '\n';
    std::cout << "Argument from lambda:- " << x << '\n';
  };

  std::thread lambda_thread(lambda, 100);
  std::cout << "hello from my main thread" << '\n';

  // main thread might finish it's work before test and whole program will get
  // terminated in that case it's core dump
  myThread.join();
  lambda_thread.join();
  return 0;
}