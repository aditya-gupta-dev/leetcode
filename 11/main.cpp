#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int area = 0;
    int start = 0;
    int end = height.size() - 1;

    while (start < end) {
      int sub = min(height[start], height[end]);
      int new_area = (end - start) * sub;
      area = max(area, new_area);

      if (height[start] < height[end]) {
        start++;
      } else {
        end--;
      }
    }

    return area;
  }
};

int main() {

  vector<int> c = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  Solution sol;
  cout << sol.maxArea(c) << "\n";
}
