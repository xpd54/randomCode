#pragma once
#include "Quote.h"
/* Bulk_quote inherits from Quote. As Bulk_quote uses public in derivation list
 * we can use Bulk_quote object as Quote object*/
class Bulk_quote : public Quote {
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &, double, size_t, double);
  // overrides the base version in order to implement the bulk purchase discount
  // policy
  double net_price(size_t) const override;

private:
  size_t min_qty = 0;    // minimum purchase for the discount to apply
  double discount = 0.0; // fractional discount to apply
};