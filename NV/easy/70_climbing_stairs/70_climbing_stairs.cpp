#include <iostream>
using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n == 0) {
      return 0;
    } else if (n == 1) {
      return 1;
    } else if (n == 2) {
      return 2;
    } else {
      int prev = 1;
      int current = 2;
      for (int i = 2; i < n; i++) {
        int next = prev + current;
        prev = current;
        current = next;
      }
      return current;
    }
  }
};

int main() {
  Solution s;
  cout << s.climbStairs(2) << endl;
  cout << s.climbStairs(3) << endl;
  cout << s.climbStairs(4) << endl;
  cout << s.climbStairs(5) << endl;
  cout << s.climbStairs(6) << endl;
  cout << s.climbStairs(7) << endl;
  cout << s.climbStairs(8) << endl;
  cout << s.climbStairs(9) << endl;
  cout << s.climbStairs(10) << endl;
  return 0;
}