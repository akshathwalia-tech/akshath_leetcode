#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxProductDifference(std::vector<int>& nums) {
        int max1 = 0, max2 = 0;
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int x : nums) {
            // Track two maximums
            if (x > max1) {
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max2 = x;
            }

            // Track two minimums
            if (x < min1) {
                min2 = min1;
                min1 = x;
            } else if (x < min2) {
                min2 = x;
            }
        }

        return (max1 * max2) - (min1 * min2);
    }
};