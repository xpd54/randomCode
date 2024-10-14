class Data {
public:
  int input;
  int output;
  bool operator<(const Data &rhs) { return rhs.output < output; }
  Data(int first = 10, int second = 20) : input(first), output(second) {}
};
