#include <iostream>
#include <string>
class Base {
public:
  virtual std::string say_my_name() const {
    std::cout << "I am BaseClass" << std::endl;
    return "BaseClass";
  }
};

class Derived : public Base {
public:
  int value;
  std::string say_my_name() const {
    std::cout << "I am Derived" << std::endl;
    return "Derived";
  }
};

/* we can pass both Base and Derived class object in this function and it will
 * get decided ad run-time (dynamic binding) which method to call. From Base or
 * Derived*/
void get_name_object(Base &obj) {
  std::string name = obj.say_my_name();
  std::cout << "From ref " << name << std::endl;
}

void calling_by_ref() {
  Base base;
  Derived derived;
  get_name_object(base);
  get_name_object(derived);
}

void calling_by_value() {
  Base base;
  Derived derived;
  /*Compiler already know which version of say_my_name() need to called here.
   * (static binding)*/
  base.say_my_name();
  derived.say_my_name();
}