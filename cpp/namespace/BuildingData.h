#pragma once
#include <string>
namespace building {
class BuildingData {
public:
  BuildingData(std::string name, std::string floor, double cost_in_million);
  std::string get_cost() const;
  inline std::string get_name() const { return building_name; }

private:
  std::string building_name;
  std::string floor_name;
  double cost_to_build;
};
} // namespace building