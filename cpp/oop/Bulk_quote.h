#pragma once
#include "Disc_quote.h"
#include <iostream>
/* Bulk_quote inherits from Quote. As Bulk_quote uses public in derivation list
 * we can use Bulk_quote object as Quote object*/
class Bulk_quote : public Disc_quote {
public:
  Bulk_quote() = default;
  ~Bulk_quote() override {
    std::cout << "Runing Destructor in Bulk_quote"
              << "\n";
  };
  Bulk_quote(const std::string &isbn, double price, size_t quntity,
             double discount);

  // overrides the base version in order to implement the bulk purchase discount
  // policy
  double net_price(size_t) const override;
};