#pragma once
#include <string>
class Quote {
private:
  std::string bookNo; // ISBN number of this item
protected:
  double price = 0.0; // normal, undiscounted price
public:
  Quote() = default;
  Quote(const std::string &book, double sales_price)
      : bookNo(book), price(sales_price) {}

  std::string isbn() const { return bookNo; }

  virtual double net_price(size_t n) const { return n * price; }

  /*classes used as root of an inheritance hierarchy always define a virtual
   * destructor*/
  virtual ~Quote() = default; // dynamic binding for destructor
};
