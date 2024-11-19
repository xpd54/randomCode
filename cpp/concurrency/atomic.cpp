#include <atomic>
#include <iostream>
#include <thread>
#include <vector>
static std::atomic<int> shared_value = 0;
void shared_value_increment() { shared_value++; }

int main() {
  std::vector<std::thread> threads;
  threads.reserve(100);
  for (int i = 0; i < 1000; ++i) {
    threads.push_back(std::thread(shared_value_increment));
  }

  for (auto &thread : threads) {
    thread.join();
  }

  std::cout << shared_value << "\n";
  return 0;
}