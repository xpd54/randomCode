#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex gLock;
std::condition_variable gCondition;

int main() {
  int result = 0;
  bool notified = false;
  // reporting thread
  std::thread reporter([&]() {
    std::unique_lock<std::mutex> lock(gLock);
    if (!notified) {
      gCondition.wait(lock);
    }
    std::cout << "reported :- " << result << '\n';
  });
  // worker thread
  std::thread worker([&]() {
    std::unique_lock<std::mutex> lock(gLock);
    result = 1 + 2 + 3;

    notified = true;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "work done" << '\n';
    gCondition.notify_one();
  });

  reporter.join();
  worker.join();

  return 0;
}
