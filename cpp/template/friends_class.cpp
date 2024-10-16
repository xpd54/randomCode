#include <iostream>
#include <string>
template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);
template <typename T> class Blob {
  friend class BlobPtr<T>;
  /*Operator should also be denoted as template as this wil allow all the
   * instansiation of Blob to access the operator accordingly*/
  friend bool operator== <T>(const Blob<T> &, const Blob<T> &);

private:
  T value;

public:
  Blob(T val) : value(val) {}
};

template <typename T>
bool operator==(const Blob<T> &left, const Blob<T> &right) {
  return left.value == right.value;
}

template <typename T> class BlobPtr {
public:
  void print(const Blob<T> &blob) { std::cout << blob.value << std::endl; }
};

int main() {
  Blob<std::string> hello("Hello");
  Blob<std::string> world("World");
  Blob<int> value_ten(10);
  Blob<int> value_twenty(20);
  BlobPtr<std::string> blob_pt;
  BlobPtr<int> blob_pt_int;
  blob_pt.print(hello);
  blob_pt.print(world);
  blob_pt_int.print(value_ten); // BlobPtr<int> is friend of Blob<int> but not
                                // mix with std::string
  bool value = operator==(value_ten, value_twenty);
  std::cout << value << std::endl;
  return 0;
}
