#include <chrono>
#include <cstddef>
#include <iostream>
#include <thread>

volatile bool flag = false;
volatile size_t start = 0;

void set_flag() {
  std::this_thread::sleep_for(std::chrono::nanoseconds(1));
  flag = true;
  while (flag) {
    ++start;
  }
}

int main() {
  int count = 0;
  std::thread exicute(set_flag);
  while (!flag) {
    ++count;
  }

  std::this_thread::sleep_for(std::chrono::nanoseconds(1));
  flag = false;
  exicute.join();
  std::cout << "flag counted : " << count << '\n';
  std::cout << "start counted : " << start << '\n';
  return 1;
}