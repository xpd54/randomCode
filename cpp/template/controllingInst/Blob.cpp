template <typename T> class Blob {
public:
  Blob(T val) : value(val) {}
  T getValue() { return value; }

private:
  T value;
};
