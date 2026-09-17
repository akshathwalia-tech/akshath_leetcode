#include <vector>

class Solution {
public:
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
        std::vector<int> ans(2 * n);
        for (int i = 0; i < n; i++) {
            ans[2 * i] = nums[i];       // Place x_i at even indices
            ans[2 * i + 1] = nums[n + i]; // Place y_i at odd indices
        }
        return ans;
    }
};