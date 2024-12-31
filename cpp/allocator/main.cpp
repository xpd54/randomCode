#include <cstddef>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

template <typename T>
struct MyAlloc : allocator<T> {
  T* allocate(size_t size) {
    cout << "Allocation size" << '\n';
    return new T[size];
  }
};

int main() { vector<int, MyAlloc<int>> v1; }