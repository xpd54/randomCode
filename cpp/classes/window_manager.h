#include "screen.h"
#include <vector>
class Window_mgr {
private:
  std::vector<Screen> screens{Screen(24, 80, ' ')};
};