#include "Bear.h"
Bear::Bear(bool cute, bool is_black)
    : ZooAnimal("Bear", (is_black ? "Around The Glob" : "North Pole"), 100),
      adorable(cute), should_run(!is_black),
      color(is_black ? "Black" : "white"){};
