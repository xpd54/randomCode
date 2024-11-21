#include "ZooAnimal/Bear/Bear.h"
#include "ZooAnimal/Panda/Panda.h"
#include "ZooAnimal/Racoon/Racoon.h"
#include "ZooAnimal/ZooAnimal.h"
#include <iostream>

void should_I_run(Bear &bear) {
  std::cout << (bear.see_and_run() ? "Run !!" : "No need") << '\n';
}

void can_you_find_in_japan(Racoon &racoon) {
  std::cout << (racoon.get_origin() == "Japan" ? "Yes!!" : "No!!") << '\n';
}

void print_details(ZooAnimal &animal) {
  AnimalDetails details = animal.get_details();
  std::cout << "Name:- " << details.name_of_animal << '\n';
  std::cout << "Country:- " << details.origin_country << '\n';
  std::cout << "Weight:- " << details.weight << '\n';
}

int main() {
  Panda chinese_panda("China"), only_maxican_panda("Maxico");
  std::cout << chinese_panda.get_color() << '\n';
  std::cout << chinese_panda.get_max_weight() << '\n';
  // see_and_run have to be explicity or panda will implement that
  std::cout << chinese_panda.Bear::see_and_run() << '\n';
  std::cout << chinese_panda.see_and_run() << '\n';
  std::cout << chinese_panda.cuddle() << '\n';
  std::cout << chinese_panda.where_it_protected() << '\n';
  should_I_run(chinese_panda);
  can_you_find_in_japan(chinese_panda);
  /*if only one base class is virtual like only Bear this is an ambiguity for
    which part its should convert
    Panda -> Bear -> ZooAnimal ?
    Panda -> Racoon -> ZooAnimal ?

    In case when both are virtual inharitance it only make one copy of
    ZooAnimal.
  */

  print_details(chinese_panda);
}
