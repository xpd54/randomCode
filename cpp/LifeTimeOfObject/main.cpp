#include <cstdio>
#include <iostream>
#include <optional>
#include <source_location>
void print(
    const std::source_location &location = std::source_location::current()) {
  std::puts(location.function_name());
}

class Lifetime {
 public:
  Lifetime() { print(); }
  Lifetime(int val) { print(); }
  Lifetime(const Lifetime &lifetime) { print(); }
  Lifetime(Lifetime &&lifetime) { print(); }
  Lifetime &operator=(const Lifetime &lifetime) {
    print();
    return *this;
  }
  Lifetime &operator==(Lifetime &&lifetime) {
    print();
    return *this;
  }
  ~Lifetime() {}
};

std::optional<Lifetime> get() { return Lifetime(); }

int main() { get(); }