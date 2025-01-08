struct B {
  explicit B(int x) {}
};

struct A {
  A(B const& b) {}
  void doSomething() {}
};

int main() {
  int x = 42;
  // A a(B(x));
  // Use {} not () for constructor
  A a(B{x});
  a.doSomething();
}