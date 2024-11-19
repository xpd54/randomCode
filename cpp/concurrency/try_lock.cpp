#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex glock;
void first_job() {
  glock.lock();
  std::cout << "First job is done" << '\n';
  glock.unlock();
}

void second_job() {
  if (glock.try_lock()) {
    std::cout << "Second job is done" << '\n';
    glock.unlock();
  } else {
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(5ms);
    if (glock.try_lock()) {
      std::cout << "Second after wait" << '\n';
      glock.unlock();
    }
  }
}

int main() {
  std::thread first_thread(first_job);
  std::thread second_thread(second_job);

  first_thread.join();
  second_thread.join();
  return 0;
}