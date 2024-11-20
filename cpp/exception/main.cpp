#include "Base.h"
#include "exception.h"
#include <vector>

int main() {
  std::vector<int> input{1, 2, 3, 4, 5, 6};
  for (auto &value : input) {
    Derived *derived = new Derived(value, "Hello");
    try {
      print_pattern(derived);
      /*Catch clause should be top derived to Base. In case where Base is first
       * and Derived is later all exception will be cought by Base.*/
    } catch (Derived value) {
      std::cout << "Caught By Derived:- " << value.get_value() << '\n';
    } catch (Base value) {
      std::cout << "Caught By Base:- " << value.get_value() << '\n';
    }
  }

  Base base(10);
  std::cout << base.get_value() << '\n';
  return 0;
}