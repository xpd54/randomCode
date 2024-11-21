#include "BuildingData.h"
#include <iostream>

int main() {
  building::BuildingData monster_building("Monster Building", "15fb", 300);
  std::cout << monster_building.get_name() << " "
            << "cost would be:- " << monster_building.get_cost() << '\n';
  return 0;
}