#include <iostream>

class Solution {
public:
    int reverse(int x) {
        if (x < 0) {
            int reverse = 0;
            int abs = -x;
            while (abs > 0) {
                int digit = abs % 10;
                reverse = reverse * 10 + digit;
                abs = abs / 10;
            }
            return -reverse;
        } else {
            int reverse = 0;
            while (x > 0) {
                int digit = x % 10;
                reverse = reverse * 10 + digit;
                x = x / 10;
            }
            return reverse;
        }
    }
};

int main(void) {
    Solution *sol = new Solution();
    std::cout << sol->reverse(123);
    std::cout << sol->reverse(-123);
}
