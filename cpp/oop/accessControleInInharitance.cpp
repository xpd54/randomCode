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
  void accessMethod() {
    publicMethod();    // it's accessible
    protectedMethod(); // it's accessible but became protected here so can't
                       // access with  object
    // privateMethod(); // not accessible
  }
};

class ProtectedBase : protected Base {
public:
  void accessMethod() {
    publicMethod();
    protectedMethod();
    // privateMethod(); // not accessible
  }
};

class PrivateBase : private Base {
public:
  void accessMethod() {
    publicMethod();
    protectedMethod();
    // privateMethod(); /// not accessible
  }
};

class ThirdLevel : public PrivateBase {
public:
  void acessMethod() {
    // publicMethod(); // can't access any of method
    // protectedMethod();
  }
};

int main() {

  Base base;
  base.publicMethod();
  // base.protectedMethod();
  // base.privateMethod();

  PublicBase publicBase;
  publicBase.accessMethod();
  publicBase.publicMethod();
  // publicBase.protectedMethod();
  // publicBase.privateMethod();
  base = publicBase; // only if it's public inherits 
  ProtectedBase protectedBase;
  protectedBase.accessMethod();
  // protectedBase.publicMethod();
  // protectedBase.protectedMethod();
  // protectedBase.privateMethod();
  PrivateBase privateBase;
  privateBase.accessMethod();
  // base = privateBase; can't as it's not public
  // privateBase.publicMethod();
  // privateBase.protectedMethod();
  // privateBase.privateMethod();
  ThirdLevel level;
  level.accessMethod();
  // level.publicMethod();
  return 0;
}