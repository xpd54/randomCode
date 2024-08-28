#include <iostream>
#include <string>

class Base {
protected:
  // Default constructor doesn't initialized the protected, private or public
  // built in members;
  int protected_value;

private:
  int private_value;

public:
  virtual std::string say_my_name() const {
    std::cout << "I am BaseClass" << std::endl;
    return "BaseClass";
  }

  virtual void access_protected() const {
    std::cout << "Default initialized proected_value from base "
              << protected_value << std::endl;
  }

  void access_private() const {
    std::cout << "Default initialized private_value from base " << private_value
              << std::endl;
  }
};

class Derived : public Base {
public:
  int value;
  std::string say_my_name() const override {
    std::cout << "I am Derived" << std::endl;
    return "Derived";
  }
  void access_protected() const override {
    std::cout << "Default initialized protected_value " << protected_value
              << std::endl;
  }

  /*
    private members are not accessable for Derived class;
      void access_private() {
        std::cout << "Default initialized private_value" << private_value
                  << std::endl;
      }
  */
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
  base.access_protected();
  base.access_private();
  derived.say_my_name();
  derived.access_protected();
}