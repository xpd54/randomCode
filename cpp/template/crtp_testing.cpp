#include <iostream>
using namespace std;
template <typename T>
class Base {
 public:
  void working_on_base() {
    cout << "Hey how are you!! say hello \n";
    update();
  }
  void update() { static_cast<T *>(this)->update(); }
};

class SayHello : public Base<SayHello> {
 public:
  void update() { cout << "hello" << '\n'; }
};

class SayBye : public Base<SayBye> {
 public:
  void update() { cout << "Bye Bye" << '\n'; }
};

int main() {
  SayHello *derived = new SayHello();
  derived->working_on_base();

  SayBye *bye_bye = new SayBye();
  bye_bye->working_on_base();
}