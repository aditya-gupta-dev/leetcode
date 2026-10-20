#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int sumOfSquares(const vector<int>& nums) {
        long sum = 0;
        for (int i{1}; i <= nums.size(); i++) {
            if(nums.size() % i == 0) {
                sum += nums[i - 1] * nums[i - 1];
            }
        }
        return sum;
    }
};

int main() {
    Solution sol;
    cout << sol.sumOfSquares({1,2,3,4}) << endl;
}
