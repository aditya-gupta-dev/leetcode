#include <iostream>
#include <vector>

class Solution {
    public:
        static int sumDigits(int n) {
            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n = n / 10;
            }
            return sum;
        }

        bool isHappy(int n) {
            std::vector<int> set;
            while (n != 1) {
                 n = Solution::sumDigits(n);
                 if (n == 1) {
                     return true;
                 }
                 for (const auto item: set) {
                     if (item == n) {
                         return false;
                     }
                 }
                 set.push_back(n);
            }

            return true;
        }
};

int main() {
    Solution sol;
    std::cout << sol.isHappy(19);
    std::cout << sol.isHappy(2);
}
