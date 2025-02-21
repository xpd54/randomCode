#include <cstddef>
#include <iomanip>
#include <ios>
#include <iostream>
#include <memory>
using namespace std;
template <typename T = int, size_t Size = 10>
class Container {
 public:
  Container() : m_data(std::make_unique<T[]>(Size)) {}
  T& operator[](size_t index) { return m_data[index]; }

 private:
  std::unique_ptr<T[]> m_data;
};

int main() {
  Container<float, 5> holding;
  holding[0] = 23423.234;
  Container input;
  input[7] = 10;
  cout << input[7] << '\n';
  cout << holding[0] << '\n';
}