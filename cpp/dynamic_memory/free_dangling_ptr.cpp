#include <memory>
int main() {
  int *q = new int(42), *r = new int(100);
  // if we don't delete before assigning q to r we did't free up memory aquaried
  // by r;
  delete r;
  r = q;
  delete q;
  auto q2 = std::make_shared<int>(42), r2 = std::make_shared<int>(100);
  r2 = q2;
  return 0;
}