#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int i = num1.size() - 1, j = num2.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0) {
            int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            result.push_back((sum % 10) + '0');
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    string num1 = "123";
    string num2 = "456";
    string sum = sol.addStrings(num1, num2);
    cout << sum << endl;  // Output: "579"
    return 0;
}
