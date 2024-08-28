#pragma once
#include "Quote.h"

class Disc_quote : public Quote {
protected:
// These will get acessed by Bulk_quote fo implement net_price
  size_t min_qty = 0;
  double discount = 0.0;

public:
  Disc_quote() = default;
  Disc_quote(const std::string &book, double price, size_t qty, double disc)
      : Quote(book, price), min_qty(qty), discount(disc) {}
  double net_price(size_t) const = 0;
};
