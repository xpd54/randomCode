#include "header.h"

class DebugDelete {
public:
  DebugDelete(std::ostream &s = std::cerr) : os(s) {}
  template <typename T> void operator()(T *p) const {
    os << "deleting unique_ptr" << std::endl;
    delete p;
  }

private:
  std::ostream &os;
};

template <typename T> class Blob {
public:
  template <typename It> Blob(It s, It e);

private:
  It start;
  It end;
};

int main() {
  double *p = new double;
  DebugDelete d;
  d(p);
  int *ip = new int;
  DebugDelete()(ip);
  return 0;
}
