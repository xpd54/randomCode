#pragma once
#include "Quote.h"
/* Bulk_quote inherits from Quote. As Bulk_quote uses public in derivation list
 * we can use Bulk_quote object as Quote object*/
class Bulk_quote : public Quote {
public:
  double net_price(size_t) const override;
};
