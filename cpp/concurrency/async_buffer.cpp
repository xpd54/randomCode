#include <chrono>
#include <cstddef>
#include <future>
#include <iostream>
#include <thread>

bool load_file_buffer() {
  size_t bytesLoaded = 0;
  while (bytesLoaded <= 20000) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    bytesLoaded += 1000;
    std::cout << "file buffer is loading ...." << '\n';
  }
  return true;
}

int main() {
  std::future<bool> load_file_in_background =
      std::async(std::launch::async, &load_file_buffer);
  while (true) {
    std::cout << "Main thread is running" << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::future_status status =
        load_file_in_background.wait_for(std::chrono::milliseconds(1));
    if (status == std::future_status::ready) {
      std::cout << "Our file load is ready" << '\n';
      break;
    }
  }
  std::cout << "Main program is complted" << '\n';
  return 0;
}