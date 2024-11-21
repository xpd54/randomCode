#include "BuildingData.h"
#include <iostream>
#include <string>
namespace building {
BuildingData::BuildingData(std::string name, std::string floor,
                           double cost_in_million)
    : building_name(name), floor_name(floor), cost_to_build(cost_in_million) {
  std::cout << building_name << " "
            << "building has been created" << '\n';
}

} // namespace building

std::string building::BuildingData::get_cost() const {
  return std::to_string(cost_to_build) + "m";
}