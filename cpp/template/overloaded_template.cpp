#include "header.h"

template <typename T> std::string debug_rep(const T &t) {
  std::ostringstream ret;
  ret << t;
  return ret.str();
}

template <typename T> std::string debu_rep(T *p) {
  std::ostringstream ret;
  ret << "pointer: " << p;
  if (p)
    ret << " " << debu_rep(*p);
  else
    ret << " null pointer";
  return ret.str();
}

int main() {
  std::string s("hi");
  std::string *val;
  val = &s;
  std::cout << debug_rep(s) << std::endl;
  std::cout << debug_rep(val) << std::endl;

  return 0;
}
