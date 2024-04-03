#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n <= 0)
      return false;
    return (n & (n - 1)) == 0;
  }
};

int main() {
  Solution solution;
  int n = 16;
  cout << solution.isPowerOfTwo(n) << endl;
  return 0;
}