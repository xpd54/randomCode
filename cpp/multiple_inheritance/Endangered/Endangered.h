#pragma once
#include <string>

enum class State { Declined, Rare, Alarming };

class Endangered {
public:
  Endangered(State state, std::string selter_in);
  inline std::string where_it_protected() { return protection_country; }

private:
  State level_endangered;
  std::string protection_country;
};