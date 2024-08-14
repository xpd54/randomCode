#include <iostream>
#include <string>
#include <vector>

void print_string_vector(std::vector<std::string> &input) {
  for (auto &str : input) {
    std::cout << str << std::endl;
  }
}

void vector_of_vector() {
  std::vector<std::vector<std::string>> holding;
  std::vector<std::string> first = {"Hello", "World"};

  std::vector<std::string> second;
  second.push_back("Second");
  second.push_back("Hand");
  holding = {first, second};

  for (auto &vec : holding) {
    print_string_vector(vec);
  }
}

void value_initialize() {
  std::vector<int> ivec(10, 89);
  std::vector<std::string> svec(20, "Pedro");
  for (auto &ref : svec) {
    std::cout << ref << std::endl;
  }
  for (auto &ref : ivec) {
    std::cout << ref << std::endl;
  }
}

void range_for_loop() {
  std::vector<int> vec{1, 3, 4, 5, 5, 6, 6};
  for (int &value : vec) {
    value *= value;
  }

  std::vector<int>::size_type size = vec.size();
  std::cout << size << std::endl;
  for (auto &value : vec) {
    std::cout << value << std::endl;
  }
}

void string_iterator() {
  std::string str = "Some String";
  auto start = str.begin();
  auto end = str.end();
  while (start != end) {
    *start = toupper(*start);
    ++start;
  }
  std::cout << str << std::endl;
}

void const_iterator() {
  std::vector<int> holding{1, 3, 4, 5, 6, 7};
  /*const_iterator only get used to read the element from container but it
      can't update the object which container is holding. */
  std::vector<int>::const_iterator start_it = holding.begin();
  std::vector<int>::const_iterator end_it = holding.end();
  while (start_it != end_it) {
    std::cout << *start_it << "\n";
    start_it++;
  }
  std::cout << std::endl << std::endl;
  std::vector<int>::iterator start_it_update = holding.begin();
  std::vector<int>::iterator end_it_update = holding.end();
  while (start_it_update != end_it_update) {
    *start_it_update *= (*start_it_update);
    start_it_update++;
  }
}

void binary_search(const int &search_value) {
  const std::vector<int> holding = {1,  23, 36,  48,  59,  72,
                                    82, 98, 100, 123, 456, 800};
  std::vector<int>::const_iterator start = holding.begin();
  std::vector<int>::const_iterator end = holding.end();
  std::vector<int>::const_iterator mid = start + (end - start) / 2;
  while (mid != end && *mid != search_value) {
    if (search_value < *mid)
      end = mid;
    else
      start = mid + 1;
    mid = start + (end - start) / 2;
  }
  std::cout << "found value " << *mid << "\n";
}

int main() {
  binary_search(80);
  return 0;
}