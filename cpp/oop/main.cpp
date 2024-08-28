#include "Bulk_quote.h"
#include "Quote.h"
#include "Disc_quote.h"
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

void bulk_vs_quote() {
  Bulk_quote bulk("100-300-2", 50, 5, 0.5);
  /* This will bring a price of 250 as we are getting bulk price and it have
   * discount on 5 item (mentioned in constructor) */
  print_total(std::cout, bulk, 10);
  // calling bulk net_price for 5 would be 125 with discount
  std::cout << "Calling Bulk price for 5:- " << bulk.net_price(5) << std::endl;
  Quote item;
  /*We have copied Quote part of of derived info to base, In this case net_price
   * is from base*/
  item = bulk;
  print_total(std::cout, item, 10);
  // calling Quote's net_price which would be 250 since there is not discount
  std::cout << "Calling Quote price for 5:- " << item.net_price(5) << std::endl;
}

int main() {
  bulk_vs_quote();
  return 0;
}