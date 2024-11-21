#pragma once
#include <cstdint>
#include <string>
struct AnimalDetails {
  std::string name_of_animal;
  std::string origin_country;
  uint16_t weight;
};

class ZooAnimal {
public:
  ZooAnimal(std::string name, std::string origin, uint16_t lb);
  AnimalDetails get_details() const;
  inline std::string get_origin() { return origin_country; }
  uint16_t get_max_weight(uint16_t year_old) const;

private:
  std::string name_of_animal;
  std::string origin_country;
  uint16_t weight;
  uint16_t max_weight;
};