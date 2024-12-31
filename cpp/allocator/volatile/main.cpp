#include <chrono>
#include <cstddef>
#include <iostream>
#include <thread>

volatile bool flag = false;

void set_flag() {
  std::this_thread::sleep_for(std::chrono::nanoseconds(1));
  flag = true;
}

int main() {
  size_t count = 0;
  size_t start = 0;

  std::thread starter([&]() {
    while (!flag) ++start;
  });

  std::thread counter([&]() {
    while (!flag) {
      ++count;
    }
  });

  std::thread exicute(set_flag);

  starter.join();
  exicute.join();
  counter.join();
  std::cout << "start counted : " << start << '\n';
  std::cout << "count counted : " << count << '\n';

  return 1;
}