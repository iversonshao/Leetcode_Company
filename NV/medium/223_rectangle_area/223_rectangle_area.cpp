#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;


class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int ax = ax2 - ax1;
        int ay = ay2 - ay1;
        int ra = ax * ay;
        int bx = bx2 - bx1;
        int by = by2 - by1;
        int rb = bx * by;


        int left = max(ax1, bx1); //0
        int bottom = max(ay1, by1);//0
        int right = min(ax2, bx2);//3
        int top = min(ay2, by2);//2

        int overlap = 0;
        if (right > left && top > bottom){
            overlap = (right - left) * (top - bottom);
        }

        int total = ra + rb - overlap;
        return total;
    }
};

int main() {
    Solution sol;
    cout << sol.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    return 0;
}