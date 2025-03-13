#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int gcd(int a, int b) {
    while (!b) {
      int temp = b;
      b = a % b;
      a = temp;
    }
    return a;
  }

  int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

  string fractionAddition(string expression) {}
};