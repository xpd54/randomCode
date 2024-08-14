#include <iostream>
#include <vector>
void using_null_statement() {
  int input[] = {1, 23, 5, 6, 7, 0};
  int i = 0;
  while (input[i])
    ;
  i++;
}

int single_statement_function() { return 10; }

void definition_inside_the_body() {
  std::vector<int> input = {1, 2, 3, 4, 54, 6, 7};
  for (auto &value : input) {
    switch (value) {
      /* jump bypass variable initialization
        As initialization is in scope we can skip it where it's out of scope
        this came ivalue to be a ilegal defination to prevent that. c++ dont'
        allow initialization in switch case unless it's a block. If it's a block
        we can't access the value outsid of the block and it make it safe to
        keep it there. Even though it's not gonna get initialized we know that
        given variable is not getting used.
      */
    case 1: {
      int ivalue = 0;
    } break;
    case 2:
      std::cout << "test" << std::endl;
    default:
      break;
    }
  }
}

void try_catch_block() {
  std::vector<int> input = {1, 2, 3, 4, 5, 6, 0, 2, 3, 4};
  double base_value = 20.0;
  for (auto &value : input) {
    try {
      double div = base_value / value;
      std::cout << div << "\n";
    } catch (std::exception exc) {
      std::cout << "devided by 0 happen" << std::endl;
      std::cout << exc.what() << std::endl;
    }
  }
}

int main() {
  try_catch_block();
  return 0;
}