#include "Base.h"
#include "exception.h"

int main() {
  Derived *derived = new Derived(4, "Hello");
  try {
    print_pattern(derived);
  } catch (Base *value) {
    std::cout << value->get_value() << '\n';
  }

  Base base(10);
  std::cout << base.get_value() << '\n';
  return 0;
}