#include <iostream>
class MyFriend;

class Base {
  friend MyFriend;

public:
  int pub_value = 5;
  void publicMethod() {
    std::cout << "Public method of Base class " << prot_value << std::endl;
  }

protected:
  int prot_value = 10;
  void protectedMethod() {
    std::cout << "Protected method of Base class" << std::endl;
  }

private:
  int priv_value = 5;
  void privateMethod() {
    std::cout << "Private method of Base class " << std::endl;
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

class MyFriend {
public:
  void getValue() {
    Base base;
    std::cout << "public " << base.pub_value << std::endl;
    std::cout << "protected " << base.prot_value << std::endl;
    std::cout << "private " << base.priv_value << std::endl;
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

  MyFriend fr;
  fr.getValue();
  return 0;
}