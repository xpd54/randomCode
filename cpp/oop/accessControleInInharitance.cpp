#include <iostream>

class Base {
public:
  void publicMethod() {
    std::cout << "Public method of Base class" << std::endl;
  }

protected:
  void protectedMethod() {
    std::cout << "Protected method of Base class" << std::endl;
  }

private:
  void privateMethod() {
    std::cout << "Private method of Base class" << std::endl;
  }
};

class PublicBase : public Base {
public:
  void publicMethod();
  void protectedMethod();
  void privateMethod();
};

class ProtectedBase : protected Base {
public:
  void publicMethod();
  void protectedMethod();
  void privateMethod();
};

class PrivateBase : private Base {
public:
  void publicMethod();
  void protectedMethod();
  void privateMethod();
};

int main() {

  Base base;
  base.publicMethod();
  base.protectedMethod();
  base.privateMethod();

  PublicBase publicBase;
  publicBase.publicMethod();
  publicBase.protectedMethod();
  publicBase.privateMethod();

  ProtectedBase protectedBase;
  protectedBase.publicMethod();
  protectedBase.protectedMethod();
  protectedBase.privateMethod();

  PrivateBase privateBase;
  privateBase.publicMethod();
  privateBase.protectedMethod();
  privateBase.privateMethod();

  return 0;
}