#include "Bulk_quote.h"

Bulk_quote::Bulk_quote(const std::string &book, double p, size_t qty,
                       double disc)
    : Disc_quote(book, p, qty, disc) {}

double Bulk_quote::net_price(size_t count) const {
  if (count >= min_qty)
    return count * (1 - discount) * price;
  else
    return count * price;
}