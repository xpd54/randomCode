#include <map>
#include <utility>

class Date {
 public:
  Date(int year, int month, int day) {}
  // ...
};

using FutureDate = Date;    // the original example used NamedType here
using OptionExpiry = Date;  // but I removed it for simplification

class KeyInstrument {
 public:
  KeyInstrument(const FutureDate &futureDate,
                const OptionExpiry &optionExpiry) {}
  bool operator<(const KeyInstrument &other) const { return false; }
  // ...
};

enum class StatusInstrument { Ok, NegativeFwdFwdVol };

using PairStatus = std::pair<KeyInstrument, StatusInstrument>;
using StatusCalib = std::map<KeyInstrument, StatusInstrument>;

int main() {
  Date date1(2017, 12, 02);
  Date date2(2018, 03, 30);

  // KeyInstrument key(FutureDate(date1), OptionExpiry(date2));
  // use {} instead
  KeyInstrument key(FutureDate(date1), OptionExpiry{date2});

  StatusCalib status;
  status.insert(PairStatus(key, StatusInstrument::Ok));
}