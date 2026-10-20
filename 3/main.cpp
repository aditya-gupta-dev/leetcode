#include <bits/stdc++.h>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(const string &s) {
        std::vector<int> last_seen(128, -1);
        int left = 0, max_len = 0;

        for (int right = 0; right < s.length(); ++right) {
            unsigned char c = s[right];
            if (last_seen[c] >= left) {
                left = last_seen[c] + 1;
            }
            last_seen[c] = right;
            max_len = std::max(max_len, right - left + 1);
        }
        return max_len;
    }
};

int main(void) {
    Solution sol;
    sol.lengthOfLongestSubstring("abcabcbb");

}
