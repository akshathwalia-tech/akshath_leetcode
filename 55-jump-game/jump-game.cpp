#include <vector>
#include <algorithm>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // If the current index is beyond the farthest reachable point, stop
            if (i > maxReach) {
                return false;
            }

            // Update the farthest index we can jump to
            maxReach = std::max(maxReach, i + nums[i]);

            // Early exit if the last index is already reachable
            if (maxReach >= n - 1) {
                return true;
            }
        }

        return true;
    }
};