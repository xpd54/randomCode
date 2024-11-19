#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
static int shared_value = 0;
std::mutex gLock;
void shared_value_increment() {
  std::lock_guard<std::mutex> lock_guard(gLock);
  try {
    shared_value++;
    throw "Error";
  } catch (...) {
    std::cout << "Error" << '\n';
    return;
  }
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