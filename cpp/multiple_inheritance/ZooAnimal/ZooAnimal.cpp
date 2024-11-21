#include "ZooAnimal.h"

ZooAnimal::ZooAnimal(std::string name, std::string origin, uint16_t lb)
    : name_of_animal(name), origin_country(origin), weight(lb) {}
AnimalDetails ZooAnimal::get_details() const {
  return {name_of_animal, origin_country, weight};
}

uint16_t ZooAnimal::get_max_weight(uint16_t year_old) const {
  return weight * year_old + 10 - (5 * year_old);
}