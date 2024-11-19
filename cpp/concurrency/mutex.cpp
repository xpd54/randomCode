#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
static int shared_value = 0;
std::mutex gLock;
void shared_value_increment() {
  gLock.lock();
  shared_value++;
  gLock.unlock();
}

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