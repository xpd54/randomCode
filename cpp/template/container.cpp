#include <cstddef>
#include <iostream>
#include <memory>
using namespace std;
template <typename T, size_t N>
class Container {
 public:
  Container() : m_data(std::make_shared<T[]>(N)) {}
  T& operator[](size_t index) { return m_data[index]; }

 private:
  std::shared_ptr<T[]> m_data;
};

int main() {
  Container<int, 10> integer;
  Container<double, 5> double_container;
  integer[0] = 10;
  double_container[0] = 10.3;
  cout << integer[0] << '\n';
  cout << double_container[0] << '\n';
  return 0;
}