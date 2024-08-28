#include "Bulk_quote.h"
#include "Quote.h"
#include "StaticMemberInBase.cpp"
#include "virtualBindingInRef.cpp"
#include <iostream>
/* As print_total is getting called via reference there gonna boe run-time
 * binding or dynamic binding. As Compiler don't know yet which type of object
 * gonna get pass to the function.*/
double print_total(std::ostream &os, const Quote &item, size_t n) {
  // depending on the type of object bound to the item parameter
  // call either Quote::net_price or Bulk_quote::net_price

  double ret = item.net_price(n);
  os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret
     << std::endl;
  return ret;
}

int main() {
  return 0;
}