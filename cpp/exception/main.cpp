#include "Base.h"
#include "exception.h"
#include <iostream>
#include <memory>
#include <vector>

int main() {
  std::vector<int> input{5};
  for (auto &value : input) {
    std::shared_ptr<Derived> derived(std::make_shared<Derived>(value, "Hello"));
    try {
      print_pattern(derived);
      /*Catch clause should be top derived to Base. In case where Base is first
       * and Derived is later all exception will be cought by Base.*/
    } catch (Derived value) {
      std::cout << "Caught By Derived:- " << value.get_value() << '\n';
    } catch (Base value) {
      std::cout << "Caught By Base:- " << value.get_value() << '\n';
    }
    std::cout << "Shared Count in main " << derived.use_count() << '\n';
  }
  return 0;
}