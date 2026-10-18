#include <bits/stdc++.h>
#include <cassert>

using namespace std;

class Solution {
public:
    int searchInsert(const vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target ==  nums[mid]) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low;
    }
};


int main() {
    Solution sol;

    assert(sol.searchInsert({1,3,5,6}, 5) == 2);
    assert(sol.searchInsert({1,3,5,6}, 2) == 1);
    assert(sol.searchInsert({1,3,5,6}, 7) == 4);
}
