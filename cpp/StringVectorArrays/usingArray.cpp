#include <array>
#include <iostream>
#include <string>
#include <vector>

void array_initialization() {
  unsigned cnt = 42;
  constexpr unsigned sz = 42;
  std::string arr[42];
}

void char_array() {
  // no null termination here
  char a1[] = {'C', '+', '+'};
  // null char termination
  char a2[] = {'C', '+', '+', '\0'};
  // if initialized by string litral null termination is included.
  char a3[] = "c++";
  // have to leave 1 value empty for null termination char
  const char a4[6] = "Danie";
  std::cout << a1 << "\n";
  std::cout << a2 << "\n";
  std::cout << a3 << "\n";
  std::cout << a4 << "\n";
}

void overflow_array() {
  constexpr size_t array_size = 10;
  int input[array_size];
  // overflow there is not index 10 here. index starts from 0
  for (size_t ix = 1; ix <= array_size; ++ix) {
    std::cout << ix << std::endl;
    input[ix] = ix;
  }
}

void begin_end_iterator() {
  constexpr size_t size_of_array = 10;
  // after 5 values other value would be default initialized as 0 because it's
  // int array
  int input[size_of_array] = {1, 3, 4, 5, 6};
  /* array is not a class type so we can't use the method as member function,
   * instead we have to use it as function itself. */
  int *beg = std::begin(input);
  int *end = std::end(input);
  while (beg != end) {
    std::cout << *beg << "\n";
    beg++;
  }
}

void null_terminate_char_array() {
  char input[5] = {'1', 'a', 'd', '3', '\0'};
  std::cout << input << " " << strlen(input)
            << " "
               "\n";
}

void string_char_array() {
  std::string input[3] = {"hello", "world", "here"};
  std::cout << input[0] << "\n";
}

void array_to_vec() {
  int input[] = {1, 2, 3, 4, 5, 6, 7};
  std::vector<int> vec_input(std::begin(input) + 1, std::end(input));
  for (auto &ref : vec_input) {
    std::cout << ref << "\n";
  }
}

void three_dimentional_array() {
  int input[2][3][2] = {{{1, 2}, {3, 4}, {5, 6}}, {{7, 8}, {9, 10}, {11, 12}}};
  for (auto &ref : input) {
    std::cout << "{" << std::endl;
    for (auto &ref1 : ref) {
      std::cout << " {" << ref1[0] << ", " << ref1[1] << "}" << std::endl;
    }
    std::cout << "}," << std::endl;
  }
}

int main() {
  three_dimentional_array();
  return 0;
}