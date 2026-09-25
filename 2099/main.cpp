#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> maxSubsequence(const vector<int> &nums, int k) {
    int n = nums.size();
    std::vector<std::pair<int, int>> valIndex(n);
    for (int i = 0; i < n; ++i) {
      valIndex[i] = {nums[i], i};
    }

    std::nth_element(
        valIndex.begin(), valIndex.begin() + k, valIndex.end(),
        [](const auto &a, const auto &b) { return a.first > b.first; });

    std::sort(valIndex.begin(), valIndex.begin() + k,
              [](const auto &a, const auto &b) { return a.second < b.second; });

    std::vector<int> result(k);
    for (int i = 0; i < k; ++i) {
      result[i] = valIndex[i].first;
    }

    return result;
  }
};
int main(void) {
  int k = 2;
  Solution sol;
  vector<int> nums = {2, 1, 3, 3};

  for (const auto &item : sol.maxSubsequence(nums, k)) {
    cout << item << " ";
  }

  cout << endl;
}
