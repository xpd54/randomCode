#include <iostream>
#include <string>
template <typename T> class Blob {
  template <typename K> friend void print_out(const Blob<K> &);

private:
  T pri_value;

public:
  T pub_value;
  Blob(T pub, T pri) : pub_value(pub), pri_value(pri) {}
};

template <typename K> void print_out(const Blob<K> &blob) {
  std::cout << "Public Value: " << blob.pub_value << std::endl;
  std::cout << "Private Value: " << blob.pri_value << std::endl;
}

int main() {
  Blob<int> blob(10, 30);
  print_out(blob);

  Blob<std::string> blob_string("Hello", "World");
  print_out(blob_string);
  return 0;
}
