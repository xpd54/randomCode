#include "StrBlob.h"
#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

/*Both constructor takes initializer list to initialize it's data member.*/
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

/*Initialize the vector by copying the values in the list*/
StrBlob::StrBlob(std::initializer_list<std::string> initializer_list)
    : data(std::make_shared<std::vector<std::string>>(initializer_list)) {}

void StrBlob::check(size_type i, const std::string &msg) const {
  if (i >= data->size())
    throw std::out_of_range(msg);
}

std::string &StrBlob::front() {
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string &StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}

void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}