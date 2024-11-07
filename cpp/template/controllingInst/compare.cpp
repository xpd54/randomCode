#include <functional>
template <typename T> T compare(const T &left, const T &right) {
  return std::less<T>{}(left, right) ? 1 : -1;
}
