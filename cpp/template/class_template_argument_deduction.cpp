#include <iostream>
using namespace std;
template <typename Key, typename Value>
struct Entry {
  Entry(Key key, Value value) : m_key(key), m_value(value) {}
  Key m_key;
  Value m_value;
};

int main() {
  // skipped type name of template here for Entry (CTAD)
  // class template argument deduction
  Entry entry(4, 5.4f);
  cout << entry.m_key << " " << entry.m_value << '\n';
}