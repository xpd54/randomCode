#include "Sales_data.h"
int main() {
  Sales_data data;
  Sales_data data_with_name("Book");
  Sales_data data_with_all("harry potter", 19, 5.0);

  // Sales_data data_with_input(std::cin);
  // print(std::cout, data_with_input) << std::endl;
  print(std::cout, data) << std::endl;
  print(std::cout, data_with_name) << std::endl;
  print(std::cout, data_with_all) << std::endl;
  return 0;
}
